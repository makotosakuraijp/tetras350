#include <graph.h>

void GRAPH::copypage (int to_page)
{
	switch (m.machine)
	{
		case PC9801:
			graph_copy_page (to_page);
			break;

		case PC_AT:
			at_copypage (to_page);
			break;

		case FMR:
			break;
	}
}
