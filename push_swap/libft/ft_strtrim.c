/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:04:06 by Jyniemit          #+#    #+#             */
/*   Updated: 2024/11/11 13:04:20 by Jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setcheck(char const *s1, char const *set)
{
	int	found;

	found = 0;
	while (*set)
	{
		if (*set == *s1)
		{
			found = 1;
			return (found);
		}
		set++;
	}
	return (found);
}

static char const	*ft_strcheckset(char const *s1, char const *set)
{
	while (ft_setcheck(s1, set))
		s1++;
	return (s1);
}

static char const	*ft_strchecksetrev(char const *s1,
									char const *s2, char const *set)
{
	while (ft_setcheck(s1, set) && s1 > s2)
		s1--;
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*res;
	size_t		res_len;

	res = NULL;
	res_len = 0;
	if (!s1 || !set)
		return (NULL);
	start = ft_strcheckset(s1, set);
	end = ft_strchecksetrev(&s1[ft_strlen(s1) - 1], start, set);
	while (&start[res_len] <= end)
		res_len++;
	res = ft_calloc(res_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, start, res_len + 1);
	return (res);
}
