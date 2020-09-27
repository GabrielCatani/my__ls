#include "../header/my_ls.h"

void my_putstr(char *s)
{
    int len;

    len = my_strlen(s, 0);
    write(1, s, len);
}