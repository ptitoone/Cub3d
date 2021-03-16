/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:21:30 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/24 13:21:56 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ls;
	t_list	*tmp;

	ls = *lst;
	while (ls)
	{
		tmp = ls->next;
		del(ls->content);
		free(ls);
		ls = tmp;
	}
	*lst = NULL;
}
