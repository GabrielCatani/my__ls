#include "../header/my_ls.h"

void print_cpy_list(node_entry **head)
{
    node_entry *node_ptr;

    node_ptr = *head;
    while (node_ptr)
    {
        my_putstr(node_ptr->data->name);
        my_putstr("\n");
        node_ptr = node_ptr->next;
    }
}