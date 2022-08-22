#include "../incls/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	l = ft_lstnew(f(lst->content));
	if (l == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&l, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&l, new);
	}
	return (l);
}
