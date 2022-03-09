#include "minitalk.h"

void	ft_delone(t_word *lst)
{
	if (!lst)
		return ;
	free(lst);
}
