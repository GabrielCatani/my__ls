#include "../header/my_ls.h"

void clean_flags_passed(flags **flags_passed)
{
    int i;

    i = 0;
    while (i < (*flags_passed)->dirs)
    {
        free((*flags_passed)->path[i]);
        i++;
    }
    free((*flags_passed));
}