#include <graph.h>

void GRAPH::line (int x1, int y1, int x2, int y2, int color)
{
	setcolor (color);
	switch (m.machine)
	{
		case PC9801:
			grcg_line (x1, y1, x2, y2);
			break;

		case PC_AT:
			vgc_line (x1, y1, x2, y2);
			break;

		case FMR:
			break;
	}
}
