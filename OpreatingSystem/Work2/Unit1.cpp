//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <stdlib.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//定义需要的全局变量和常量；
TRTLCriticalSection Sec1;//定义一个windows的临界区对象；
int data;                //定义一个公共变量用来作为公共资源；
const int TotalCount=24; //定义循环次数用的常量；
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 InitializeCriticalSection(&Sec1);//用来初始化临界区对象的windows API函数；参数是对象的地址；
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
 DeleteCriticalSection(&Sec1);//用来删除（回收资源）临界区对象的windows API函数；参数是对象的地址；
}
//---------------------------------------------------------------------------
DWORD CALLBACK ThreadFunction1(void *p)
{
 Form1->ListBox1->Items->Clear();//把Form1上的ListBox1的空间清空；
 int i;
 String S;//定义字符串对象S用来输出文本到ListBox1当中；
 for(int j=0;j<=TotalCount;j++)
 {
  if(Form1->CheckBox1->Checked)EnterCriticalSection(&Sec1);//entry section；进入制定临界区对象标识的临界区；
  Sleep(3);//临界区开始；让线程休眠3个毫秒；
  data+=3;//data=data+3；
  i=data-3;

  S.sprintf(L"Information: %d",i);//把i的值转换为字符串赋值给S；
  SendMessage(Form1->ListBox1->Handle,LB_ADDSTRING,0,(long)S.c_str());//把S的内容添加到ListBox1当中去；
  data-=3;//临界区结束；data=data-3；
  if(Form1->CheckBox1->Checked)LeaveCriticalSection(&Sec1);//exit section；离开制定临界区对象标识的临界区；
 };
 return(0);
}

DWORD CALLBACK ThreadFunction2(void *p)
{
 Form1->ListBox2->Items->Clear();//把Form1上的ListBox1的空间清空；
 int i;
 String S;//定义字符串对象S用来输出文本到ListBox2当中；
 for(int j=0;j<=TotalCount;j++)
 {
  if(Form1->CheckBox1->Checked)EnterCriticalSection(&Sec1);//entry section；进入制定临界区对象标识的临界区；
  Sleep(3);//临界区开始；让线程休眠3个毫秒；
  data-=3;//data=data-3；
  i=data+3;
  S.sprintf(L"Information: %d",i);//把i的值转换为字符串赋值给S；
  SendMessage(Form1->ListBox2->Handle,LB_ADDSTRING,0,(long)S.c_str());//把S的内容添加到ListBox2当中去；
  data+=3;
  if(Form1->CheckBox1->Checked)LeaveCriticalSection(&Sec1);//exit section；离开制定临界区对象标识的临界区；
 };
 return(0);
}

DWORD CALLBACK ThreadFunction3(void *p)
{
 Form1->ListBox3->Items->Clear();//把Form1上的ListBox1的空间清空；
 int i;
 String S;//定义字符串对象S用来输出文本到ListBox2当中；
 for(int j=0;j<=TotalCount;j++)
 {
  if(Form1->CheckBox1->Checked)EnterCriticalSection(&Sec1);//entry section；进入制定临界区对象标识的临界区；
  Sleep(3);//临界区开始；让线程休眠3个毫秒；
  data-=5;//data=data-3；
  i=data+5;
  S.sprintf(L"Information: %d",i);//把i的值转换为字符串赋值给S；

  SendMessage(Form1->ListBox3->Handle,LB_ADDSTRING,0,(long)S.c_str());//把S的内容添加到ListBox2当中去；
  data+=5;
  if(Form1->CheckBox1->Checked)LeaveCriticalSection(&Sec1);//exit section；离开制定临界区对象标识的临界区；
 };
 return(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 DWORD ThreadID1;
 DWORD ThreadID2;
 DWORD ThreadID3;
 HANDLE ThreadHandle1;
 HANDLE ThreadHandle2;
 HANDLE ThreadHandle3;
 data=100;//给公共变量赋初始值；
 ThreadHandle1=CreateThread(0,0,ThreadFunction1,0,0,&ThreadID1);//创建两个线程进行并发；
 ThreadHandle2=CreateThread(0,0,ThreadFunction2,0,0,&ThreadID2);//创建两个线程进行并发；
 ThreadHandle3=CreateThread(0,0,ThreadFunction3,0,0,&ThreadID3);//创建两个线程进行并发；
 //线程创建是有先后顺序的；
}
