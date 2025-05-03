/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:04:33 by Jyniemit          #+#    #+#             */
/*   Updated: 2025/04/28 08:43:11 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_array_height(char const *s, char c)
{
	size_t		i;
	size_t		result;

	i = 0;
	result = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			result++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (result);
}

static int	ft_safe_save(char **dest, char const *source, size_t len, int loc)
{
	dest[loc] = malloc(sizeof(char) * len);
	if (!dest[loc])
	{
		while (loc-- > 0)
			free(dest[loc]);
		return (1);
	}
	ft_strlcpy(dest[loc], source, len);
	return (0);
}

static int	ft_save_strings(char **dest, char const *source, char c)
{
	char const	*pos;
	size_t		len;
	int			i;

	pos = source;
	len = 0;
	i = 0;
	while (*pos)
	{
		len = 0;
		while (*pos == c && *pos)
			pos++;
		while (*pos != c && *pos)
		{
			len++;
			pos++;
		}
		if (len > 0 && ft_safe_save(dest, pos - len, len + 1, i))
			return (1);
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	size_t		height;

	res = NULL;
	height = 0;
	if (!s)
		return (NULL);
	height = ft_count_array_height(s, c);
	res = malloc(sizeof(char *) * (height + 1));
	if (!res)
		return (NULL);
	res[height] = NULL;
	if (ft_save_strings(res, s, c))
	{
		free (res);
		return (NULL);
	}
	return (res);
}
