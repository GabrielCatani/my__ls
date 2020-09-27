#include "my_ls.h"
#include <stdio.h>

void first_cli_arg(char *attr, char **av, char flag)
{
    if (av[1][1] == flag)
            *attr = flag;
        else if (my_strlen(av[1], 0) > 2)
        {
            if (av[1][2] == flag)
                *attr = flag;
        }
}

void second_cli_arg(char *attr, char **av, char flag)
{
    if (av[1][1] == flag)
            *attr = flag;
        else if (my_strlen(av[1], 0) > 2)
        {
            if (av[1][2] == flag)
                *attr = flag;
        }
    else if (av[2][1] == flag)
        *attr = flag;
}

flags *check_flags(int ac, char **av)
{
    flags *fs;

    fs = (flags *)malloc(sizeof(flags));
    fs->a = FALSE;
    fs->t = FALSE;

    if (ac == 2)
    {
        first_cli_arg(&fs->a, av, 'a');
        first_cli_arg(&fs->t, av, 't');
    }
    else if (ac == 3)
    {
        second_cli_arg(&fs->a, av, 'a');
        second_cli_arg(&fs->t, av, 't');
    }
    
    return fs;
}