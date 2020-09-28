#include "../header/my_ls.h"

int main(int ac, char **av)
{
    DIR *folder;
    struct dirent *r_entry;
    flags *flags_passed;
    c_entry *cp_entry;
    node_entry *head_cpy_entries;

    flags_passed = check_flags(ac, av);
    folder = opendir("./test_dir");
    r_entry = readdir(folder);    
    cp_entry = copy_entry(r_entry);
    head_cpy_entries = create_node(cp_entry);
    //append_entry(&head_cpy_entries, cp_entry);
    printf("%s\n", head_cpy_entries->data->name);

    return 0;
}