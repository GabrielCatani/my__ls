#include "../header/my_ls.h"

void insert_node(node_entry **node, read_entry *data)
{
    node_entry *ref_ptr;

    ref_ptr = create_node(data);
    if ((*node)->next)
        ref_ptr->next = (*node)->next;
    (*node)->next = ref_ptr;
}