/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:19:07 by edouvier          #+#    #+#             */
/*   Updated: 2020/01/07 13:19:14 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

char	*ft_itoa_base(unsigned nbr, char *base)
{
	char	*str;
	int		i;
	int		n;
	int 	basesize;

	i = 0;
	basesize = ft_strlen(base);
	n = nbr;
	while ((n = n / basesize) >= 1)
		i++;
	i += 1;
	if (!(str = (char *)ft_calloc(sizeof(char), (i + 1))))
		return (NULL);
	while (i--)
	{
		str[i] = base[nbr % basesize];
		nbr = nbr / basesize;
	}
	return (str);
}

char	*ft_itoa_base_p(unsigned long long int nbr, char *base)
{
	char						*str;
	int							i;
	unsigned long long int		n;
	int							basesize;
	char	*tmp;

	i = 0;
	basesize = ft_strlen(base);
	n = nbr;
	while ((n /= basesize) >= 1)
		i++;
	i += 1;
	if (!(str = (char *)ft_calloc(sizeof(char), (i + 1))))
		return (NULL);
	while (i--)
	{
		str[i] = base[nbr % basesize];
		nbr /= basesize;
	}
	tmp = ft_strjoin("0x", str);
	free(str);
	return (tmp);
}
