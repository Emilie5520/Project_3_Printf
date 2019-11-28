/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:33:51 by edouvier          #+#    #+#             */
/*   Updated: 2019/10/21 13:19:15 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupl(const char *s)
{
	int		i;
	int		j;
	int		k;
	char	*dest;
	char	*src;

	i = 0;
	j = 0;
	k = 0;
	src = (char*)s;
	while (src[k] != '\0')
	{
		k++;
	}
	dest = (char *)malloc(sizeof(char) * (k + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		is_malloc(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

void	int_to_str(char *str, int *c, long int *n)
{
	int	num;
	int	count;

	count = *c;
	num = *n;
	while (num > 0)
	{
		str[count - 1] = (num % 10) + '0';
		num = num / 10;
		count--;
	}
	*c = count;
	*n = num;
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long int	num;

	count = 0;
	num = n;
	if (num == -2147483648)
		return (ft_strdupl((const char*)"-2147483648"));
	if (num < 0)
	{
		num = -num;
		count++;
	}
	count = count + is_malloc(num);
	if (!(str = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	str[count] = '\0';
	if (num == 0)
		str[0] = '0';
	int_to_str(str, &count, &num);
	if (count == 1)
		str[0] = '-';
	return (str);
}
