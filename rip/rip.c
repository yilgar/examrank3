#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_isvalid(char *s)
{
	int o = 0;
	int c = 0;
	int i = 0;
	while (s[i])
	{
		if (s[i] == '(')
			o++;
		else if (s[i] == ')')
		{
			if (o > 0)
				o--;
			else
				c++;
		}
		i++;
	}
	return (o  + c);
}


void rip(char *s, int mf, int f, int p)
{
	if (mf == f && !ft_isvalid(s))
	{
		puts(s);
		return ;
	}

	int i = p;
	while(s[i])
	{
		if(s[i] == '(' || s[i] == ')')
		{
			char c = s[i];
			s[i] = ' ';
			rip(s, mf, f+ 1, i + 1);
			s[i] = c;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		while(av[1][i])
		{
			if (av[1][i] != '(' && av[1][i] != ')')
				return 1;
			i++;
		}
		int mf = ft_isvalid(av[1]);
		rip(av[1], mf, 0, 0);
	}
}