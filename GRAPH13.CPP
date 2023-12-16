#include <graph.h>

void GRAPH::visual (int page)
{
	switch (m.machine)
	{
		case PC9801:
			graph_showpage (page);
			break;

		case PC_AT:
			at98_showpage (page);
			break;

		case FMR:
			break;
	}
}
