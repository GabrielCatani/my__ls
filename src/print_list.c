#include "../header/my_ls.h"

void print_list(node_entry **head)
{
    node_entry *node_ptr;

    node_ptr = *head;
    read_entry *node_data;
    while (node_ptr)
    {
        node_data = (read_entry*)node_ptr->data;
        my_putstr(node_data->d_name);
        my_putstr("\n");
        node_ptr = node_ptr->next;
    }
}