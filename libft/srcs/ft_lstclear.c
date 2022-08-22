#include "../incls/libft.h"

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
