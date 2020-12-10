//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Console.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
 if(((int(Key)<48)||(int(Key)>57))&&(int(Key)!=13)&&(int(Key)!=8))Key=Char(0);//屏蔽掉用户的一些非法输入，保证Edit1得到的是整形数字
}//只允许数字符号和回车、退格以及删除，ascII码
//---------------------------------------------------------------------------
void BubbleSort(int *ia,int Items,int c)//冒泡排序算法
{
 HDC DC=GetDC(Form2->Handle);
 int temp;//用来交换两个变量的值

 int count = 0;

 for(int i=Items;i>0;i--)
 {
  for(int j=0;j<i;j++)
   if(ia[j]>ia[j+1])
   {
    //计数转换
   c++;
   String s = c;
   //输出计数次数
   TextOut(DC,110,12,s.c_str(),s.Length());
	temp=ia[j];
    SetPixel(DC,ia[j+1]+PixelOfBorder,j+1+PixelOfBorder,FormColor);//设置指定设备指定位置像素的颜色值
	SetPixel(DC,ia[j]+PixelOfBorder,j+PixelOfBorder,FormColor);//到原位置把小点擦除
	ia[j]=ia[j+1];
    ia[j+1]=temp;
	SetPixel(DC,ia[j+1]+PixelOfBorder,j+1+PixelOfBorder,PenColor);//到新的位置画一个小点
	SetPixel(DC,ia[j]+PixelOfBorder,j+PixelOfBorder,PenColor);//到新的位置画一个小点
   }
 }
 ReleaseDC(Form2->Handle,DC);
}




void QuickSort(int *ia,int iLow,int iHigh,int c)//快速排序算法
{
 int temp;//用来交换两个变量的值
 int Low=iLow;//排序的下界
 int High=iHigh;//排序的上界
 int Mid=ia[int((Low+High)/2)];//排序的中间位置，需要类型转换为整形，数组下标不能为小数
 HDC DC=GetDC(Form3->Handle);
 do
 {
  while(ia[Low]<Mid)Low++;
  while(ia[High]>Mid)High--;
  if(Low<=High)
  {
   temp=ia[Low];
   SetPixel(DC,ia[Low]+PixelOfBorder,Low+PixelOfBorder,FormColor);//到原位置把小点擦除
   SetPixel(DC,ia[High]+PixelOfBorder,High+PixelOfBorder,FormColor);//到原位置把小点擦除
   ia[Low]=ia[High];
   ia[High]=temp;
   SetPixel(DC,ia[Low]+PixelOfBorder,Low+PixelOfBorder,PenColor);//到新的位置画一个小点
   SetPixel(DC,ia[High]+PixelOfBorder,High+PixelOfBorder,PenColor);//到新的位置画一个小点
   Low++;
   //计数转换
   c++;
   String s = c;
   //输出计数次数
   TextOut(DC,110,12,s.c_str(),s.Length());
   High--;
  }
 }while(Low<=High);
 if(High>iLow)QuickSort(ia,iLow,High,c);//递归调用自己
 if(Low<iHigh)QuickSort(ia,Low,iHigh,c);//递归调用自己
 ReleaseDC(Form3->Handle,DC);
}

DWORD CALLBACK BubbleSortThreadFunction(void *p)//冒泡排序入口函数
{
 int co = *((int*)p);
 BubbleSort(Form1->a,Form1->NumberOfItems-1,co);
 return(0);
}

DWORD CALLBACK QuickSortThreadFunction(void *p)//快速排序入口函数
{
 int co = *((int*)p);
 QuickSort(Form1->b,0,Form1->NumberOfItems-1,co);
 return(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)//把三个窗体放到指定的位置（靠桌面最上的中间），找到桌面中心的位置
{
 Form1->Top=0;
 Form1->Left=int((Screen->DesktopWidth-Width)/2);
 SortWindowSize=Screen->DesktopWidth-Height-PixelOfFormGap;
 if(SortWindowSize>int(Screen->DesktopWidth/2))
  SortWindowSize=int(Screen->DesktopWidth/2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
 delete[] a;//把数组a的空间回收
 delete[] b;//把数组b的空间回收
}


//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{

 delete Form2;//动态生成窗体2，并显示到指定的位置
 Form2=new TForm2(this);
 Form2->Top=Form1->Top+Form1->Height+PixelOfFormGap;
 Form2->Left=int((Screen->DesktopWidth-SortWindowSize*2)/2);
 Form2->Width=SortWindowSize;
 Form2->Height=SortWindowSize;
 Form2->Color=FormColor;
 Form2->Show();//显示窗体


 //----------------------------------------------------------
 delete Form3;//动态生成窗体3，并显示到指定的位置
 Form3=new TForm3(this);
 Form3->Top=Form1->Top+Form1->Height+PixelOfFormGap;
 Form3->Left=Form2->Left+Form2->Width;
 Form3->Width=SortWindowSize;
 Form3->Height=SortWindowSize;
 Form3->Color=FormColor;
 Form3->Show();//显示窗体

 //----------------------------------------------------------
 NumberOfItems=StrToInt(Edit1->Text);//把Edit1的Text属性中存放的字符串转换为整形数
 delete[] a;//删除数组a
 a=new int[NumberOfItems];//用a指向新创建的数组
 delete[] b;//删除数组b
 b=new int[NumberOfItems];//用b指向新创建的数组
 randomize();//初始化随机数生成器
 for(int i=0;i<NumberOfItems;i++)
 {
  a[i]=random(NumberOfItems);//根据输入的指定的值，在允许的范围内产生一个随机整数
  b[i]=a[i];
  Form2->Canvas->Pixels[a[i]+PixelOfBorder][i+PixelOfBorder]=PenColor;//初始时在窗体2的指定位置画个小点
  Form3->Canvas->Pixels[b[i]+PixelOfBorder][i+PixelOfBorder]=PenColor;//初始时在窗体3的指定位置画个小点
 }


 DWORD ThreadID1;
 int *count1 = 0;
 T1=CreateThread(0,0,BubbleSortThreadFunction,(void *)&(count1),0,&ThreadID1);//创建一个新线程执行冒泡排序
 if(RadioButton1->Checked)SetThreadPriority(T1,-2);//设置指定线程的优先级
 else if(RadioButton2->Checked)SetThreadPriority(T1,0);
	  else SetThreadPriority(T1,2);

 DWORD ThreadID2;
 int *count2 = 0;
 T2=CreateThread(0,0,QuickSortThreadFunction,(void *)&(count2),0,&ThreadID2);//创建一个新线程执行快速排序
 if(RadioButton4->Checked)SetThreadPriority(T2,-2);//设置指定线程的优先级
 else if(RadioButton5->Checked)SetThreadPriority(T2,0);
      else SetThreadPriority(T2,2);
}
//---------------------------------------------------------------------------
