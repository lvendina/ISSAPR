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
	AnsiString initial_string = start_memo->Text;


	AnsiString finish_string = "";

	int number_bracket = 0;

	int j = 1;
	while (j != initial_string.Length()-1) {

		if ((initial_string[j] == ';') && (initial_string[j+1] != '\r')) {
			if (!number_bracket) {
				initial_string.Insert("\r\n", j+1);
			}
		}
		if (number_bracket) {
			if (initial_string[j+1] == '\r' && initial_string[j] != '\\') {
				initial_string.Delete(j+1, 2);
			}
		}
		if (initial_string[j] == '(')
			number_bracket += 1;
		if (initial_string[j] == ')')
			number_bracket -= 1;

		j++;
	}

	j = 1;
	while (j != initial_string.Length()-1) {
		if (initial_string[j] == '{' && initial_string[j+1] != '\r') {
			initial_string.Insert("\r\n", j+1);
		}
		if (initial_string[j] == ')' && initial_string[j+1] != '\r'
			&& initial_string[j+1] != ';') {
			initial_string.Insert("\r\n", j+1);
			int i = j + 3;
			while (initial_string[i] == ' ') {
				initial_string.Delete(i, 1);
			}
		}
		if (initial_string[j] == ')' && initial_string[j-1] == '\n') {
			initial_string.Delete(j-2, 2);
		}
		++j;
	}

	number_bracket = 0;
	int number_for = 0;

	j = 2;
	while (j <= initial_string.Length()) {
		if (initial_string[j] == '{') {
			number_bracket += 1;
			if (number_for) {
				number_for = 0;
			}
		}

		if (initial_string[j] == 'f' && initial_string[j+1] == 'o' &&
			initial_string[j+2] == 'r' && initial_string[j+3] == '(') {
			number_for = 1;
			for (int i = 1; i <= number_bracket + number_for - 1; ++i) {
					initial_string.Insert("    ", j);
			}
			while (initial_string[j] != ')') {
				++j;
			}
		}

		if (initial_string[j-1] == '\n') {
			if (initial_string[j] == '{') {
				for (int i = 1; i <= number_bracket + number_for - 1; ++i) {
					initial_string.Insert("    ", j);
					j += 4;
				}
			}
			else if (initial_string[j] == '}') {
				for (int i = 1; i <= number_bracket + number_for - 1; ++i) {
					initial_string.Insert("    ", j);
				}
			}
			else {
				for (int i = 1; i <= number_bracket + number_for; ++i) {
					initial_string.Insert("    ", j);
				}
			}
		}

		if (initial_string[j] == ';') {
			number_for = 0;
		}
		if (initial_string[j] == '}') {
			number_bracket -= 1;
		}

		j++;
	}

	exit_memo->Text = initial_string;
}
//---------------------------------------------------------------------------
