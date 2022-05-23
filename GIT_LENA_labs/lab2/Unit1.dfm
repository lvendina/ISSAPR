object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 418
  ClientWidth = 766
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object start_Label: TLabel
    Left = 64
    Top = 48
    Width = 54
    Height = 13
    Caption = 'start_Label'
  end
  object exit_Label: TLabel
    Left = 376
    Top = 48
    Width = 49
    Height = 13
    Caption = 'exit_Label'
  end
  object start_Memo: TMemo
    Left = 56
    Top = 80
    Width = 241
    Height = 321
    Lines.Strings = (
      '#include <iostream>'
      'using namespace std;'
      ' '
      'int main() {'
      'std::cout << "Hello World!\n";'
      'int i, j;'
      'for(i=0, j=0; i<56; i++)'
      'cout<<i;'
      'int FOR;'
      'for(FOR=0; '
      'FOR<56; FOR++'
      ') sizeof("Hello \'
      'world \'
      '!");'
      'cout<< " " << i;'
      'int iforex;'
      'for(iforex=0; iforex<56; iforex++);cout<<i;'
      'for(int k=i; k>0; k-=1, i--)'
      '{cout<<i;'
      'cout<<k;}'
      'while(--i);'
      'cout<<j;}')
    TabOrder = 0
  end
  object exit_Memo: TMemo
    Left = 376
    Top = 80
    Width = 257
    Height = 318
    TabOrder = 1
  end
  object Run: TButton
    Left = 672
    Top = 373
    Width = 75
    Height = 25
    Caption = 'Run'
    TabOrder = 2
  end
end
