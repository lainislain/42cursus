#include "minitalk.h"

char    ft_bitoi(char *tab)
{
    // TO DO:
}

void    ft_print(pid_t SIGUSR)
{
    static char tab[8];
    static int  i = 0;
    char    c;

    if (SIGUSR1 == SIGUSR)
        tab[i] = '0';
    if (SIGUSR2 == SIGUSR)
        tab[i] = '1';
    if (i == 8)
    {
        c = ft_bitoi(tab);
        printf("%c", (char)c);
        i = 0;
    }
}

int main()
{
    pid_t    pid;

    pid = getpid();
    printf("%d\n", pid);
    signal(SIGUSR1, ft_print);
    signal(SIGUSR2, ft_print);
    while (1)
        pause();
}