#include "../header/my_ls.h"

int is_time_precedent(filestat f_stat, read_entry *node_data, char *path)
{
    time_t copy_sec;
    time_t node_sec;
    time_t copy_nano;
    time_t node_nano;
    filestat n_stat;
    char *full_path;

    full_path = my_strjoin(path, (char*)node_data->d_name);
    if (DT_LNK == node_data->d_type)
        lstat(full_path, &n_stat);
    else
        stat(full_path, &n_stat);

    copy_sec = f_stat.st_mtim.tv_sec;
    node_sec = n_stat.st_mtim.tv_sec;
    copy_nano = f_stat.st_mtim.tv_nsec;
    node_nano = n_stat.st_mtim.tv_nsec;
    free(full_path);
    if (copy_sec == node_sec)
    {
        if (copy_nano <= node_nano)
        {
            return TRUE;
        }
    }
    else if (copy_sec < node_nano)
    {
        return TRUE;
    }

    return FALSE;
}

int is_precedent(read_entry *r_entry, read_entry *node_data, flags *flag)
{
    int check;
    filestat f_stat;
    f_type e_type;
    f_type n_type;
    char *path;
    char *full_path;

    check = FALSE;
    path = my_strjoin(flag->path, "/");
    full_path = my_strjoin(path, r_entry->d_name);
    n_type = (int)node_data->d_type;
    if (DT_LNK == r_entry->d_type)
        lstat(full_path, &f_stat);
    else
        stat(full_path, &f_stat);
    
    if(S_ISDIR(f_stat.st_mode) || (DT_DIR == r_entry->d_type))
        e_type = d;
    else
        e_type = f;
    if((DT_DIR == node_data->d_type))
        n_type = d;
    else
        n_type = f;
    free(full_path);
    
    if (e_type == n_type)
    {
        if (flag->t)
        {
            check = is_time_precedent(f_stat, node_data, path);
            free(path);
            if (check == TRUE)
                return TRUE;
            else
                return FALSE;
        }
        else
        {
            free(path);
            if ((my_strcmp(r_entry->d_name, (char*)node_data->d_name)) <= 0)
                return TRUE;
            else
                return FALSE;
        }
    }
    else if (e_type == 1 && n_type == 0)
    {
        free(path);
        return TRUE;
    }

    free(path);
    return FALSE;
}