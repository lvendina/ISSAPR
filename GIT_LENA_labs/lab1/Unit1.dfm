object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 395
  ClientWidth = 622
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object start_lab: TLabel
    Left = 48
    Top = 32
    Width = 72
    Height = 13
    Caption = #1074#1093#1086#1076#1085#1086#1081' '#1092#1072#1081#1083
  end
  object exit_lab: TLabel
    Left = 312
    Top = 32
    Width = 80
    Height = 13
    Caption = #1074#1099#1093#1086#1076#1085#1086#1081' '#1092#1072#1081#1083
  end
  object start_memo: TMemo
    Left = 48
    Top = 64
    Width = 209
    Height = 281
    Lines.Strings = (
      '#include <iostream>'
      'using namespace std;'
      ' '
      'int main() {'
      'int i, j;'
      'for(i=0, j=0; i<10; i++)'#9'{cout<<i; '
      '}'
      'int FOR;'
      'int iforex=i;'
      'if(FOR<56, iforex>5){'
      ' sizeof("Hello \'
      'world \'
      '!"),'
      'cout<< "\n" << i,'
      'cout<< FOR;'
      '    }'
      'switch(iforex){'
      '    case 0:'
      'for(i=0, j=0; i<56; i++);'
      '    case 56:'
      '        cout<< FOR;'
      '            cout<< "FOR";'
      '    break;'
      '    default:    '
      '    std::cout << "\nHello World!\n";'
      '}'
      '      return 0;'
      '}'
      ' '
      #8212'-------------------'
      './main'
      '0123456789'
      '1012337'
      'Hello World!')
    TabOrder = 0
  end
  object exit_memo: TMemo
    Left = 312
    Top = 64
    Width = 217
    Height = 281
    Lines.Strings = (
      '')
    TabOrder = 1
  end
  object Button: TButton
    Left = 539
    Top = 362
    Width = 75
    Height = 25
    Caption = 'Convert'
    TabOrder = 2
    OnClick = ButtonClick
  end
end
