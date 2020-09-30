#include "../header/my_ls.h"

void place_cpy_entry(node_entry **head, c_entry cp_entry, int t_flag)
{
    node_entry *ptr_node;

    ptr_node = *head;

    while (ptr_node)
    {
        if (cp_entry.type == d && cp_entry.type != ptr_node->data->type)
            ptr_node = ptr_node->next;
        else if (cp_entry.type == d && cp_entry.type == ptr_node->data->type)
        {
            if (my_strcmp(cp_entry.name, ptr_node->data->name) <= 0)
            {
                insert_node(head, &cp_entry);
                break;
            }
            else
            {
                ptr_node = ptr_node->next;
            }
        }
    }
}