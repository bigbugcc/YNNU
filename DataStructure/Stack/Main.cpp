#include<iostream>  
#include<stdio.h>  
#include<stdlib.h>  
#include<string>  
#include<math.h>  
#define STACK_INIT_SIZE 100  
using namespace std;

//������ṹ��
typedef struct
{
    char date[STACK_INIT_SIZE];
    int top;
}OptrStack;    

//�������ṹ��    
typedef struct
{
    double date[STACK_INIT_SIZE];
    int top;
}OpndStack;     

//��������ز���  
OptrStack* Init_OptrStack();    //��ջ��  
int Empty_OptrStack(OptrStack* s);//�п�ջ  
int Push_OptrStack(OptrStack* s, char x);//��ջ(ע�⣺�ж�ջ�Ƿ�����)  
char Pop_OptrStack(OptrStack* s, char x);//��ջ(ע�⣺�ж�ջ�Ƿ��ѿ�)  
char GetTop_OptrStack(OptrStack* s, char x);//ȡջ��Ԫ�أ����п�  

//��������ز���  
OpndStack* Init_OpndStack();//��ջ��  
int Empty_OpndStack(OpndStack* t);//�п�ջ  
int  Push_OpndStack(OpndStack* t, double y);//��ջ(ע�⣺�ж�ջ�Ƿ�����)  
double Pop_OpndStack(OpndStack* t, double y);//��ջ(ע�⣺�ж�ջ�Ƿ��ѿ�)  
double GetTop_OpndStack(OpndStack* t, double y);//ȡջ��Ԫ��  

//���ʽ��ֵ����  
void Error(char* s);                  //��������  
int Judge_optr(char ch);              //�����ж��ַ�ch�Ƿ��������  
int Operate(int a, int b, char top);  //���ڼ��㵱ǰ��ֵ��������ֵ����  
void Jsbds_operate(char str[]);        //����һ�����������ʽ��ֵ  

//����������ʵ�ֲ���  
OptrStack* Init_OptrStack()
{
    OptrStack* s;
    s = (OptrStack*)malloc(sizeof(OptrStack));
    s->top = -1;
    return s;
}
int Empty_OptrStack(OptrStack* s)//�п�ջ  
{
    if (s->top != -1)
        return 1;
    else
        return 0;
}
int  Push_OptrStack(OptrStack* s, char x)//��ջ(ע�⣺�ж�ջ�Ƿ�����)  
{
    if (s->top == (STACK_INIT_SIZE - 1))
    {
        return 0;
    }
    else
        s->date[++s->top] = x;
    return 1;

}
char Pop_OptrStack(OptrStack* s, char x)//��ջ(ע�⣺�ж�ջ�Ƿ��ѿ�)  
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
char GetTop_OptrStack(OptrStack* s, char x)//ȡջ��Ԫ�أ����п�  
{
    if (!Empty_OptrStack(s))
    {
        return 0;
    }
    else
        x = s->date[s->top];
    return x;
}
//����������ʵ�ֲ���  
OpndStack* Init_OpndStack()//��ջ��  
{
    OpndStack* t;
    t = (OpndStack*)malloc(sizeof(OpndStack));
    t->top = -1;
    return t;
}
int Empty_OpndStack(OpndStack* t)//�п�ջ  
{
    if (t->top != -1)
        return 1;
    else
        return 0;
}
int  Push_OpndStack(OpndStack* t, double y)//��ջ(ע�⣺�ж�ջ�Ƿ�����)  
{
    if (t->top == (STACK_INIT_SIZE - 1))
    {
        return 0;
    }
    else
        t->date[++t->top] = y;
    return 1;
}
double Pop_OpndStack(OpndStack* t, double y)//��ջ(ע�⣺�ж�ջ�Ƿ��ѿ�)  
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
double GetTop_OpndStack(OpndStack* t, double y)//ȡջ��Ԫ��  
{
    if (!Empty_OpndStack(t))
    {
        return 0;
    }
    y = t->date[t->top];
    return y;
}

//���ʽ��ֵ����ʵ��  
void Error(char* s)   //��������  
{
    std::cout << s << endl;
    exit(1);
}


int Judge_optr(char top)//�����ж��ַ�ch�Ƿ��������
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

double Operate(double b, double a, char top)  //���ڼ��㵱ǰ��ֵ��������ֵ����
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
            printf("��ĸΪ��!\n");
            return 0;
        }
        else
            c = b / a;
        break;
    default:
        printf("������ַ��Ƿ�!\n");
        break;
    }
    return c;
}

