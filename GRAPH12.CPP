#include <graph.h>

void GRAPH::setcolor (int color)
{
	switch (m.machine)
	{
		case PC9801:
			grcg_setcolor (GC_RMW, color);
			break;

		case PC_AT:
			vgc_setcolor (VGA_PSET | GC_BRGI, color);
			break;

		case FMR:
			break;
	}
}
