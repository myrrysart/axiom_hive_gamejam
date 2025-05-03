/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:08:24 by Jyniemit          #+#    #+#             */
/*   Updated: 2024/12/02 10:22:44 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_recursive_putnbr_helper(int n, int fd)
{
	if (n == 0)
		return ;
	if (n == INT_MIN)
	{
		write(fd, "-", 1);
		ft_recursive_putnbr_helper(-(n / 10), fd);
		n = -(n % 10) + 48;
		write(fd, &n, 1);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n *= -1;
	}
	ft_recursive_putnbr_helper(n / 10, fd);
	if (n > 9)
		n = n % 10 + 48;
	else
		n += 48;
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	ft_recursive_putnbr_helper(n, fd);
}
