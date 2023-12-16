#include <graph.h>

void GRAPH::circle (int x, int y, int r, int color)
{
	setcolor (color);
	switch (m.machine)
	{
		case PC9801:
			grcg_circle (x, y, r);
			break;

		case PC_AT:
			vgc_circle (x, y, r);
			break;

		case FMR:
			break;
	}
}

