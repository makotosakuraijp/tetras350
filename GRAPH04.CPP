#include <graph.h>

void GRAPH::active (int page)
{
	switch (m.machine)
	{
		case PC9801:
			graph_accesspage (page);
			break;

		case PC_AT:
			at98_accesspage (page);
			break;

		case FMR:
			break;
	}
}
