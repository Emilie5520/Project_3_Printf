/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:21:10 by edouvier          #+#    #+#             */
/*   Updated: 2019/11/28 14:25:15 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_initialize_parsing(t_parsing *elem)
{
	elem->flag_tiret = 0;
	elem->flag_zero = 0;
	elem->width_asterisque = 0;
	elem->precision_point = 0;
	//elem.size = 0;
	//elem.type = 0;
	//elem.params = 0;
}

int		ft_complete_parsing(char *form, t_parsing *elem) //remplir les elements de ma structure
{
	int		i;

	i = 0;
	i += ft_is_flags(form, elem); // i+= pour a chaque fois incrementer i pour recuperer le bon nbr dans ft_printf
	i += ft_is_width(form, elem);
	i += ft_is_precision(form, elem);
	return (i);
} 

int		ft_is_flags(char *form, t_parsing *elem) // recupère l'adresse de form
{
	int		i;

	i = 0;
	while (form)
	{
		while (form[i] == '-' || form[i] == '0') //si - et 0, 0 est ignoré
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

int		ft_is_width(char *form, t_parsing *elem)
{
	int		i;

	i = 0;
	while (form)
	{
		if (form[i] == '*')
			elem->width_asterisque = 1;
	}
	return (i);
}

int		ft_is_precision(char *form, t_parsing *elem)
{
	int		i;

	i = 0;
	while (form)
	{
		if (form[i] == '.')
			elem->precision_point = 1;
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_parsing	*elem;
	char		*form;
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	va_start(ap, format);
	form = (char*)format; //on travaille avec form et non format 
	elem = (t_parsing*)malloc(sizeof(t_parsing)); //malloc pour stocker les infos dans ma structure 
	if (elem == NULL)
		return (0);
	while (form)
	{
		if (form[i] == '%')
		{
			ft_initialize_parsing(elem);
			i++;
			ft_complete_parsing(form, elem);
		}
		else
		{
			ft_putchar(form[i]);
			len = ft_strlen(form);
			i++;
		}
	}
	va_end(ap);
	return (len);
}

int	main(void)
{
	ft_printf("%-", "coucou");
//	printf("|%-5d|\n", 10);
//	printf("|%5d|\n", 10);
//	printf("|%d|\n", 10);
//	printf("|%05d|\n", 20);
//	printf("|%5d|\n", 20);
//	printf("|%d|\n", 20);
// si 0 et - l'attribut 0 est ignore
//	printf("|%0*d|\n", 5, 3);
//	printf("|%*d|\n", 5, 3);
//	printf("|%.0d|\n", 0);
//	printf("|%u|\n", "abcd");
//	printf("|%.5s|\n", "coucou" );
//	printf("|%.w2d0s|", "coucou");
	return (0);	
}

