//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
void __fastcall TForm1::btn_formatClick(TObject *Sender) {
/*	initial_string = start_memo->Text;
	initial_string = doEnterAfterPointWithComma(initial_string);
	initial_string = doEnterAfterBracket(initial_string);
	initial_string = doTabs(initial_string);
	exit_memo->Text = initial_string
    */
}
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
