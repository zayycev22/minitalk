/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:30:38 by                   #+#    #+#             */
/*   Updated: 2021/10/17 15:30:38 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*a;

	if (!lst)
		return (NULL);
	tmp = ft_lstnew(f(lst->content));
	if (!tmp)
		return (NULL);
	a = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&a, del);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (a);
}
