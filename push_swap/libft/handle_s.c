/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:26:29 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/28 14:38:31 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	handle_s(va_list args)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