void Jsbds_operate(char str[])             //����һ�����������ʽ,�������������ص�������
{
    OptrStack* optr = Init_OptrStack();     //��ʼ��������ջ  
    OpndStack* opnd = Init_OpndStack();     //��ʼ��������ջ  
    int i, j;                               //i,jΪѭ��������a,b���մӲ�����ջ�г�ջ��Ԫ��  
    double f;                               //���ս��ַ���ת��Ϊ��������ֵ  
    double a = 0;
    double b = 0;
    double c = 0;
    char d[100];                           //�����ַ����������ġ�����  
    char top = 0;                          //���մӲ�����ջ�г�ջ��Ԫ�� 
    for (i = 0; str[i]; i++)               //���ַ����е�Ԫ�ذ�˳���뵽ջ��
    {
        switch (str[i])
        {
        case '(':
        case '+':
        case '-':
            /*���жϵ�ǰ������������ջջ��Ԫ�ص����ȼ����������ջ��Ԫ�أ�����ջ��
            С��ջ��Ԫ�أ���Ӳ�����ջ�����γ�������������������ջ��ջ��Ԫ�س�ջ��
            �ٽ��Ӳ�����ջ�г��������������Ӳ�����ջջ�г�����������㣬
            �������ѹ�������ջ�У��ٽ���ǰ�Ĳ�����ѹ�������ջ�С�*/
            if ((!Empty_OptrStack(optr)) || (Judge_optr(str[i]) > Judge_optr(GetTop_OptrStack(optr, top))) || (str[i] == '('))  //��������ջΪ�յ�ʱ��ѹջ����
            {
                Push_OptrStack(optr, str[i]);
            }
            else
            {
                a = Pop_OpndStack(opnd, a); //���մӲ�����ջ�г�ջ��Ԫ��  
                b = Pop_OpndStack(opnd, b); //���մӲ�����ջ�г�ջ��Ԫ��  
                top = Pop_OptrStack(optr, top);//���մӲ�����ջ�г�ջ��Ԫ��  
                c = Operate(b, a, top);
                Push_OpndStack(opnd, c);
                //��������ֵѹ�������ջ��  
                Push_OptrStack(optr, str[i]);
            }
            break;
        case '*':
        case '/':
            if ((!Empty_OptrStack(optr)) || (Judge_optr(str[i]) > Judge_optr(GetTop_OptrStack(optr, top))) || (str[i] == '('))
            { //��������ջΪ�ջ��߸ò����������ȼ�����ջ��Ԫ�ص����ȼ�����ջ����
                Push_OptrStack(optr, str[i]);
            }
            else
            {
                a = Pop_OpndStack(opnd, a);//���մӲ�����ջ�г�ջ��Ԫ��  
                b = Pop_OpndStack(opnd, b);//���մӲ�����ջ�г�ջ��Ԫ��  
                top = Pop_OptrStack(optr, top);//���մӲ�����ջ�г�ջ��Ԫ�� 
                c = Operate(b, a, top);
                Push_OpndStack(opnd, c);
                //��������ֵѹ�������ջ��  
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
            } while (str[i] >= '0' && str[i] <= '9');  //�ɴ���һ�����������ַ�  
            d[j] = '\0';                  //�������������������ַ�ƴ�����ַ���  
            i--;
            f = atof(d);                //���ÿ⺯��atoi()���ַ���ת��Ϊ������  
            Push_OpndStack(opnd, f);    //��ת�������ѹ�������ջ��  
            break;
        }
    }
    while (Empty_OptrStack(optr))  //��������ջ��Ϊ�յ�ʱ��ִ��
    {
        if ((GetTop_OptrStack(optr, top) == ')') || (GetTop_OptrStack(optr, top) == '('))
        {
            top = Pop_OptrStack(optr, top);
        }
        else
        {
            a = Pop_OpndStack(opnd, a);//���մӲ�����ջ�г�ջ��Ԫ�� 
            b = Pop_OpndStack(opnd, b);//���մӲ�����ջ�г�ջ��Ԫ��  
            top = Pop_OptrStack(optr, top);//���մӲ�����ջ�г�ջ��Ԫ��  
            c = Operate(b, a, top);
            Push_OpndStack(opnd, c);
            //��������ֵѹ�������ջ��  
        }
    }
    cout << "�ñ��ʽ�ļ�����Ϊ��";
    std::cout << GetTop_OpndStack(opnd, c) << endl;//��������ջ�е�Ԫ��(�����ʽ�����ս��)��ӡ����  
}

int main()
{
    char str[100];
    std::cout << "�������������ʽ(���ܣ�+��-��*��/)" << endl;
    cin >> str;
    Jsbds_operate(str);
    return 0;
}