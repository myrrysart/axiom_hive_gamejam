/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:03:06 by Jyniemit          #+#    #+#             */
/*   Updated: 2024/11/11 13:03:18 by Jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	total_len;

	if (!s)
		return (NULL);
	total_len = ft_strlen(s);
	s_len = total_len - start;
	if (start >= total_len)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[0] = 0;
		return (res);
	}
	if (s_len < len)
		len = s_len;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_memmove(res, &s[start], len);
	res[len] = '\0';
	return (res);
}
