/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:55:35 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/23 21:37:14 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	len = 0;
	while (s[len])
	{
		dup[len] = s[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

static size_t	str_fill(char *dest, char *src, size_t start_i)
{
	size_t	i;

	i = 0;
	while (src && src[i])
	{
		dest[start_i + i] = src[i];
		i++;
	}
	return (i);
}

char	*concat_buffer_to_remains(char *remains, char *buffer)
{
	char	*joined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (remains && remains[i])
		i++;
	while (buffer && buffer[j])
		j++;
	joined = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!joined)
	{
		free(remains);
		return (NULL);
	}
	i = 0;
	i = str_fill(joined, remains, i);
	j = 0;
	j = str_fill(joined, buffer, i);
	joined[i + j] = '\0';
	if (remains)
		free(remains);
	return (joined);
}
