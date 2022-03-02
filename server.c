#include "minitalk.h"

static void close_server(int sig)
{
    (void)sig;
    ft_printf("\nServer is closed\n");
    exit(0);
}

int main(int argc, char **argv)
{
    ft_printf("PID: %d\n", getpid());
    ft_printf("signal is %d\n", SIGINT);
    signal(SIGINT, close_server);
    while (1)
        pause();
}