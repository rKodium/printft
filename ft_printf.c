/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arcamart <arcamart@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/19 14:55:37 by arcamart      #+#    #+#                 */
/*   Updated: 2026/10/28 17:07:26 by arcamart      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	is_spec(char c)
{
	unsigned int	i;
	char			*specs;

	specs = "cspdiuxX%";
	i = 0;
	while (specs[i])
	{
		if (specs[i] == c)
			return (specs[i]);
		i++;
	}
	return (0);
}

static int	handle_spec(char c, va_list *ap)
{
	if (c == '%')
		return (write_c('%'));
	if (c == 'c')
		return (write_c(va_arg(*ap, int)));
	if (c == 's')
		return (write_s(va_arg(*ap, char *)));
	if (c == 'd' || c == 'i')
		return (write_n(va_arg(*ap, int)));
	if (c == 'u' || c == 'x' || c == 'X')
		return (write_unsigned(va_arg(*ap, unsigned int), c));
	if (c == 'p')
		return (write_p(va_arg(*ap, void *)));
	return (0);
}

int	ft_printf(const char	*format, ...)
{
	va_list	ap;
	size_t	i;
	int		c_count;

	c_count = 0;
	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ((is_spec(format[i + 1])) != 0))
		{
			c_count += handle_spec(is_spec(format[i + 1]), &ap);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			c_count++;
		}
		i++;
	}
	va_end(ap);
	return (c_count);
}
