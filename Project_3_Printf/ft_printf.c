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

void	ft_initialize_parsing(t_parsing *elem)
{
	elem->flag_tiret = 0;
	elem->flag_zero = 0;
	elem->width_asterisque = 0;
	elem->width_digit = 0;
	elem->precision_point = 0;
	elem->precision_asterisque = 0;
	elem->type = 0;
	elem->arg = NULL;
}

int	ft_complete_parsing(char *form, t_parsing *elem, va_list *ap)
{
	int		i;

	i = 0;
	i += ft_is_flags(&form[i], elem); 
	printf("flag_tiret : %i\n", elem->flag_tiret);
	printf("flag_zero : %i\n", elem->flag_zero);
	i += ft_is_width(&form[i], elem);
	printf("width_asterisque : %i\n", elem->width_asterisque);
	printf("width_digit : %i\n", elem->width_digit);
	i += ft_is_precision(&form[i], ap, elem);
	printf("precision_point : %i\n", elem->precision_point);
	printf("precision_asterisque : %i\n", elem->precision_asterisque);
	i += ft_is_type(&form[i], elem);
	printf("type : %c\n", elem->type);
	ft_what_type(&form[i], elem, ap);
	printf("elem arg : %s\n", elem->arg);
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
	form = (char*)format;
	elem = (t_parsing*)malloc(sizeof(t_parsing));
	if (elem == NULL)
		return (0);
	if (form)
	{
		while (form[i])
		{
			ft_initialize_parsing(elem);
			if (form[i] == '%')
			{
				i++;
				i += ft_complete_parsing(&form[i], elem, &ap);
			}
			else
			{
				ft_putchar(form[i]);
				len = ft_strlen(form);
				i++;
			}
		}
	}
	va_end(ap);
	return (len);
}


int	main(void)
{
	//ft_printf(NULL, 25378);
	//printf("%i\n", 25378);
	printf("%X\n", 176763763);
	printf("%x\n", 176763763);
	printf("%s\n", ft_itoa_base(18, "16"));
	//ft_printf("***************_____hello");
	//printf("====================================================");
	//printf("***************_____hello" "...%%%%%d-677537386");
	return (0);	
}

