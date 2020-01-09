/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:22:20 by edouvier          #+#    #+#             */
/*   Updated: 2019/12/03 16:33:26 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int		ft_is_flags(char *form, t_parsing *elem)
{
	int		i;

	i = 0;
	if (form)
	{
		while (form[i] == '-' || form[i] == '0')
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
