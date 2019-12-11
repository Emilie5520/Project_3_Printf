#include "../includes/ft_printf.h"

int	ft_is_type(char *form, t_parsing *elem)
{
	int 	i;

	i = 0;
	if (form)
		if (form[i] == 'c' || form[i] == 's' ||form[i] == 'p'||form[i] == 'd'||form[i] == 'i' || form[i] == 'u' || form[i] == 'x' || form[i] == 'X' || form[i] == '%')
		{
			elem->type = form[i];
		}
	return (i);
}

void	ft_what_type(char *form, t_parsing *elem, va_list *ap)
{
	int		i;

	i = 0;
	if (form[i] == 'c')
		elem->arg = ft_char_dup(va_arg(*ap, int));
	if (form[i] == 's')
		elem->arg = ft_strdup(va_arg(*ap, char*));
	if (form[i] == '%')
		elem->arg = ft_char_dup('%');
	if (form[i] == 'd' || form[i] == 'i') 
		elem->arg = ft_itoa(va_arg(*ap, int)); //entier signé + et -
//	if type == 'u') //entier non signé donc uniquement +
//	if (type == 'x')
//	if (type == 'X')
	}