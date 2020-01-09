/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:22:50 by edouvier          #+#    #+#             */
/*   Updated: 2019/12/02 10:22:52 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_width(char *form, va_list *ap, t_parsing *elem)
{
	int		i;

	i = 0;
	if (form && ft_isdigit(form[i]))
	{
		elem->width = ft_atoi(&form[i]);
		while (ft_isdigit(form[i]))
			i++;
	}
	else if (form && form[i] == '*')
	{
		elem->width = va_arg(*ap, unsigned int);
		i++;
		if (elem->width < 0)
		{
			elem->flag_tiret = 1;
			elem->flag_zero = 0;
			elem->width *= -1;
		}
	}
	return (i);
}

void	ft_width(t_parsing *elem)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)ft_calloc(sizeof(char), (elem->width + 1));
	if ((elem->type == 'c' || elem->type == 's' || elem->type == 'p' || elem->type == 'd' || elem->type == 'i'|| elem->type == 'u'||
	elem->type == 'x' || elem->type == 'X' || elem->type == '%') && (elem->width > ft_strlen(elem->arg)))
	{
		if (elem->arg[0] == '-')
		{
			tmp[i] = '-';
			i++;
		}
		while (elem->width > ft_strlen(elem->arg))
		{
			if (elem->flag_zero == 1)
				tmp[i] = '0';
			else
				tmp[i] = ' ';
			i++;
			elem->width--;
		}
		tmp[i] = '\0';
		if (elem->flag_tiret)
			tmp = ft_strjoin(elem->arg, tmp);
		else
			tmp = ft_strjoin(tmp, elem->arg);
		free(elem->arg);
		elem->arg = tmp;
	}
}
