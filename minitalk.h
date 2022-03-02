//
// Created by zayycev22 on 02.03.2022.
//

#ifndef MINITALK_H
#define MINITALK_H
# include "ft_printf/includes/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_word
{
	int				sig;
	int				pw;
	struct t_word	*next;
}	t_word;
void	pb(t_word **word, int sig);
t_word	*new(int sig);
int		ft_size(t_word *w);
#endif
