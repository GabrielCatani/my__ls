#include "../header/my_ls.h"

void first_cli_arg(int *attr, char **av, char flag)
{
    if (av[1][0] == '-' && av[1][1] == flag)
            *attr = TRUE;
        else if (my_strlen(av[1], 0) > 2)
        {
            if (av[1][0] == '-' && av[1][2] == flag)
                *attr = TRUE;
        }
}

void second_cli_arg(int *attr, char **av, char flag)
{
    if ((my_strlen(av[1], 0) == 2) && (my_strlen(av[2], 0) == 2))
    {
        if (av[1][0] == '-' && av[1][1] == flag)
                *attr = TRUE;
            else if (my_strlen(av[1], 0) > 2)
            {
                if (av[1][0] == '-' && av[1][2] == flag)
                    *attr = TRUE;
            }
        else if (av[2][0] == '-' && av[2][1] == flag)
            *attr = TRUE;
    }
}

flags *check_args(int ac, char **av)
{
    flags *fs;

    fs = (flags *)malloc(sizeof(flags));
    fs->a = FALSE;
    fs->t = FALSE;

    if (ac == 1)
    {
        fs->path = (char*)malloc(sizeof(char) + 1);
        fs->path = my_strcpy(fs->path, ".");
    }
    else if (ac == 2)
    {
        first_cli_arg(&fs->a, av, 'a');
        first_cli_arg(&fs->t, av, 't');
        if (fs->a == FALSE && fs->t == FALSE)
        {
            fs->path = (char*)malloc(sizeof(char) * my_strlen(av[1], 0) + 1);
            fs->path = my_strcpy(fs->path, av[1]);
        }
        else
        {
            fs->path = (char*)malloc(sizeof(char) + 1);
            fs->path = my_strcpy(fs->path, ".");
        }
    }
    else if (ac == 3)
    {
        first_cli_arg(&fs->a, av, 'a');
        first_cli_arg(&fs->t, av, 't');
        if (fs->a == TRUE && fs->t == TRUE)
        {
            fs->path = (char*)malloc(sizeof(char) * my_strlen(av[2], 0) + 1);
            fs->path = my_strcpy(fs->path, av[2]);
        }
        second_cli_arg(&fs->a, av, 'a');
        second_cli_arg(&fs->t, av, 't');
        if (fs->a == FALSE || fs->t == FALSE)
        {
            fs->path = (char*)malloc(sizeof(char) * my_strlen(av[2], 0) + 1);
            fs->path = my_strcpy(fs->path, av[2]);
        }
        else
        {
            fs->path = (char*)malloc(sizeof(char) + 1);
            fs->path = my_strcpy(fs->path, ".");
        }
    }
    else if (ac == 4)
    {
        first_cli_arg(&fs->a, av, 'a');
        first_cli_arg(&fs->t, av, 't');
        second_cli_arg(&fs->a, av, 'a');
        second_cli_arg(&fs->t, av, 't');
        fs->path = (char*)malloc(sizeof(char) * my_strlen(av[3], 0) + 1);
        fs->path = my_strcpy(fs->path, av[3]);
    }
    
    return fs;
}