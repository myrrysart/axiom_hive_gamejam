/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:45:26 by Jyniemit          #+#    #+#             */
/*   Updated: 2024/11/11 16:41:48 by Jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -(n);
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_intmin_handler(int n)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = ft_getlen(n / 10) + 1;
	i = len - 1;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[0] = '-';
	res[len] = '\0';
	while (i > 0)
	{
		res[i] = -(n % 10) + 48;
		n /= 10;
		i--;
	}
	return (res);
}

static char	*ft_int_parser(char *dest, int n, int len)
{
	int	offset;

	offset = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	if (n < 0)
	{
		dest[offset++] = '-';
		n *= -1;
	}
	dest[len] = '\0';
	while (--len >= offset)
	{
		dest[len] = n % 10 + 48;
		n /= 10;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	res = NULL;
	if (n == INT_MIN)
	{
		res = ft_intmin_handler(n);
		if (!res)
			return (NULL);
		return (res);
	}
	if (n == 0)
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	len = ft_getlen(n);
	res = ft_int_parser(res, n, len);
	return (res);
}
