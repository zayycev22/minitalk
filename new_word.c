#include "minitalk.h"
#include "ft_printf/includes/ft_printf.h"

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

	//ft_printf("pbsig = %d\n", sig);
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
		tmp->pw = prev + 1;
	}
}

int	ft_size(t_word *w)
{
	int	n;

	n = 0;
	while (w)
	{
		n++;
		w = (t_word *) w->next;
	}
	return (n);
}

void	get_d(t_word *a)
{
	char	*c;
	int		size;
	int		i;

	size = ft_size(a);
	i = 0;
	c = NULL;
	while (i < size)
	{
		if (a->sig)
			c = ft_strjoin(c, "1");
		else
			c = ft_strjoin(c, "0");
		i++;
		a = (t_word *) a->next;
	}
	//ft_printf("norm stack rev = %s\n", c);
	free(c);
}
