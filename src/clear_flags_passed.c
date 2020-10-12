#include "../header/my_ls.h"

void clear_flags_passed(flags **flags_passed)
{
    int i;

    i = 0;
    while (i < (*flags_passed)->dirs)
    {
       (*flags_passed)->path[i] = NULL;
        i++;
    }
}