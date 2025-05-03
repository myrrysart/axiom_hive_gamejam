/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:00:33 by Jyniemit          #+#    #+#             */
/*   Updated: 2024/11/11 13:00:36 by Jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	dup = NULL;
	len = ft_strlen(s1) + 1;
	if (!len)
		return (NULL);
	dup = ft_calloc(len, sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, len);
	return (dup);
}
