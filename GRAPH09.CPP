#include <graph.h>

void GRAPH::clear (void)
{
	switch (m.machine)
	{
		case PC9801:
			graph_clear ();
			break;

		case PC_AT:
			vga4_clear ();
			break;

		case FMR:
			break;
	}
}
