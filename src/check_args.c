#include "../header/my_ls.h"

int check_flags_dir_qty(int ac, char **av, flags **fs)
{
    int i;
    int j;
    int dirs;

    (*fs)->a = 0;
    (*fs)->t = 0;
    i = 1;
    dirs = 0;
    while (i < ac)
    {
        j = 0;
        if (av[i][0] == '-')
        {
            while (av[i][j])
            {
                if (av[i][j] == 'a')
                    (*fs)->a = 1;
                if (av[i][j] == 't')
                    (*fs)->t = 1;    
                j++;
            }
        }
        else
            dirs += 1;
        i++;
    }

    return dirs;
}

void check_dirs(int ac, char **av, flags **fs)
{
    int i;
    int j;

    i = 1;
    j = 0;

    while (i < ac)
    {
        if (av[i][0] != '-')
        {
            (*fs)->dirs_index[j] = i;
            j++;
        }
        i++;
    }
}

void check_args(int ac, char **av, flags **fs) 
{
    (*fs)->dirs = check_flags_dir_qty(ac, av, fs);
    if ((*fs)->dirs)
        (*fs)->dirs_index = (int*)malloc(sizeof(int) * (*fs)->dirs);
    else
        (*fs)->dirs = 1;    

    check_dirs(ac, av, fs);
}