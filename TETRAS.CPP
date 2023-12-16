#include <tetras.h>

extern unsigned _stklen = 17000;

int main (void)
{
	//logo ();
	//title ();

	try
	{
		MACHINE m;
		TETRAS *tetras;

		switch (m.machine)
		{
			case PC9801:
				tetras = new TETRAS98;
				break;

			case PC_AT:
				tetras = new TETRASat;
				break;

			default:
				printf ("�c�O�Ȃ���A���o�[�W�����ł͂��̋@��ɂ͑Ή����Ă��܂���B\n");
				exit (5);
				break;
		}

		tetras->go ();
		delete tetras;
	}
	catch (xalloc)
	{
		printf ("main�ɂ����āA�w������������O����\n");
	}
	catch (...)
	{
		printf ("main�ɂ����āA��̗�O����\n");
	}
	return 0;
}