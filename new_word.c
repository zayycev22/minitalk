#include "minitalk.h"

t_word	*new(int sig)
{
	t_word	*new_t;

	new_t = (t_word *)malloc(sizeof(t_word));
	if (!new_t)
		return (NULL);
	new_t->sig = sig;
	new_t->pw = -1;
	new_t->next = NULL;
	return (new_t);
}

void	pb(t_word **word, int sig)
{
	t_word	*tmp;
	int		prev;

	if (!(*word))
	{
		*word = new(sig);
		(*word)->pw = 0;
	}
	else
	{
		tmp = *(word);
		while (tmp->next)
		{
			if (tmp->next == NULL)
				prev = tmp->pw;
			tmp = (t_word *) tmp->next;
		}
		tmp->next = (struct t_word *)new(sig);
		tmp = (t_word *) tmp->next;
		tmp->pw = prev++;
	}
}

int	ft_size(t_word *w)
{
	int	n;

	n = 0;
	while (w)
	{
		n++;
		w = w->next;
	}
	return (n);
}
