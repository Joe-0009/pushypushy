#include "push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*a;

	if (num_elements != 0 && SIZE_MAX / num_elements < element_size)
		return (NULL);
	a = malloc(num_elements * element_size);
	if (!a)
		return (NULL);
	if (num_elements == 0 || element_size == 0)
	{
		ft_memset(a, 0, 1);
		return (a);
	}
	ft_memset(a, 0, element_size * num_elements);
	return (a);
}
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

int	ft_intcmp(int a, int b)
{
	return (a == b);
}

