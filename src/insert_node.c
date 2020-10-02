#include "../header/my_ls.h"

void insert_node(node_entry **node, c_entry *data)
{
    node_entry *ref_ptr;

    ref_ptr = create_node(data);
    ref_ptr->next = (*node)->next;
    (*node)->next = ref_ptr;
}