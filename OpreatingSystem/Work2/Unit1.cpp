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
//������Ҫ��ȫ�ֱ����ͳ�����
TRTLCriticalSection Sec1;//����һ��windows���ٽ�������
int data;                //����һ����������������Ϊ������Դ��
const int TotalCount=24; //����ѭ�������õĳ�����
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 InitializeCriticalSection(&Sec1);//������ʼ���ٽ��������windows API�����������Ƕ���ĵ�ַ��
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
 DeleteCriticalSection(&Sec1);//����ɾ����������Դ���ٽ��������windows API�����������Ƕ���ĵ�ַ��
}
//---------------------------------------------------------------------------
DWORD CALLBACK ThreadFunction1(void *p)
{
 Form1->ListBox1->Items->Clear();//��Form1�ϵ�ListBox1�Ŀռ���գ�
 int i;
 String S;//�����ַ�������S��������ı���ListBox1���У�
 for(int j=0;j<=TotalCount;j++)
 {
  if(Form1->CheckBox1->Checked)EnterCriticalSection(&Sec1);//entry section�������ƶ��ٽ��������ʶ���ٽ�����
  Sleep(3);//�ٽ�����ʼ�����߳�����3�����룻
  data+=3;//data=data+3��
  i=data-3;

  S.sprintf(L"Information: %d",i);//��i��ֵת��Ϊ�ַ�����ֵ��S��
  SendMessage(Form1->ListBox1->Handle,LB_ADDSTRING,0,(long)S.c_str());//��S��������ӵ�ListBox1����ȥ��
  data-=3;//�ٽ���������data=data-3��
  if(Form1->CheckBox1->Checked)LeaveCriticalSection(&Sec1);//exit section���뿪�ƶ��ٽ��������ʶ���ٽ�����
 };
 return(0);
}

DWORD CALLBACK ThreadFunction2(void *p)
{
 Form1->ListBox2->Items->Clear();//��Form1�ϵ�ListBox1�Ŀռ���գ�
 int i;
 String S;//�����ַ�������S��������ı���ListBox2���У�
 for(int j=0;j<=TotalCount;j++)
 {
  if(Form1->CheckBox1->Checked)EnterCriticalSection(&Sec1);//entry section�������ƶ��ٽ��������ʶ���ٽ�����
  Sleep(3);//�ٽ�����ʼ�����߳�����3�����룻
  data-=3;//data=data-3��
  i=data+3;
  S.sprintf(L"Information: %d",i);//��i��ֵת��Ϊ�ַ�����ֵ��S��
  SendMessage(Form1->ListBox2->Handle,LB_ADDSTRING,0,(long)S.c_str());//��S��������ӵ�ListBox2����ȥ��
  data+=3;
  if(Form1->CheckBox1->Checked)LeaveCriticalSection(&Sec1);//exit section���뿪�ƶ��ٽ��������ʶ���ٽ�����
 };
 return(0);
}

DWORD CALLBACK ThreadFunction3(void *p)
{
 Form1->ListBox3->Items->Clear();//��Form1�ϵ�ListBox1�Ŀռ���գ�
 int i;
 String S;//�����ַ�������S��������ı���ListBox2���У�
 for(int j=0;j<=TotalCount;j++)
 {
  if(Form1->CheckBox1->Checked)EnterCriticalSection(&Sec1);//entry section�������ƶ��ٽ��������ʶ���ٽ�����
  Sleep(3);//�ٽ�����ʼ�����߳�����3�����룻
  data-=5;//data=data-3��
  i=data+5;
  S.sprintf(L"Information: %d",i);//��i��ֵת��Ϊ�ַ�����ֵ��S��

  SendMessage(Form1->ListBox3->Handle,LB_ADDSTRING,0,(long)S.c_str());//��S��������ӵ�ListBox2����ȥ��
  data+=5;
  if(Form1->CheckBox1->Checked)LeaveCriticalSection(&Sec1);//exit section���뿪�ƶ��ٽ��������ʶ���ٽ�����
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
 data=100;//��������������ʼֵ��
 ThreadHandle1=CreateThread(0,0,ThreadFunction1,0,0,&ThreadID1);//���������߳̽��в�����
 ThreadHandle2=CreateThread(0,0,ThreadFunction2,0,0,&ThreadID2);//���������߳̽��в�����
 ThreadHandle3=CreateThread(0,0,ThreadFunction3,0,0,&ThreadID3);//���������߳̽��в�����
 //�̴߳��������Ⱥ�˳��ģ�
}
