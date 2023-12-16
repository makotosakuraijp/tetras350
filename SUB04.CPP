#include <tetras.h>

XY::XY (void)
{
	x = 0;
	y = 0;
}

XY::XY (int a, int b)
{
	x = a;
	y = b;
}

void XY::operator =(XY a)
{
	x = a.x;
	y = a.y;
}

int BLOCK::all (void)
{
	int i;
	int k = 0;
	for (i = 0; i <= 9; i++)
		k += t [i];
	return (k == 10);
}

BLOCK::BLOCK (void)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		bfnt [i] = -1;
		t [i] = 0;
	}
}

void BLOCK::operator =(int a)
{
	int i;
	for (i = 0; i <= 9; i++)
	{
		t [i] = a;
		if (a == 0)
			bfnt [i] = -1;
	}
}
