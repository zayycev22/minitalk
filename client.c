#include "minitalk.h"

int main(int argc, char **argv)
{
    int pid;
    int i;

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        kill(pid, SIGUSR1);
    }
}