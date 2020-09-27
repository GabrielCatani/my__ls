#include "../header/my_ls.h"
#include <stdio.h>

int main(int ac, char **av)
{
    //DIR *folder;
    //struct dirent *entry;
    //struct stat filestat;
    flags *flags_passed;
    flags_passed = check_flags(ac, av);

    
    printf("%c\n", flags_passed->t);
    return 0;
}