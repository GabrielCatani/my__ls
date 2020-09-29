#include "../header/my_ls.h"

void insert_node(node_entry **head, c_entry *data)
{
    node_entry *ref_ptr;

    if (*head)
    {
        ref_ptr = create_node(data);
        if (ref_ptr)
        {
            ref_ptr->next = *head;
            *head = ref_ptr;
        }
    }
    else
    {
        *head = create_node(data);
    }
}