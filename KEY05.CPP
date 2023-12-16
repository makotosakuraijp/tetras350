#include <key.h>

void KEY::key (int *scan, int *shift)
{
	switch (m.machine)
	{
		case PC9801:
			/*DOSファンクションとキーBIOSを併用する場合は、*/
			/*BREAKチェックをオフにすること*/
			*scan  = (int) (pc98key (0) >> 8);
			*shift = (int) (pc98key (2));
			break;

		case PC_AT:
			/*BREAKチェックをオフにすること*/
			*scan  = vkey_scan ();
			*shift = 0;
			break;

		case FMR:
			break;
	}
}
