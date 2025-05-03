/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:41:32 by Jyniemit          #+#    #+#             */
/*   Updated: 2024/11/11 12:41:47 by Jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*res;

	i = 0;
	source = (unsigned char *)src;
	res = (unsigned char *)dst;
	if (len && !source && !res)
		return (NULL);
	if (res > source)
	{
		while (len - i++ > 0)
			res[len - i] = source[len - i];
	}
	else
	{
		while (i < len)
		{
			res[i] = source[i];
			i++;
		}
	}
	return (res);
}
