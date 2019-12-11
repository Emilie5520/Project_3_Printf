#include "../includes/ft_printf.h"

int		ft_is_precision(char *form, va_list *ap, t_parsing *elem)
{
	int		i;

	i = 0;
	if (form && form[i] == '.')
	{
		i++;
		elem->precision_point = 1;
		if (form && ft_isdigit(form[i]))
		{
			elem->precision_point = form[i];
			while (ft_isdigit(form[i]))
				i++;
		}
		else if (form && form[i] == '*')
		{
			elem->precision_asterisque = va_arg(*ap, int);
			i++;
		}
	
	}
	return (i);
}
