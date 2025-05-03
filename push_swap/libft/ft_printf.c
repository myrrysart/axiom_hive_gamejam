/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:03:31 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/28 14:37:02 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_cases(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i = handle_c(args);
	else if (*format == 's')
		i = handle_s(args);
	else if (*format == 'p')
		i = handle_p(args);
	else if (*format == 'd' || *format == 'i')
		i = handle_d(args);
	else if (*format == 'u')
		i = handle_u(args);
	else if (*format == 'x')
		i = handle_hex_low(args);
	else if (*format == 'X')
		i = handle_hex_up(args);
	else
		return (-1);
	return (i);
}

static int	write_char(char c)
{
	return (write(1, &c, 1));
}

static int	handle_format(const char **format, va_list args)
{
	int	i;

	(*format)++;
	if (**format == '%')
		return (write_char('%'));
	i = handle_cases(*format, args);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			i = handle_format(&format, args);
		else
			i = write_char(*format);
		if (i < 0)
			return (-1);
		count += i;
		format++;
	}
	va_end(args);
	return (count);
}
