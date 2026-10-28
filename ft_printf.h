/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arcamart <arcamart@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/19 14:59:20 by arcamart      #+#    #+#                 */
/*   Updated: 2026/10/28 18:00:26 by arcamart      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
// # include <stdlib.h>
// # include <stdint.h>
// # include <stdio.h>

int		ft_printf(const char	*format, ...);
int		write_c(char c);
int		write_s(char *s);
int		write_n(int nb);
int		write_unsigned(unsigned long n, char c);
int		write_p(void *p);

#endif