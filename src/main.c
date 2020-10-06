#include "../header/my_ls.h"

int main(int ac, char **av)
{
    DIR *folder;
    read_entry *r_entry;
    flags *flags_passed;
    node_entry *head_cpy_entries;
 
    head_cpy_entries = NULL;
    flags_passed = check_args(ac, av);

    folder = opendir(flags_passed->path);
    if (!folder)
    {
        free(flags_passed->path);
        free(flags_passed);
        return 1;
    }
    while ((r_entry = readdir(folder)))
    {
        place_entry(&head_cpy_entries, r_entry, flags_passed);
    }

    print_list(&head_cpy_entries);
    clean_list(&head_cpy_entries); 
    closedir(folder);
     
    return 0;
 }