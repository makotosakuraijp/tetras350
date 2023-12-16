#include <key.h>

int KEY::rotate (int a, int b)
{
	return (a >> (b - 1)) - (a >> b) * 2;
}
