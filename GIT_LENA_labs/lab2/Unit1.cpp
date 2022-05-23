//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::btn_formatClick(TObject *Sender)
{}
	AnsiString doEnterAfterPointWithComma(AnsiString initial_string) {
	int count_open_bracket = 0;

	int pos = 1;
	while (pos != initial_string.Length()-1) {

		if ((initial_string[pos] == ';') && (initial_string[pos+1] != '\r')) {
			if (!count_open_bracket) {
				initial_string.Insert("\r\n", pos+1);
			}
			if (count_open_bracket) {
				while (initial_string[pos+1] == ' ') {
					++pos;
				}
				if (initial_string[pos+1] == '\r') {
					initial_string.Delete(pos+1, 2);
				}
			}
		}
		if (initial_string[pos] == '(')
			++count_open_bracket;
		if (initial_string[pos] == ')')
			--count_open_bracket;

		++pos;
	}
	return initial_string;
}

AnsiString doEnterAfterBracket(AnsiString initial_string) {
	int pos = 1;
	while (pos != initial_string.Length()-1) {
		if (initial_string[pos] == '{' && initial_string[pos+1] != '\r') {
			initial_string.Insert("\r\n", pos+1);
		}
		if (initial_string[pos] == ')' && initial_string[pos+1] != '\r'
			&& initial_string[pos+1] != ';') {
			initial_string.Insert("\r\n", pos+1);
			int i = pos + 3;
			while (initial_string[i] == ' ') {
				initial_string.Delete(i, 1);
			}
		}
		if (initial_string[pos] == ')' && initial_string[pos-1] == '\n') {
			initial_string.Delete(pos-2, 2);
		}
		++pos;
	}

	return initial_string;
}

AnsiString doTabs(AnsiString initial_string) {
	int count_open_bracket = 0;
	int count_for = 0;

	int pos = 2;
	while (pos <= initial_string.Length()) {
		if (initial_string[pos] == '{') {
			++count_open_bracket;
			if (count_for) {
				count_for = 0;
            }
		}

		if (initial_string[pos] == 'f' && initial_string[pos+1] == 'o' &&
			initial_string[pos+2] == 'r' && initial_string[pos+3] == '(') {
			count_for = 1;
			for (int i = 1; i <= count_open_bracket + count_for - 1; ++i) {
					initial_string.Insert("    ", pos);
			}
			while (initial_string[pos] != ')') {
                ++pos;
			}
		}

		if (initial_string[pos-1] == '\n') {
			if (initial_string[pos] == '{') {
				for (int i = 1; i <= count_open_bracket + count_for - 1; ++i) {
					initial_string.Insert("    ", pos);
					pos += 4;
				}
			}
			else if (initial_string[pos] == '}') {
				for (int i = 1; i <= count_open_bracket + count_for - 1; ++i) {
					initial_string.Insert("    ", pos);
				}
			}
			else {
				for (int i = 1; i <= count_open_bracket + count_for; ++i) {
					initial_string.Insert("    ", pos);
				}
			}
		}

		if (initial_string[pos] == ';') {
			count_for = 0;
		}
        if (initial_string[pos] == '}') {
			--count_open_bracket;
		}

		++pos;
	}

	return initial_string;
}
//---------------------------------------------------------------------------
