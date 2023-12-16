#include <graph.h>

void GRAPH::circle (int x, int y, int r, int color1, int color2)
{
	setcolor (color2);
	switch (m.machine)
	{
		case PC9801:
			grcg_circle (x, y, r);
			setcolor (color1);
			grcg_circlefill (x, y, r - 1);
			break;

		case PC_AT:
			vgc_circle (x, y, r);
			setcolor (color1);
			vgc_circlefill (x, y, r - 1);
			break;

		case FMR:
			break;
	}
}
