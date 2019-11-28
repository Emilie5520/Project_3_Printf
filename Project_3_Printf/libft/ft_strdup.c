/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:53:16 by edouvier          #+#    #+#             */
/*   Updated: 2019/10/21 10:09:31 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
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
