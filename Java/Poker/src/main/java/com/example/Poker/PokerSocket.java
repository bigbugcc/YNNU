package com.example.Poker;

import com.example.Poker.entity.Message;
import com.google.gson.Gson;

import javax.websocket.OnMessage;
import javax.websocket.OnOpen;
import javax.websocket.Session;
import javax.websocket.server.ServerEndpoint;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

@ServerEndpoint("/PokerSocket")
public class PokerSocket {
    public static Map<String, Session> sessionMap = new HashMap<String, Session>();
    private Session session;
    @OnOpen
    public void startSocket(Session session) {
        this.session = session;
        System.out.println("链接成功");
        if (sessionMap.size() == 0) {
            return ;
        }
        Set userIds = sessionMap.keySet();
        StringBuffer sBuffer  = new StringBuffer();
        for (Object str : userIds) {
            sBuffer.append(str.toString() + ":");
        }
        Gson gson = new Gson();
        try {
            Message message = new Message();
            message.setFrom("系统");
            message.setMsg(sBuffer.toString());
            session.getBasicRemote().sendText(gson.toJson(message),true);
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    @OnMessage
    public void getMessgae(Session session, String str, boolean last) {
        if (session.isOpen()) {
            try {
                System.out.println(str);
                Gson gson = new Gson();
                Message msg = gson.fromJson(str, Message.class);
                Message toMessage = msg;
                toMessage.setFrom(msg.getId());
                toMessage.setTo(msg.getTo());

                if (msg.getMsg().equals("newUser")) {
                    if (sessionMap.containsKey(msg.getId())) {
                        sessionMap.remove(msg.getId());
                    }
                    sessionMap.put(msg.getId(), session);
                } else {
                    Session toSession = sessionMap.get(msg.getTo());
                    if (toSession != null && toSession.isOpen()) {
                        toSession.getBasicRemote().sendText(gson.toJson(toMessage).toString(), last);
                    } else {
                        toMessage.setMsg("用户不存在");
                        toMessage.setFrom("系统");
                        session.getBasicRemote().sendText(gson.toJson(toMessage).toString(), last);
                    }
                }
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }

        } else {
            System.out.println("session is closed");
        }
    }


}
