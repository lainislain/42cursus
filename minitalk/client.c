#include "minitalk.h"

char *ft_intobi(char c)
{
    // TO DO:
}

int main(int argc, char **argv)
{
    int   i;
    char    *str;
    int pid;

    pid = ft_atoi(argv[1]);
    i = 0;
    str = ft_intobi(argv[2]);
    while (str[i] != '\0')
    {
        if (str[i] == '0')
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i++;
    }
}