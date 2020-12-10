object Form1: TForm1
  Left = 234
  Top = 139
  BorderStyle = bsDialog
  Caption = #32447#31243#19982#20020#30028#21306
  ClientHeight = 390
  ClientWidth = 556
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 12
  object ListBox1: TListBox
    Left = 32
    Top = 16
    Width = 153
    Height = 329
    ItemHeight = 12
    TabOrder = 0
  end
  object ListBox2: TListBox
    Left = 200
    Top = 16
    Width = 153
    Height = 329
    ItemHeight = 12
    TabOrder = 1
  end
  object CheckBox1: TCheckBox
    Left = 152
    Top = 352
    Width = 121
    Height = 17
    Caption = 'Critical Section'
    TabOrder = 2
  end
  object Button1: TButton
    Left = 280
    Top = 352
    Width = 75
    Height = 25
    Caption = 'Run'
    TabOrder = 3
    OnClick = Button1Click
  end
  object ListBox3: TListBox
    Left = 369
    Top = 16
    Width = 153
    Height = 329
    ItemHeight = 12
    TabOrder = 4
  end
end
