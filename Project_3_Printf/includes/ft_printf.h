/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:36:16 by edouvier          #+#    #+#             */
/*   Updated: 2019/11/26 14:40:45 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <../libft/libft.h>

typedef struct      s_parsing
{
    int     flag_tiret;
    int     flag_zero;
    int     width_aterisque;
    int     precision_point;
    int     size;
    int     type;
    int     params; // stocker l'argument 
}       t_parsing;

int     ft_printf(const char *format, ...);

#endif