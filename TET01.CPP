#include <tetras.h>

/*void *operator new (size_t size)
{
	unsigned segm;

	if ((segm = hmem_allocbyte (size)) == 0)
	{
		printf ("Out of memory.\n");
		exit (11);
	}

	return (void *) MK_FP (segm, 0);
}

void operator delete (void *p)
{
	hmem_free (FP_SEG (p));
}*/

char *strcat (char *dest, const char src) //strcat‚Ìˆê•¶Žš”Å
{
	char tmp [2];
	tmp [0] = src;
	tmp [1] = NULL;
	return ::strcat (dest, tmp);
}
