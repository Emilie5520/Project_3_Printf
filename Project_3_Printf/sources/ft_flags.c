#include "../includes/ft_printf.h"

int	ft_is_flags(char *form, t_parsing *elem) // recupère l'adresse de form
{
	int		i;

	i = 0;
	if (form)
	{
		while (form[i] == '-' || form[i] == '0') //si - et 0, 0 est ignor
		{
			if (form[i] == '-')
				elem->flag_tiret = 1;
			if (form[i] == '0' && elem->flag_tiret != 1)
				elem->flag_zero = 1;
			if (elem->flag_tiret == 1)
				elem->flag_zero = 0;
			i++;
		}
	}
	return (i);
}
