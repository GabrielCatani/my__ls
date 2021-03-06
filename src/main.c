#include "../header/my_ls.h"

int main(int ac, char **av)
{
    DIR *folder;
    read_entry *r_entry;
    flags *flags_passed;
    node_entry *head_cpy_entries;
    int i;

    head_cpy_entries = NULL;
    flags_passed = (flags*)malloc(sizeof(flags));
    flags_passed->dirs_index = NULL;
    check_args(ac, av, &flags_passed);
    i = 0;
    while (i < flags_passed->dirs)
    {
        if (!(flags_passed->dirs_index))
            folder = opendir(".");
        else    
            folder = opendir(av[flags_passed->dirs_index[i]]);
        if (!folder)
        {
            my_putstr("my_ls: cannot access '");
            my_putstr(av[flags_passed->dirs_index[i]]);
            my_putstr("': No such file or directory");
            clean_flags_passed(&flags_passed);
            return 1;
        }
        while ((r_entry = readdir(folder)))
        {
            if (!(flags_passed->dirs_index))
                place_entry(&head_cpy_entries, r_entry, flags_passed, ".");
            else
                place_entry(&head_cpy_entries, r_entry, flags_passed, av[flags_passed->dirs_index[i]]);
        }
        if (flags_passed->dirs > 1)
        {
            my_putstr(av[flags_passed->dirs_index[i]]);
            my_putstr(":\n");
        }
        print_list(&head_cpy_entries);
        clean_list(&head_cpy_entries); 
        closedir(folder);
        i++;
        if (i < flags_passed->dirs)
            my_putstr("\n");
    }
    clean_flags_passed(&flags_passed);     
    return 0;
 }