/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:41:07 by Jyniemit          #+#    #+#             */
/*   Updated: 2024/11/11 12:41:11 by Jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*res;
	unsigned char	*source;

	res = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (n && !res && !source)
		return (dst);
	while (n > 0)
	{
		*(res++) = *(source++);
		n--;
	}
	return (dst);
}
