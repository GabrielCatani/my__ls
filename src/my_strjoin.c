#include "../header/my_ls.h"

char *my_strjoin(char *s1, char *s2)
{
    char *str;
    int i;

    if (!s1 | !s2)
     return NULL;

    str = (char *)malloc(sizeof(char) * (my_strlen(s1, 0) + my_strlen(s2, 0) + 1));
    if (!str)
        return NULL;
    i = 0;
    while (*s1 != '\0')
        str[i++] = *s1++;
    
    while (*s2 != '\0')
        str[i++] = *s2++;

    str[i] = '\0';
    return str;   
}