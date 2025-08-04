#include <stdio.h>
#include <stdlib.h>

int argc;
char **argv;
int	solution = 0;
int	*subset;
int subsetlen = 0;
int target;

void	print(void)
{
	for(int i = 0; i < subsetlen; i++)
	{
		solution = 1;
		if (i > 0)
			printf(" ");
		printf("%d", subset[i]);
	}
	printf("\n");
}

int sum(void)
{
	int sum = 0;
	for(int i = 0; i < subsetlen; i++)
		sum += subset[i];
	return sum;
}

void	find(int start)
{
	if (subsetlen != 0)
	{
		if (sum() == target)
			print();
	}
	for(int i = start; i < argc; i++)
	{
		subset[subsetlen++] = atoi(argv[i]);
		find(i + 1);
		subsetlen--;
	}
}

int	main(int ac, char *av[])
{
	if (ac <= 2)
		return 1;
	argc = ac;
	argv = av;
	target = atoi(av[1]);
	int buff[ac - 2];
	subset = buff;

	find(2);
	if(!solution)
		printf("\n");
}