#include <graph.h>

void GRAPH::box (int x1, int y1, int x2, int y2, int color1, int color2)
{
	setcolor (color2);
	switch (m.machine)
	{
		case PC9801:
			grcg_line (x1, y1, x2, y1);
			grcg_line (x2, y1, x2, y2);
			grcg_line (x2, y2, x1, y2);
			grcg_line (x1, y2, x1, y1);
			setcolor (color1);
			grcg_boxfill (x1 + 1, y1 + 1, x2 - 1, y2 - 1);
			break;

		case PC_AT:
			vgc_line (x1, y1, x2, y1);
			vgc_line (x2, y1, x2, y2);
			vgc_line (x2, y2, x1, y2);
			vgc_line (x1, y2, x1, y1);
			setcolor (color1);
			vgc_boxfill (x1 + 1, y1 + 1, x2 - 1, y2 - 1);
			break;

		case FMR:
			break;
	}
}
