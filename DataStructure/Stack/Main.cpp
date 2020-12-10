#include<iostream>  
#include<stdio.h>  
#include<stdlib.h>  
#include<string>  
#include<math.h>  
#define STACK_INIT_SIZE 100  
using namespace std;

//运算符结构体
typedef struct
{
    char date[STACK_INIT_SIZE];
    int top;
}OptrStack;    

//操作数结构体    
typedef struct
{
    double date[STACK_INIT_SIZE];
    int top;
}OpndStack;     

//操作符相关操作  
OptrStack* Init_OptrStack();    //置栈空  
int Empty_OptrStack(OptrStack* s);//判空栈  
int Push_OptrStack(OptrStack* s, char x);//入栈(注意：判断栈是否已满)  
char Pop_OptrStack(OptrStack* s, char x);//出栈(注意：判断栈是否已空)  
char GetTop_OptrStack(OptrStack* s, char x);//取栈顶元素，先判空  

//操作数相关操作  
OpndStack* Init_OpndStack();//置栈空  
int Empty_OpndStack(OpndStack* t);//判空栈  
int  Push_OpndStack(OpndStack* t, double y);//入栈(注意：判断栈是否已满)  
double Pop_OpndStack(OpndStack* t, double y);//出栈(注意：判断栈是否已空)  
double GetTop_OpndStack(OpndStack* t, double y);//取栈顶元素  

//表达式求值函数  
void Error(char* s);                  //错误处理函数  
int Judge_optr(char ch);              //用于判断字符ch是否是运算符  
int Operate(int a, int b, char top);  //用于计算当前的值，并将该值返回  
void Jsbds_operate(char str[]);        //读入一个简单算术表达式的值  

//操作符函数实现部分  
OptrStack* Init_OptrStack()
{
    OptrStack* s;
    s = (OptrStack*)malloc(sizeof(OptrStack));
    s->top = -1;
    return s;
}
int Empty_OptrStack(OptrStack* s)//判空栈  
{
    if (s->top != -1)
        return 1;
    else
        return 0;
}
int  Push_OptrStack(OptrStack* s, char x)//入栈(注意：判断栈是否已满)  
{
    if (s->top == (STACK_INIT_SIZE - 1))
    {
        return 0;
    }
    else
        s->date[++s->top] = x;
    return 1;

}
char Pop_OptrStack(OptrStack* s, char x)//出栈(注意：判断栈是否已空)  
{
    if (!Empty_OptrStack(s))
    {
        return 0;
    }
    else
        x = s->date[s->top];
    s->top--;
    return x;
}
char GetTop_OptrStack(OptrStack* s, char x)//取栈顶元素，先判空  
{
    if (!Empty_OptrStack(s))
    {
        return 0;
    }
    else
        x = s->date[s->top];
    return x;
}
//操作数函数实现部分  
OpndStack* Init_OpndStack()//置栈空  
{
    OpndStack* t;
    t = (OpndStack*)malloc(sizeof(OpndStack));
    t->top = -1;
    return t;
}
int Empty_OpndStack(OpndStack* t)//判空栈  
{
    if (t->top != -1)
        return 1;
    else
        return 0;
}
int  Push_OpndStack(OpndStack* t, double y)//入栈(注意：判断栈是否已满)  
{
    if (t->top == (STACK_INIT_SIZE - 1))
    {
        return 0;
    }
    else
        t->date[++t->top] = y;
    return 1;
}
double Pop_OpndStack(OpndStack* t, double y)//出栈(注意：判断栈是否已空)  
{
    if (!Empty_OpndStack(t))
    {
        return 0;
    }
    else
        y = t->date[t->top];
    t->top--;
    return y;
}
double GetTop_OpndStack(OpndStack* t, double y)//取栈顶元素  
{
    if (!Empty_OpndStack(t))
    {
        return 0;
    }
    y = t->date[t->top];
    return y;
}

//表达式求值函数实现  
void Error(char* s)   //错误处理函数  
{
    std::cout << s << endl;
    exit(1);
}


int Judge_optr(char top)//用于判断字符ch是否是运算符
{
    int x;
    //cout << top << "test" << endl;
    switch (top)
    {
    case '(':
        x = 0; break;
    case '+':
    case '-':
        x = 1; break;
    case '*':
    case '/':
        x = 2; break;
    case ')':
        x = 3; break;
    }
    return x;
}

double Operate(double b, double a, char top)  //用于计算当前的值，并将该值返回
{
    double c = 0;
    switch (top)
    {
    case '+':
        c = b + a;
        break;
    case '-':
        c = b - a;
        break;
    case '*':
        c = b * a;
        break;
    case '/':
        if (a == 0)
        {
            printf("分母为零!\n");
            return 0;
        }
        else
            c = b / a;
        break;
    default:
        printf("输入的字符非法!\n");
        break;
    }
    return c;
}

