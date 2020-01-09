/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:50:53 by edouvier          #+#    #+#             */
/*   Updated: 2019/12/02 11:50:54 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_is_type(char *form, t_parsing *elem)
{
	int 	i;

	i = 0;
	if (form)
		if (form[i] == 'c' || form[i] == 's' ||form[i] == 'p'||form[i] == 'd'|| form[i] == 'i' || form[i] == 'u' || form[i] == 'x' || form[i] == 'X' || form[i] == '%')
		{
			elem->type = form[i];
			i++;
		}
	return (i);
}

void	ft_what_type(t_parsing *elem, va_list *ap)
{
	if (elem->type == 'c')
		elem->arg = ft_char_dup(va_arg(*ap, int));
	else if (elem->type == 's')
		elem->arg = ft_strdup(va_arg(*ap, char*));
	else if (elem->type == '%')
		elem->arg = ft_char_dup('%');
	else if (elem->type == 'p')
		elem->arg = ft_itoa_base_p(va_arg(*ap, unsigned long long int), "0123456789abcdef");
	else if (elem->type == 'd' || elem->type == 'i') 
		elem->arg = ft_itoa(va_arg(*ap, int)); 
	else if (elem->type == 'u')
		elem->arg = ft_itoa_base(va_arg(*ap, unsigned), "0123456789");
	else if (elem->type == 'x')
		elem->arg = ft_itoa_base(va_arg(*ap, unsigned), "0123456789abcdef");
	else if (elem->type == 'X')
		elem->arg = ft_itoa_base(va_arg(*ap, unsigned), "0123456789ABCDEF");
}