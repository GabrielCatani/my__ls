#include "../header/my_ls.h"

int my_strcmp(const char *s1, const char *s2)
{
	int i;
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	i = 0;
	while (ptr1[i] != '\0' && ptr2[i] != '\0' && ptr1[i] == ptr2[i])
		i++;

	return (ptr1[i] - ptr2[i]);
}