void Jsbds_operate(char str[])             //读入一个简单算术表达式,并将计算结果返回到主函数
{
    OptrStack* optr = Init_OptrStack();     //初始化操作符栈  
    OpndStack* opnd = Init_OpndStack();     //初始化操作数栈  
    int i, j;                               //i,j为循环变量，a,b接收从操作数栈中出栈的元素  
    double f;                               //接收将字符数转换为浮点数的值  
    double a = 0;
    double b = 0;
    double c = 0;
    char d[100];                           //储存字符串中连续的‘数’  
    char top = 0;                          //接收从操作符栈中出栈的元素 
    for (i = 0; str[i]; i++)               //将字符串中的元素按顺序入到栈中
    {
        switch (str[i])
        {
        case '(':
        case '+':
        case '-':
            /*先判断当前运算符与操作符栈栈顶元素的优先级，如果高于栈顶元素，则入栈；
            小于栈顶元素，则从操作数栈中依次出两个数，并将操作符栈中栈顶元素出栈，
            再将从操作数栈中出的两个数，按从操作符栈栈中出的运算符运算，
            并将结果压入操作数栈中，再将当前的操作符压入操作符栈中。*/
            if ((!Empty_OptrStack(optr)) || (Judge_optr(str[i]) > Judge_optr(GetTop_OptrStack(optr, top))) || (str[i] == '('))  //当操作符栈为空的时候压栈保存
            {
                Push_OptrStack(optr, str[i]);
            }
            else
            {
                a = Pop_OpndStack(opnd, a); //接收从操作数栈中出栈的元素  
                b = Pop_OpndStack(opnd, b); //接收从操作数栈中出栈的元素  
                top = Pop_OptrStack(optr, top);//接收从操作符栈中出栈的元素  
                c = Operate(b, a, top);
                Push_OpndStack(opnd, c);
                //将计算后的值压入操作数栈中  
                Push_OptrStack(optr, str[i]);
            }
            break;
        case '*':
        case '/':
            if ((!Empty_OptrStack(optr)) || (Judge_optr(str[i]) > Judge_optr(GetTop_OptrStack(optr, top))) || (str[i] == '('))
            { //当操作符栈为空或者该操作符的优先级大于栈顶元素的优先级是入栈保存
                Push_OptrStack(optr, str[i]);
            }
            else
            {
                a = Pop_OpndStack(opnd, a);//接收从操作数栈中出栈的元素  
                b = Pop_OpndStack(opnd, b);//接收从操作数栈中出栈的元素  
                top = Pop_OptrStack(optr, top);//接收从操作符栈中出栈的元素 
                c = Operate(b, a, top);
                Push_OpndStack(opnd, c);
                //将计算后的值压入操作数栈中  
                Push_OptrStack(optr, str[i]);
            }
            break;
        case ')':
            Push_OptrStack(optr, str[i]);
            break;
        case '\0':
            break;
        default:
            j = 0;
            do
            {
                d[j++] = str[i];
                i++;
            } while (str[i] >= '0' && str[i] <= '9');  //可存入一个或多个数字字符  
            d[j] = '\0';                  //将输入的连续多个数字字符拼成了字符串  
            i--;
            f = atof(d);                //调用库函数atoi()将字符数转换为浮点数  
            Push_OpndStack(opnd, f);    //将转换后的数压入操作数栈中  
            break;
        }
    }
    while (Empty_OptrStack(optr))  //当操作符栈不为空的时候执行
    {
        if ((GetTop_OptrStack(optr, top) == ')') || (GetTop_OptrStack(optr, top) == '('))
        {
            top = Pop_OptrStack(optr, top);
        }
        else
        {
            a = Pop_OpndStack(opnd, a);//接收从操作数栈中出栈的元素 
            b = Pop_OpndStack(opnd, b);//接收从操作数栈中出栈的元素  
            top = Pop_OptrStack(optr, top);//接收从操作符栈中出栈的元素  
            c = Operate(b, a, top);
            Push_OpndStack(opnd, c);
            //将计算后的值压入操作数栈中  
        }
    }
    cout << "该表达式的计算结果为：";
    std::cout << GetTop_OpndStack(opnd, c) << endl;//将操作数栈中的元素(即表达式的最终结果)打印出来  
}

int main()
{
    char str[100];
    std::cout << "请输入算术表达式(功能：+，-，*，/)" << endl;
    cin >> str;
    Jsbds_operate(str);
    return 0;
}