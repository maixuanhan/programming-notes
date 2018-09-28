#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int a = atoi(argv[1]);

	/*Solution 1*/
	const char*b[2]={"EVEN", "ODD"};

	printf("%s\n", b[(a & 1)]);


	/*Solution 2*/
	(a&1) ? printf("ODD\n") : printf("EVEN\n");


	/*Solution 3*/
	switch (a % 2)
	{
		case 0:
			printf("EVEN\n");
			break;
		case 1:
			printf("ODD\n");
			break;
	}
	return 0;
}
