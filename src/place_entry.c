#include "../header/my_ls.h"

void place_entry(node_entry **head, read_entry *r_entry, flags *flag, char *dir)
{
    node_entry *ptr_node;

    ptr_node = *head;
    if (flag->a == 0 && r_entry->d_name[0] == '.')
    {}
    else if (!(*head) || (is_precedent(r_entry, (*head)->data, flag, dir)))
        front_insert_node(head, r_entry);
    else
    {
        while (ptr_node)
        {
            if (!ptr_node->next || (is_precedent(r_entry, ptr_node->next->data, flag, dir)))
            {
                insert_node(&ptr_node, r_entry);
                break;
            } 
            ptr_node = ptr_node->next;
        }
    }
}