#include "../incls/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	else
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}
