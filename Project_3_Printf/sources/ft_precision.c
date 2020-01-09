/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:22:42 by edouvier          #+#    #+#             */
/*   Updated: 2019/12/02 10:22:44 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"


int		ft_is_precision(char *form, va_list *ap, t_parsing *elem)
{
	int		i;

	i = 0;
	if (form && form[i] == '.')
	{
		i++;
		elem->precision = 1;
		if (form && ft_isdigit(form[i]))
		{
			elem->precision = ft_atoi(&form[i]);
			while (ft_isdigit(form[i]))
				i++;
		}
		else if (form && form[i] == '*')
		{
			elem->precision = va_arg(*ap, unsigned int);
			i++;
		}
	
	}
	return (i);
}

void	ft_precison_s(t_parsing *elem)
{
	char 	*tmp;

	if (elem->type == 's' && elem->precision > 0)
	{
		tmp = ft_substr(elem->arg, 0, elem->precision);
		free(elem->arg);
		elem->arg = tmp;
	}
}

void	ft_precision_cpdiuxX(t_parsing *elem)
{
	char	*tmp;
	int		i;

	i = 0;
	if ((elem->type == 'c' || elem->type == 'p' || elem->type == 'd' || elem->type == 'i'|| elem->type == 'u'||
	elem->type == 'x' || elem->type == 'X') && (elem->precision > ft_strlen(elem->arg)))
	{
		tmp = (char *)ft_calloc(sizeof(char), (elem->precision + 1 + elem->arg[0] == '-' ? 1 : 0));
		printf("aloooors : %c\n", elem->arg[0]);
		if (elem->arg[0] == '-')
			{
				tmp[i] = '-';
				i++;
			}
		while (elem->precision > (ft_strlen(elem->arg)) - (tmp[0] == '-' ? 1 : 0))
		{
			tmp[i] = '0';
			i++;
			elem->precision--;
		}
		tmp[i] = '\0';
		tmp = ft_strjoin(tmp, &(elem->arg[tmp[0] == '-' ? 1 : 0]));
		free(elem->arg);
		elem->arg = tmp;
	}
}