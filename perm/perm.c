#include <stdio.h>
#include <stdlib.h>

int	strlen_(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	swap_(char *s1, char *s2)
{
	char	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	sort_arg(char *arg)
{
	int	i;
	int	j;

	i = strlen_(arg);
	while (i--)
	{
		j = 0;
		while (arg[j + 1])
		{
			if (arg[j] > arg[j + 1])
				swap_(arg + j, arg + j + 1);
			j++;
		}
	}
}

void	permute(char *str, int start, int end)
{
	int	i;

	if (start == end)
		puts(str);
	else
	{
		i = start;
		while (i < end)
		{
			sort_arg(str + start);
			swap_(str + start, str + i);
			permute(str, start + 1, end);
			swap_(str + start, str + i);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	permute(av[1], 0, strlen_(av[1]));
	return (0);
}
