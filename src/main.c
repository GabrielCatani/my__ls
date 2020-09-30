#include "../header/my_ls.h"

int main(int ac, char **av)
{
    DIR *folder;
    struct dirent *r_entry;
    flags *flags_passed;
    c_entry *cp_entry;
    node_entry *head_cpy_entries;

    head_cpy_entries = NULL;
    flags_passed = check_flags(ac, av);
    if (flags_passed->file) 
        folder = opendir(flags_passed->file);
    else
        folder = opendir(".");
    while ((r_entry = readdir(folder)))
    {
        if (!head_cpy_entries)
        {
            cp_entry = copy_entry(r_entry, flags_passed->a);
            head_cpy_entries = create_node(cp_entry);
        }
        else
        {
            //place_cpy_entry(head_cpy_entries, cp_entry, flags_passed->t);
        }
    }
    
    printf("%s\n", head_cpy_entries->data->name);
    closedir(folder);
    
    return 0;
}