#include "gnl.h"

char *ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n-- > 0)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

size_t ft_strlen(char *s)
{
	size_t ret;

	ret = 0;
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t size1;
	char *tmp;

	if (*s1)
	{
		size1 = ft_strlen(*s1);
	}
	else
		size1 = 0;
	tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if (dest == src)
		return (dest);
	else if (dest > src)
		return (ft_memcpy(dest, src, n));
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char *get_next_line(int fd)
{
	static char b[BUFFER_SIZE + 1] = "";
	char *ret;
	char *tmp;
	int read_ret;

	ret = NULL;
	tmp = ft_strchr(b, '\n');
	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		b[read_ret] = 0;
		if (read_ret == 0)
			break;
		tmp = ft_strchr(b, '\n');
	}
	if (tmp)
	{
		if (!str_append_mem(&ret, b, tmp - b + 1))
		{
			free(ret);
			return (NULL);
		}
		ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	}
	else if (ret && *ret)
	{
		b[0] = '\0';
		return ret;
	}
	else
		return free(ret), NULL;
	return (ret);
}
