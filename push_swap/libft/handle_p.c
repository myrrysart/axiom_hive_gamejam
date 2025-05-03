/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:27:13 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/28 14:38:31 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	handle_p_hex(unsigned long num)
{
	char	str[16];
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (num > 0)
	{
		str[i] = HEXLOW[num % 16];
		num /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &str[i], 1);
		count++;
	}
	return (count);
}

int	handle_p(va_list args)
{
	void			*ptr;
	unsigned long	num;
	int				count;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = 2;
	num = (unsigned long)ptr;
	count += handle_p_hex(num);
	return (count);
}
