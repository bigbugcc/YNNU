//---------------------------------------------------------------------------

#include <vcl.h>
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
HANDLE a;
HANDLE b;
HANDLE c;

int data;
const int TotalCount=24;
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 b=CreateSemaphore(NULL,1,1,NULL);//windows提供的创建信号量的API函数；
 a=CreateSemaphore(NULL,0,1,NULL);//第二个参数表示信号量value属性的初始值；
 c=CreateSemaphore(NULL,0,1,NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
 CloseHandle(b);//关闭句柄对应的资源；
 CloseHandle(a);//关闭句柄对应的资源；
 CloseHandle(c);
}
//---------------------------------------------------------------------------

DWORD CALLBACK ThreadFunctionRead(void *p)
{
 Form1->ListBox1->Items->Clear();
 String S;
 for(int j=0;j<=TotalCount;j++)
 {
  if(Form1->CheckBox1->Checked)WaitForSingleObject(c,INFINITE);//同步操作，相当于P原语；
  Sleep(1);
  data--;//data=data-1;
  S.sprintf(L"Information: %d",data);
  SendMessage(Form1->ListBox1->Handle,LB_ADDSTRING,0,(long)S.c_str());
  if(Form1->CheckBox1->Checked)ReleaseSemaphore(a,1,NULL);//同步操作，相当于V原语；
 };
 return(0);
}

DWORD CALLBACK ThreadFunctionWrite(void *p)
{
 Form1->ListBox2->Items->Clear();
 String S;
 for(int j=0;j<=TotalCount;j++)
 {
  if(Form1->CheckBox1->Checked)WaitForSingleObject(a,INFINITE);//同步操作，相当于P原语；
  Sleep(1);
  data--;//data=data+1;
  S.sprintf(L"Information: %d",data);
  SendMessage(Form1->ListBox2->Handle,LB_ADDSTRING,0,(long)S.c_str());
  if(Form1->CheckBox1->Checked)ReleaseSemaphore(b,1,NULL);//释放信号量对应的资源，释放1个；相当于V原语；
 };
 return(0);
}



DWORD CALLBACK ThreadFunctionRead1(void *p)
{
 Form1->ListBox3->Items->Clear();
 String S;
 for(int j=0;j<=TotalCount;j++)
 {
  if(Form1->CheckBox1->Checked)WaitForSingleObject(b,INFINITE);//同步操作，相当于P原语；
  Sleep(1);
  data+=2;//data=data-1;
  S.sprintf(L"Information: %d",data);
  SendMessage(Form1->ListBox3->Handle,LB_ADDSTRING,0,(long)S.c_str());
  if(Form1->CheckBox1->Checked)ReleaseSemaphore(c,1,NULL);//同步操作，相当于V原语；
 };
 return(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
 DWORD ThreadID1;
 DWORD ThreadID2;
 DWORD ThreadID3;
 HANDLE ThreadHandle1;
 HANDLE ThreadHandle2;
 HANDLE ThreadHandle3;
 data=100;
 ThreadHandle1=CreateThread(0,0,ThreadFunctionRead,0,0,&ThreadID1);
 ThreadHandle2=CreateThread(0,0,ThreadFunctionWrite,0,0,&ThreadID2);
 ThreadHandle3=CreateThread(0,0,ThreadFunctionRead1,0,0,&ThreadID3);
}
//---------------------------------------------------------------------------

