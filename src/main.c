#include "../header/my_ls.h"

int main(int ac, char **av)
{
    DIR *folder;
    struct dirent *r_entry;
    flags *flags_passed;
    c_entry *cp_entry;
    node_entry *head_cpy_entries;

    head_cpy_entries = NULL;
    flags_passed = check_args(ac, av);
    if (flags_passed->file) 
        folder = opendir(flags_passed->file);
    else
        folder = opendir(".");
    while ((r_entry = readdir(folder)))
    {
        cp_entry = copy_entry(r_entry, flags_passed->a);
        if (cp_entry)
            place_cpy_entry(&head_cpy_entries, cp_entry, flags_passed->t);
    }

    print_cpy_list(&head_cpy_entries);
    
    closedir(folder);
    
    return 0;
}