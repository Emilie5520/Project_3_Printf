#include "../includes/ft_printf.h"

int	ft_is_type(char *form, t_parsing *elem)
{
	int 	i;

	i = 0;
	if (form)
		if (form[i] == 'c' || form[i] == 's' ||form[i] == 'p'||form[i] == 'd'||form[i] == 'i' || form[i] == 'u' || form[i] == 'x' || form[i] == 'X' || form[i] == '%')
		{
			elem->type = form[i];
			i++;
		}
	return (i);
}
