#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		printf("invalid aruments!\n");
		exit(0);
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	a = a*b;
	b = a/b;
	a = a/b;

	printf("Afer swap a = %d, b = %d\n",a,b);
	return 0;
}
