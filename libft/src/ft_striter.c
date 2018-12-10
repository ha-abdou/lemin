/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:46:31 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/13 12:49:46 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *str, void (*f)(char *))
{
	if (!str || !f)
		return ;
	while (*str)
	{
		f(str);
		str++;
	}
}