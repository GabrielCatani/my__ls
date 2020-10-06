#include "../header/my_ls.h"

void clean_list(node_entry **head)
{
    node_entry *ptr;
    node_entry *tmp;

    ptr = (*head);
    if (ptr)
    {
        while (ptr->next)
        {
            tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }
    (*head) = NULL;
    free(ptr);
}