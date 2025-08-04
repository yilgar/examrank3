#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2, int len)
{
	while (len--)
	{
		if (*s1 == '\0' || *s2 == '\0' || *s1 != *s2)
			return 0;
		s1++;
		s2++;
	}
	return 1;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	char *buf = malloc(7000);
	if (!buf)
		return 1;
	int len = strlen(av[1]);
	char *line = av[1];
	char r;
	int i = 0;
	int readret = read(0, &r, 1);

	while (readret)
	{
		buf[i++] = r;
		readret = read(0, &r, 1);
	}
	buf[i] = '\0';
	i = 0;
	while (buf[i])
	{
		if (ft_strcmp(&buf[i], line, len))
		{
			int l = len;
			while ((l--))
				write(1, "*", 1);
			i += len;			
		}
		else
			write(1, &buf[i++], 1);
		}
}