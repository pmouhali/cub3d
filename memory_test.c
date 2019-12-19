#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void *ma;
	int *cma;

	ma = calloc(3, sizeof(int));

	cma = ma;

	int white = 16777215;
	int pink = 16750335;
	int black = 5;

	*cma = white;
	cma += 1;
	*cma = pink;
	cma += 1;
	*cma = black;
	
	cma--;
	cma--;
	printf("addr cma %p\n", &cma[0]);
	printf("valu cma %d\n", cma[0]);
	printf("addr cma %p\n", &cma[1]);
	printf("valu cma %d\n", cma[1]);
	printf("addr cma %p\n", &cma[2]);
	printf("valu cma %d\n", cma[2]);
}
