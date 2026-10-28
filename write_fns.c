/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_fns.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arcamart <arcamart@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/24 15:09:37 by arcamart      #+#    #+#                 */
/*   Updated: 2026/10/28 14:10:46 by arcamart      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	write_s(char *s)
{
	size_t	i;

	if (s == NULL)
		s = "(null)";
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	write_n(int nb)
{
	char	c;
	long	n;
	int		count;

	n = nb;
	count = 0;
	if (n < 0)
	{
		count += write_c('-');
		n = -n;
	}
	if (n >= 10)
		count += write_n(n / 10);
	c = (n % 10) + '0';
	count += write_c(c);
	return (count);
}

int	write_unsigned(unsigned long n, char c)
{
	char			result[21];
	char			*characters;
	unsigned int	len;
	unsigned int	base;

	len = 20;
	if (c == 'u')
		base = 10;
	else
		base = 16;
	characters = "0123456789abcdef";
	if (c == 'X')
		characters = "0123456789ABCDEF";
	result[len] = '\0';
	if (n == 0)
		result[--len] = '0';
	while (n > 0)
	{
		result[len - 1] = characters[n % base];
		n = n / base;
		len--;
	}
	return (write_s(result + len));
}

int	write_p(void *p)
{
	if (p == NULL)
		return (write_s("(nil)"));
	write(1, "0x", 2);
	return (write_unsigned((unsigned long) p, 'x') + 2);
}
