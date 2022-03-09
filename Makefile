server :
	gcc minitalk.h server.c ft_printf/includes/ft_printf.h ft_printf/*.c ft_printf/libft/*.c new_word.c del_one.c ft_cls_stack.c
	mv a.out server

client :
	gcc minitalk.h client.c ft_printf/includes/ft_printf.h ft_printf/*.c ft_printf/libft/*.c new_word.c
	mv a.out client
