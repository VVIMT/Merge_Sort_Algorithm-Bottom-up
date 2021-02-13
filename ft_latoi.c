#include "Merge_Sort_Bottom_up.h"

static int  ft_isspace(int c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
	{
		return (1);
	}
	return (0);
}

long        ft_latoi(const char *str)
{
	size_t	i;
	long		a;
	long		sign;

	i = 0;
	a = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	i = (str[i] == '+' || str[i] == '-') ? i + 1 : i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = 10 * a + (str[i] - '0');
		i++;
	}
	a *= sign;
	return (a);
}