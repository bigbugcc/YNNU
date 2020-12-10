//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
const int PixelOfBorder=5;//窗体边界的宽度
const int PixelOfFormGap=0;//两个绘图窗体间的距离
const TColor FormColor=clBlack;//绘图窗体的背景颜色
const TColor PenColor=clWhite;//小点的颜色
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TLabel *Label1;
        TSpeedButton *SpeedButton1;
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TGroupBox *GroupBox2;
        TRadioButton *RadioButton6;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton4;
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
 HANDLE T1;//冒泡排序线程句柄
 HANDLE T2;//快速排序线程句柄
 int SortWindowSize;
public:		// User declarations
 int *a;//冒泡排序随机数数组指针
 int *b;//快速排序随机数数组指针
 int NumberOfItems;//排序的随机数的个数
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
