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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

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

char	*ft_char_join(char const *s1, char s2)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = s2;
	str[i] = '\0';
	return (str);
}