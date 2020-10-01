#include "../header/my_ls.h"

void place_cpy_entry(node_entry **head, c_entry *cp_entry, int t_flag)
{
    node_entry **ptr_node;

    ptr_node = head;
    if (!(*ptr_node))
    {
        front_insert_node(ptr_node, cp_entry);
    }
    /*
    else
    {
        while((*ptr_node))
        {
            printf("%s\n", (*ptr_node)->data->name);
            if (cp_entry->type && (*ptr_node)->data->type)
            {
                if (my_strcmp(cp_entry->name, (*ptr_node)->data->name) <= 0)
                {
                    insert_node(ptr_node, cp_entry);
                    break;
                }
            }
            else if (!cp_entry->type && !(*ptr_node)->data->type)
            {
                if (my_strcmp(cp_entry->name, (*ptr_node)->data->name) <= 0)
                {
                    insert_node(ptr_node, cp_entry);
                    break;
                }
            }
            else if (cp_entry->type && !(*ptr_node)->data->type)
            {
                insert_node(ptr_node, cp_entry);
                break;
            }
            (*ptr_node) = (*ptr_node)->next;
        }
    }
    */   
}