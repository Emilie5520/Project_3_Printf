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
# include "../libft/libft.h"

typedef struct      s_parsing
{
    int     flag_tiret;
    int     flag_zero;
    int     width_asterisque;
    int	    width_digit;
    int     precision_point;
    int	    precision_asterisque;
    char     type;
    char    *arg; //stocker l'argument 
}       t_parsing;

int     ft_printf(const char *format, ...);
int		ft_is_width(char *form, t_parsing *elem);
int		ft_is_flags(char *form, t_parsing *elem);
int		ft_complete_parsing(char *form, t_parsing *elem, va_list *ap);
void	ft_initialize_parsing(t_parsing *elem);
int		ft_is_precision(char *form, va_list *ap, t_parsing *elem);
int		ft_is_type(char *form, t_parsing *elem);
void    ft_putchar(char c);
void	ft_what_type(char *form, t_parsing *elem, va_list *ap);
void    ft_putstr(char *str);
char	*ft_char_dup(char c);
char    *ft_itoa_base(int nbr, char *base);

#endif
