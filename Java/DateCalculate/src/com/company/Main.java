package com.company;

import java.io.IOException;
import java.time.Year;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class Main {
    public int totalDay;
    public int Years;
    public int oldYears;
    public int Month;
    public int oldMonth;
    public int Day ;

    private Main(){
        //初始化时间参数
        InitData();
    }

    //初始化数据
    private void InitData() {
        Calendar cal = Calendar.getInstance();
        totalDay = 0;
        Years = cal.get(Calendar.YEAR);
        Month = cal.get(Calendar.MONTH) +1;
        Day = cal.get(Calendar.DATE);

        Years = 2019;
        Month = 3;
        Day = 31;

        oldMonth = Month;
        oldYears = Years;
    }

    //月转天数
    private int MonthToDay(int Month,int Years){
        if(Month>12){
            Month=1;
        }else if(Month<=0){
            Month = 12;
        }
        int Days = 0;
        switch (Month){
                //31天
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                Days = 31;
                break;

            //2月
            case 2:
                if(Years%4==0&&Years%100!=0||Years%400==0){
                    Days = 29;
                }else {
                    Days = 28;
                }
                break;

                //30天
            case 4:
            case 6:
            case 9:
            case 11:
                Days = 30;
                break;
        }
        return Days;
    }

    //年份转天数
    private int YearsToDay(int Years){
        if(Years%4==0&&Years%100!=0||Years%400==0){
            return 366;
        }
        return 365;
    }

    //菜单
    private int Menu(){
        Scanner sca = new Scanner(System.in);
        System.out.println("======《菜单》=====");
        System.out.println("1.计算N天<后>的日期;");
        System.out.println("2.计算N天<前>的日期");
        System.out.println("3.Exit");
        System.out.println("请选择要操作的项目(序号):");
        int num = 0;
        if (sca.hasNext()){
            num = sca.nextInt();
        }

        switch (num){
            case 1:return 1;
            case 2:return 2;
            case 3:return 3;
            default: return 0;
        }
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        Main main = new Main();
        while (true){
            int select = main.Menu();

            switch (select){
                case 1:
                    String num = "";
                    main.InitData();
                    Scanner sca = new Scanner(System.in);

                    System.out.println("请输入要计算的天数(数字):");
                    if (sca.hasNext()){
                        num = sca.nextLine();
                        if(num.equals("0")||num.isEmpty()){return;}
                    }

                    try{
                        int Fday =  Integer.parseInt(num);
                        main.totalDay = Fday;

                        while(Fday>0){
                            //从年份开始逐一推导
                            if(Fday> main.YearsToDay(main.Years+1)){
                                Fday = Fday - main.YearsToDay(main.Years+1);
                                main.Years++;
                                //月份推导
                            }else if(Fday>main.MonthToDay(main.Month+1, main.Years)&&Fday>main.MonthToDay(main.Month, main.Years)){
                                //当月份超过12自动向前进位
                                if(main.Month+1>12){
                                    main.Years++;
                                    main.Month=1;
                                    Fday = Fday - main.MonthToDay(main.Month, main.Years);
                                }else {
                                    Fday = Fday - main.MonthToDay(main.Month+1, main.Years);
                                    main.Month++;
                                }
                                //计算天数
                            }else {
                                //不足一个月的天数相加后是否跨月
                                if(main.Day+Fday>main.MonthToDay(main.oldMonth, main.oldYears)){
                                    main.Day =main.Day+Fday- main.MonthToDay(main.oldMonth, main.oldYears);
                                    main.Month++;
                                    if(main.Month>12){
                                        main.Years++;
                                        main.Month = 1;
                                        main.Day = 1;
                                    }

                                }else {
                                    main.Day += Fday;
                                }
                                break;
                            }
                        }
                    }catch(Exception ex){
                        System.out.println("请勿输入非法字符！"+ex.getMessage());
                        break;
                    }
                    System.out.println(main.totalDay+"天后的日期: "+main.Years+"年"+main.Month+"月"+main.Day+"日");

                    Thread.sleep(2000);
                    break;

                case 2:
                    int nums = 0;
                    main.InitData();
                    Scanner sca2 = new Scanner(System.in);

                    try{
                        System.out.println("请输入要计算的天数(数字):");
                        if (sca2.hasNext()){
                            nums = sca2.nextInt();
                        }
                        int Fday =  nums;

                        main.totalDay = Fday;

                        while(Fday>0){

                            //从年份开始逐一推导
                            if(Fday> main.YearsToDay(main.Years-1)){
                                Fday = Fday - main.YearsToDay(main.Years-1);
                                main.Years--;
                                //月份推导
                            }else if(Fday>main.MonthToDay(main.Month-1, main.Years)&&Fday> main.Day){
                                //当月份超过12自动向前进位
                                if(main.Month-1<=0){
                                    main.Years--;
                                    main.Month=12;
                                    Fday = Fday - main.MonthToDay(main.Month, main.Years);
                                }else {
                                    Fday = Fday - main.MonthToDay(main.Month-1, main.Years);
                                    main.Month--;
                                }
                                //计算天数
                            }else {
                                //不足一个月的天数相加后是否跨月
                                if(main.Day-Fday<=0){
                                    if(main.Month-1<=0){
                                        main.Month=12;
                                        main.Years--;
                                        main.Day = main.MonthToDay(main.Month, main.Years)+ main.Day-Fday;
                                    }else {
                                        main.Month--;
                                        main.Day = main.MonthToDay(main.Month, main.Years)+ main.Day-Fday;
                                    }
                                }else {
                                    main.Day -= Fday;
                                }
                                break;
                            }
                        }
                    }catch(Exception ex){
                        System.out.println("请勿输入非法字符！"+ex.getMessage());
                        break;
                    }
                    System.out.println(main.totalDay+"天前的日期: "+main.Years+"年"+main.Month+"月"+main.Day+"日");

                    Thread.sleep(2000);
                    break;
                case 3:return;
            }
        }
    }
}
