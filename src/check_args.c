#include "../header/my_ls.h"

int check_flags_dir_qty(int ac, char **av, flags **fs)
{
    int i;
    int j;
    int dirs;

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
          (*fs)->path[j] = (char*)malloc(sizeof(char) * my_strlen(av[i], 0) + 1);
          my_strcpy((*fs)->path[j], av[i]);
          j++;
        }
        i++;
    }
}

flags *check_args(int ac, char **av, flags **fs) 
{

    (*fs)->dirs = check_flags_dir_qty(ac, av, fs);
    (*fs)->path = (char**)malloc(sizeof(char*) * (*fs)->dirs);
    check_dirs(ac, av, fs);

    return (*fs);
}