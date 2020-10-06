#include "../header/my_ls.h"

node_entry *create_node(void *data)
{
    node_entry *node_ptr;

    node_ptr = (node_entry *)malloc(sizeof(node_entry));
    if (node_ptr)
    {
        node_ptr->data = data;
        node_ptr->next = NULL;
    }
    return node_ptr;
}