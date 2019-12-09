#include "../includes/ft_printf.h"

int		ft_is_precision(char *form, t_parsing *elem)
{
	int		i;

	i = 0;
	if (form && form[i] == '.')
	{
		i++;
		elem->precision_point = 1;
	}
	if (form && form[i] == '*')
	{
		i++;
		elem->precision_asterisque = 1;
	}
	return (i);
}
