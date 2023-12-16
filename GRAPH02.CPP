#include <graph.h>

int GRAPH::graph = 0;

GRAPH::GRAPH (void)
{
	if (graph == 1)
	{
		return;
	}
	switch (m.machine)
	{
		case PC9801:
			graph_start ();
			grcg_and (GC_RMW, 0);
			break;

		case PC_AT:
			vga4_start(0x0e,640,400),vga_vzoom_off();
			break;

		case FMR:
			break;
	}
	graph = 1;
}
