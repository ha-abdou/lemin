/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:45:42 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/20 11:45:45 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstdelone(t_list **link, void (*del)(void *, size_t))
{
	del((*link)->content, (*link)->content_size);
	ft_memdel((void *)link);
}
