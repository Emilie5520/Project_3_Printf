/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:25:34 by edouvier          #+#    #+#             */
/*   Updated: 2019/11/28 14:25:45 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_parsing
{
	int		flag_tiret;
	int		flag_zero;
	int		width;
	int		precision;
	char	type;
	char	*arg;
}			t_parsing;

int			ft_printf(const char *format, ...);
int			ft_is_width(char *form, va_list *ap, t_parsing *elem);
int			ft_is_flags(char *form, t_parsing *elem);
int			ft_complete_parsing(char *form, t_parsing *elem, va_list *ap);
void		ft_initialize_parsing(t_parsing *elem);
int			ft_is_precision(char *form, va_list *ap, t_parsing *elem);
int			ft_is_type(char *form, t_parsing *elem);
void		ft_putchar(char c);
void		ft_what_type(t_parsing *elem, va_list *ap);
void    	ft_putstr(char *str);
char		*ft_char_dup(char c);
char    	*ft_itoa_base(unsigned nbr, char *base);
char		*ft_itoa_base_p(unsigned long long int nbr, char *base);
void		ft_width(t_parsing *elem);
void		ft_precision_cpdiuxX(t_parsing *elem);
void		ft_precison_s(t_parsing *elem);

#endif
