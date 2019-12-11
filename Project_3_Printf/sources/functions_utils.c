/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:28:54 by edouvier          #+#    #+#             */
/*   Updated: 2019/11/28 14:29:03 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

char	*ft_char_dup(char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!c)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	str[i] = c;
	i++;
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		i;
	char	*str;
	int		basesize;

	i = 0;
	basesize = ft_strlen(base);
	while ((nbr = nbr / basesize) >= 1)
		i++;
	i = i + 1;
	str = (char	*)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	while (i--)
	{
		str[i] = base[nbr % basesize];
		nbr = nbr / basesize;
	}
	return (str);
}