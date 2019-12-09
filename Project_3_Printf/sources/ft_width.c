#include "../includes/ft_printf.h"

int		ft_is_width(char *form, t_parsing *elem)
{
	int		i;

	i = 0;
	if (form && form[i] == '*')
 	{
		i++;	
		elem->width_asterisque = 1;
	}
	return (i);
}
