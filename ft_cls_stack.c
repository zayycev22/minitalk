#include "minitalk.h"

void	ft_cls_stack(t_word **lst)
{
	t_word	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (t_word *) tmp->next;
		ft_delone(tmp);
	}
	*lst = NULL;
}
