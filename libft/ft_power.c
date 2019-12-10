#include "libft.h"

double		ft_power(double nbr, double power)
{
	int		i;
	double	res;

	res = 1;
	i = 1;
	while (i <= power)
	{
		res = res * nbr;
		i++;
	}
	return (res);
}