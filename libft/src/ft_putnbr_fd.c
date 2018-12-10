/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:27:32 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/14 15:37:26 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putn_fd(int n, int fd)
{
	if (n > 9)
		ft_putn_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 2147483647)
	{
		ft_putstr_fd("2147483647", fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	ft_putn_fd(n, fd);
}
