#include "../incls/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list != NULL)
	{
		list->content = content;
		list->next = NULL;
	}
	else
		return (NULL);
	return (list);
}
