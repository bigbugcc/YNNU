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
const int PixelOfBorder=5;//����߽�Ŀ��
const int PixelOfFormGap=0;//������ͼ�����ľ���
const TColor FormColor=clBlack;//��ͼ����ı�����ɫ
const TColor PenColor=clWhite;//С�����ɫ
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
 HANDLE T1;//ð�������߳̾��
 HANDLE T2;//���������߳̾��
 int SortWindowSize;
public:		// User declarations
 int *a;//ð���������������ָ��
 int *b;//�����������������ָ��
 int NumberOfItems;//�����������ĸ���
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
