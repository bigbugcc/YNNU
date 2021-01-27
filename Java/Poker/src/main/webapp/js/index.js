const app = new Vue({
    el: '#app',
    data: {
        cards: {
            self : {
                hand: [],
                show: [],
            },
            playerTop : {
                hand: [],
                show: [],
            },
            playerLeft : {
                hand: [],
                show: [],
            },
            playerRight : {
                hand: [],
                show: [],
            }
        }
    },
    // 在 `methods` 对象中定义方法
    methods: {
        getStyle(card) {
            return `background-position: ${-69 * card.col}px ${-105 * card.row}px;`;
        },
        reset() {
            const cards = [];

            // 生成52张牌
            for (let row = 0; row < 4; row++) {
                for(let col = 0; col < 13; col++) {
                    cards.push({ id: `c-${Utils.prefixZero(row, 2)}-${Utils.prefixZero(col, 2)}`,  row, col })
                }
            }
            
            for (let i = 0; i < 50; i++) {
                const a = Math.floor(Math.random() * cards.length);
                const b = Math.floor(Math.random() * cards.length);
                const t = cards[a];
                cards[a] = cards[b]; cards[b] = t;
            }

            this.cards.self.hand = cards.splice(0, 13).sort((a, b)=> (a.id < b.id) ? -1: 1);
            this.cards.playerTop.show = cards.splice(0, 13);
            this.cards.playerLeft.show = cards.splice(0, 13);
            this.cards.playerRight.show = cards.splice(0, 13);


        }
    }
})
/*
* 通过使用websocket进行通信
* */
    $(function() {

        $(document).on("dblclick",".selfCard",function (e){

            e.target.setAttribute("style","display:none");

            console.log(e);
        });


    var url = "ws://localhost:8080/Poker_war/PokerSocket";
    var ws = "";
    var message ={"id":"","msg":"","form":"","to":""};

    //连接服务器
    function connection() {
    ws = new WebSocket(url);
    console.log("connection.......");
    ws.onmessage = function (e){
    var json = eval('(' +  e.data.toString() + ')');
    showMessage(json.from +":"+ json.msg);
}
    ws.onclose = function() {
    showMessage("close");
}
    ws.onerror = function (e){
    showMessage("error");
}
    ws.onopen = function() {
    showMessage("链接成功")
    message.id = $(".identity").val();
    message.msg = "newUser";
    console.log(JSON.stringify(message));
    ws.send(JSON.stringify(message));
    message.msg = "";

}
}



//连接服务器
$(".start-conn-btn").click(function() {
    connection();
});
    //出牌
    $(".send-btn").click(function() {//send message
    message.to = $(".to-user").val();
    message.msg = $(".msg-context").val();
    $(".msg-context").val("");
    ws.send(JSON.stringify(message));
    showMessage( "我:" + message.msg );
    message.msg = "";

});
    function showMessage(msg) {
    $(".show-message").append( msg + "<br/>");
    }
});
