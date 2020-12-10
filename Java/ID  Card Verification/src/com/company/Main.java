package com.company;
/*身份证验证*/
import java.io.Console;
import java.util.Scanner;
/**
 * @Author Bigbug
 * @Email ibigbugcc@gmail.com
 * @Version 1.0
 * @Date 2020-12-10 21:45
 * @Package com.company
 */
public class Main {
    public static void main(String[] args) {
        //存放身份证字符串数组
        char[] id = new char[50];

        //身份证系数
        int[] coefficient = new int[]{7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

        char[] correspond = new char[]{'1','0','x','9','8','7','6','5','4','3','2'};

        Scanner sc=new Scanner(System.in);
        System.out.println("请输入18位身份证号码：");

        String strId ="";

        if (sc.hasNext()){
            id = sc.next().toCharArray();
        }
        sc.close();
        if(id.length>18){
            System.out.println("输入的位数不能超过18位！");
            return;
        }

        int len=0;
        while (len<id.length) {
            strId +=id[len];
            len++;
        }
        //532923199901040051
        try {
            int num = 0;
            for(int i = 0;i<coefficient.length;i++){
                int num1 = Integer.parseInt(String.valueOf(id[i]));
                num += num1*coefficient[i];
            }
            //计算系数
            int x = num % 11;

            String strid =  "";
            for (int i = 0;0<correspond.length;i++){
                if(i==x){

                    strid = String.valueOf(correspond[i]);
                    String idLast = String.valueOf(id[17]).toLowerCase();

                    if(idLast.equals(strid)){
                        System.out.println("该身份证正确！");
                        System.out.println("出生日期为:"+strId.substring(6,14));

                    }else{
                        System.out.println("该身份证不合法！");
                    }
                    break;
                }
            }
        }catch (Exception ex){
            System.out.println(ex.toString());
        }
    }
}
