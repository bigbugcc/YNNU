object Form1: TForm1
  Left = 479
  Top = 234
  BorderStyle = bsDialog
  Caption = #32447#31243#20248#20808#32423#35774#32622
  ClientHeight = 220
  ClientWidth = 351
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 10
    Top = 10
    Width = 60
    Height = 12
    Caption = #20803#32032#20010#25968#65306
  end
  object SpeedButton1: TSpeedButton
    Left = 230
    Top = 10
    Width = 111
    Height = 28
    Caption = #24320#22987#25490#24207
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000130B0000130B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      3333333FFF33F333FF3F330E0330FFFCCFCC33777FF7F3377F7730EEE030FFFC
      CFCC377777F7F33773770EEE0000FFFFFCCF777777773F33377FEEE0BFBF0FFF
      FCCF7777333373F337730E0BFBFBF0FFCCFF77733333373F77F330BFBFBFBF0F
      CCFF37F333333F7F773330FBFBFB0B0FFFFF37F3F33F737FFFFF30B0BF0FB000
      000037F73F73F777777730FB0BF0FB0FFFFF373F73F73F7F333F330030BF0F0F
      FF993F77373F737F3377CC33330BF00FFF9977FFF373F77F3F77CC993330009F
      99FF7777F337777F77F333993330F99F99FF3F77FF37F773773F993CC330FFF9
      9F9977F77F37F3377F77993CC330FFF99F997737733733377377}
    NumGlyphs = 2
    OnClick = SpeedButton1Click
  end
  object Edit1: TEdit
    Left = 90
    Top = 10
    Width = 121
    Height = 20
    TabOrder = 0
    Text = '400'
    OnKeyPress = Edit1KeyPress
  end
  object GroupBox1: TGroupBox
    Left = 10
    Top = 50
    Width = 331
    Height = 71
    Caption = #20882#27873#25490#24207#27861
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 20
      Top = 30
      Width = 91
      Height = 21
      Caption = #20248#20808#32423'-2'
      TabOrder = 0
    end
    object RadioButton2: TRadioButton
      Left = 130
      Top = 30
      Width = 81
      Height = 21
      Caption = #20248#20808#32423'0'
      Checked = True
      TabOrder = 1
      TabStop = True
    end
    object RadioButton3: TRadioButton
      Left = 230
      Top = 30
      Width = 91
      Height = 21
      Caption = #20248#20808#32423'+2'
      TabOrder = 2
    end
  end
  object GroupBox2: TGroupBox
    Left = 10
    Top = 130
    Width = 331
    Height = 71
    Caption = #24555#36895#25490#24207#27861
    TabOrder = 2
    object RadioButton6: TRadioButton
      Left = 230
      Top = 30
      Width = 91
      Height = 21
      Caption = #20248#20808#32423'+2'
      TabOrder = 0
    end
    object RadioButton5: TRadioButton
      Left = 130
      Top = 30
      Width = 81
      Height = 21
      Caption = #20248#20808#32423'0'
      Checked = True
      TabOrder = 1
      TabStop = True
    end
    object RadioButton4: TRadioButton
      Left = 20
      Top = 30
      Width = 91
      Height = 21
      Caption = #20248#20808#32423'-2'
      TabOrder = 2
    end
  end
end
