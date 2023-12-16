#include <key.h>

void KEY::key (int *scan)
{
	switch (m.machine)
	{
		case PC9801:
			/*DOSファンクションとキーBIOSを併用する場合は、*/
			/*BREAKチェックをオフにすること*/
			*scan = (int) (pc98key (0) >> 8);
			break;

		case PC_AT:
			*scan = (int) dos_getkey ();
			break;

		case FMR:
			break;
	}
}
