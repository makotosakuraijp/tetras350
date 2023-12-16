#include <machine.h>

int MACHINE::machine = 0;

MACHINE::MACHINE (void)
{
	unsigned a = get_machine ();

	if (machine != 0)
	{
		return;
	}

	if (a & FMR)
	{
		machine = FMR;
	}
	else
	{
		if (a & PC9801)
		{
			machine = PC9801;
		}
		else
		{
			if (a & PC_AT)
			{
				machine = PC_AT;
			}
			else
			{
				machine = -1;
			}
		}
	}
}
