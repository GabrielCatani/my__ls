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
    check_args(ac, av, &flags_passed);
    i = 0;
    while (i < flags_passed->dirs)
    {
        folder = opendir(flags_passed->path[i]);
        if (!folder)
        {
            clean_flags_passed(&flags_passed);
            return 1;
        }
        while ((r_entry = readdir(folder)))
        {
            place_entry(&head_cpy_entries, r_entry, flags_passed, flags_passed->path[i]);
        }
        clear_flags_passed(&flags_passed); 
        print_list(&head_cpy_entries);
        clean_list(&head_cpy_entries); 
        closedir(folder);
        i++;
    }

    clean_flags_passed(&flags_passed);     
    return 0;
 }