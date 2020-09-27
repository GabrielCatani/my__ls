#include "../header/my_ls.h"

int my_strlen(char *s, int len)
{
    if (*s != '\0')
    {
        return my_strlen(++s, ++len);
    }
    else
    {
        return len;
    }
}