/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:23:22 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/28 14:38:31 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	handle_hex_up(va_list args)
{
	char			str[16];
	int				i;
	unsigned int	num;
	int				count;

	i = 0;
	count = 0;
	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num > 0)
	{
		str[i] = HEXHIGH[num % 16];
		num /= 16;
		i++;
	}
	while (i-- > 0)
	{
		write(1, &str[i], 1);
		count++;
	}
	return (count);
}
