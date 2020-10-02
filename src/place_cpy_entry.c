#include "../header/my_ls.h"

void place_cpy_entry(node_entry **head, c_entry *cp_entry, int t_flag)
{
    node_entry **ptr_node;

    ptr_node = head;
    if (!(*ptr_node) || (is_precedent(cp_entry, (*ptr_node)->data, t_flag)))
        front_insert_node(ptr_node, cp_entry);
    else
    {
        while ((*ptr_node))
        {
            if (!(*ptr_node)->next || (is_precedent(cp_entry, (*ptr_node)->next->data, t_flag)))
            {
                insert_node(ptr_node, cp_entry);
                break;
            }
            
            *ptr_node = (*ptr_node)->next;
        }
    }
}