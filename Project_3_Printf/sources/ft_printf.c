/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:16:07 by edouvier          #+#    #+#             */
/*   Updated: 2020/01/07 18:17:00 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_initialize_parsing(t_parsing *elem)
{
	elem->flag_tiret = 0;
	elem->flag_zero = 0;
	elem->width= 0;
	elem->precision = 0;
	elem->type = 0;
	elem->arg = NULL;
}

int	ft_complete_parsing(char *form, t_parsing *elem, va_list *ap)
{
	int		i;

	i = 0;
	i += ft_is_flags(&form[i], elem);
	i += ft_is_width(&form[i], ap, elem);
	i += ft_is_precision(&form[i], ap, elem);
	i += ft_is_type(&form[i], elem);
	ft_what_type(elem, ap);
	ft_precison_s(elem);
	ft_precision_cpdiuxX(elem);
	ft_width(elem);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_parsing	elem;
	char		*form;
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	va_start(ap, format);
	form = (char*)format;
	if (form)
	{
		while (form[i])
		{
			ft_initialize_parsing(&elem);
			if (form[i] == '%')
			{
				i++;
				i += ft_complete_parsing(&form[i], &elem, &ap);
				if (elem.arg)
				{
					ft_putstr(elem.arg);
					len += ft_strlen(elem.arg);
				}
			}
			if (!elem.arg && form)
			{
				ft_putchar(form[i]);
				len++;
				i++;
			}
		}
	}
	va_end(ap);
	return (len);
}


int	main(void)
{
	// printf("============== MARCHE PAS ==============\n");
	// ft_printf("%0*i\n", -7, -54);
	// ft_printf("%05X\n", 43);
	// ft_printf("%05x\n", 43);
	// ft_printf("%*d\n", 5, 3);
	// ft_printf("%0*i\n", -7, -54);
	// ft_printf("%.3\n", 12);
	// ft_printf("%.3s\n", "coucou");
	// ft_printf("%.*s\n", 3, "coucou");
	// printf("=============== VRAI PRINTF ===============\n");
	// printf("%0*i\n", -7, -54);
	// printf("%05X\n", 43);
	// printf("%05x\n", 43);
	// printf("%*d\n", 5, 3);
	// printf("%0*i\n", -7, -54);
	// printf("%.3\n", 12);
	// printf("%.3s\n", "coucou");
	// printf("%.*s\n", 3, "coucou");
	printf("============== MARCHE PAS ==============\n");
//	ft_printf("coucou\n");
	ft_printf("%.*s\n", 0, "hello");
	ft_printf("%0*i\n", 7, -54);
	// ft_printf("%.s\n", "NULL");
	// ft_printf("%s\n", NULL);
	// ft_printf("%.0s\n", "NULL");
//	ft_printf("%10.s\n", s_hidden);
	printf("=============== VRAI PRINTF ===============\n");
	printf("%.*s\n", 0, "hello");
	printf("%0*i\n", 7, -54);
	// printf("%.s\n", "NULL");
	// printf("%s\n", NULL);
	// printf("%.0s\n", "NULL");
//	printf("%10.s\n", s_hidden);
}