#include "../header/my_ls.h"

int is_time_precedent(c_entry *cp_entry, c_entry *node_data)
{
    time_t copy_sec;
    time_t node_sec;
    time_t copy_nano;
    time_t node_nano;

    copy_sec = cp_entry->mod_time_s;
    node_sec = node_data->mod_time_s;
    copy_nano = cp_entry->mod_time_ns;
    node_nano = node_data->mod_time_ns;
    if (copy_sec == node_sec)
    {
        if (copy_nano <= node_nano)
        {
            return TRUE;
        }
        else if (copy_nano == node_nano)
            return EQUAL;
    }
    else if (copy_sec < node_nano)
    {
        return TRUE;
    }

    return FALSE;
}

int is_precedent(c_entry *cp_entry, c_entry *node_data, int t_flag)
{
    int check;

    check = FALSE;
    if (cp_entry->type == node_data->type)
    {
        if (t_flag)
        {
            check = is_time_precedent(cp_entry, node_data);
            if (check == TRUE)
                return TRUE;
            else if (check == FALSE)
                return FALSE;
        }
        else if (check == EQUAL || !t_flag)
        {
            if ((my_strcmp(cp_entry->name, node_data->name)) <= 0)
                return TRUE;
            else
                return FALSE;
        }
    }
    else if (cp_entry->type && !(node_data->type))
    {
        return TRUE;
    }

    return FALSE;
}