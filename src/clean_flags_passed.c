#include "../header/my_ls.h"

void clean_flags_passed(flags **flags_passed)
{
    free((*flags_passed)->dirs_index);
    free((*flags_passed));
}