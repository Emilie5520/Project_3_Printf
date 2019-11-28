/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:21:10 by edouvier          #+#    #+#             */
/*   Updated: 2019/11/26 14:34:35 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_initialize_parsing(t_parsing *elem)
{
	elem.flag_tiret = 0;
	elem.flag_zero = 0;
	elem.width_asterisque = 0;
	elem.precision_point = 0;
	//elem.size = 0;
	//elem.type = 0;
	//elem.params = 0;
}

void	ft_complete_parsing() // remplir les elements de ma structure

int		ft_is_flags(char *form, t_parsing *elem) // recupère l'adresse de form
{
	int		i;

	i = 0;
	while (form)
	{
		while (form[i] == '-' || form[i] == '0' || form[i] == '*' || form[i] == '.')
		{
			if (form[i] == '-')
				elem->flag_tiret = 1;
			if (form[i] == '0' && elem->flag_tiret != 1)
				elem->flag_zero = 1;
			if (elem->flag_tiret == 1)
				elem->flag_zero = 0;
			i++;
		}
	}
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
	form = (char*)format; // on travaille avec form et non format 
	va_start(ap, form);
	elem = (t_parsing*)malloc(sizeof(t_parsing)); // malloc pour stocker les infos dans ma structure 
	if (elem == NULL)
		return (NULL);
	while (form)
	{
		if (form[i] == '%')
		{
			ft_initialize(elem);
			i++;
			form = ft_complete_parsing();
		}
		else 
		{
			ft_putchar(form[i]);
			len = ft_strlen(form);
			i++;
		}
	}
	return (len);
}
