#include <stdio.h>
#include <stdlib.h>

/*
	Print hello world n times without using loop.
solution:
	Using recursion.
*/

void printHello(int n)
{
	if (n > 0)
	{
		printf("Hello\n");
		n--;
		printHello(n);
	}
}

int main(int argc, char const *argv[])
{
	if ((argc != 2) || (atoi(argv[1]) < 0))
	{
		printf("invalid aruments!\n");
		exit(0);
	}

	printHello(atoi(argv[1]));
	return 0;
}
