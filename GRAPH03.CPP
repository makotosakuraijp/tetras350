#include <graph.h>

GRAPH::~GRAPH ()
{
	switch (m.machine)
	{
		case PC9801:
			grcg_off ();
			break;

		case PC_AT:
			break;

		case FMR:
			break;
	}
}
