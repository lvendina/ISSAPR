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
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
	AnsiString start_text = start_memo->Text;
	AnsiString exit_text = "";

	int pos_for = start_text.Pos(" for");

	while (pos_for > 0) {
		exit_text += start_text.SubString(1, pos_for-1);
		start_text = start_text.Delete(1, pos_for-1);

		int pos_open_bracket = start_text.Pos("(");
		int pos_point_with_comma = start_text.Pos(";");
		AnsiString instruction_1 = start_text.SubString(pos_open_bracket + 1,
		pos_point_with_comma - pos_open_bracket);
		start_text = start_text.Delete(1, pos_point_with_comma);

		pos_point_with_comma = start_text.Pos(";");
		AnsiString instruction_2 = start_text.SubString(1, pos_point_with_comma-1);
		start_text = start_text.Delete(1, pos_point_with_comma);

		int pos_close_bracket = start_text.Pos(")");
		AnsiString instruction_3 = start_text.SubString(1, pos_close_bracket-1) + ";";
		start_text = start_text.Delete(1, pos_close_bracket);

		pos_point_with_comma = start_text.Pos(";");
		pos_open_bracket = start_text.Pos("{");
		if (pos_open_bracket < pos_point_with_comma) {
			exit_text += " " + instruction_1 + "\r\n";
			exit_text += "   while (" + instruction_2 + ") {\r\n";
			exit_text += "       " + instruction_3 + "\r\n";

			start_text = start_text.Delete(1, pos_open_bracket+1);
			pos_close_bracket = start_text.Pos("}");
			exit_text += start_text.SubString(1, pos_close_bracket);
			start_text = start_text.Delete(1, pos_close_bracket);
		}
		else if (pos_point_with_comma == 1) {
			exit_text += " " + instruction_1 + "\r\n";
			exit_text += "   while (" + instruction_2 + ") {\r\n";
			exit_text += "       " + instruction_3 + "\r\n   }";

			start_text = start_text.Delete(1, pos_point_with_comma);
		}
		else {
			exit_text += " " + instruction_1 + "\r\n";
			exit_text += "   while (" + instruction_2 + ") {\r\n";
			exit_text += "       " + instruction_3;

			exit_text += start_text.SubString(1, pos_point_with_comma) + "\r\n   }";
            start_text = start_text.Delete(1, pos_point_with_comma+1);
		}

		pos_for = start_text.Pos(" for");
	}

	exit_text += start_text;
	exit_memo->Text = exit_text;
}
//---------------------------------------------------------------------------
