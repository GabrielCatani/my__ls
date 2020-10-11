#include "../header/my_ls.h"

int is_time_precedent(filestat f_stat, read_entry *node_data, char *path)
{
    unsigned long copy_sec;
    unsigned long node_sec;
    unsigned long copy_nano;
    unsigned long node_nano;
    filestat n_stat;
    char *full_path;

    full_path = my_strjoin(path, (char*)node_data->d_name);
    if (DT_LNK == node_data->d_type)
        lstat(full_path, &n_stat);
    else
        stat(full_path, &n_stat);

    copy_sec = (unsigned long)f_stat.st_mtim.tv_sec;
    node_sec = (unsigned long)n_stat.st_mtim.tv_sec;
    copy_nano = (unsigned long)f_stat.st_mtim.tv_nsec;
    node_nano = (unsigned long)n_stat.st_mtim.tv_nsec;
    
    free(full_path);
    if (copy_sec == node_sec)
    {
        if (copy_nano <= node_nano)
        {
            return FALSE;
        }
    }
    else if (copy_sec < node_sec)
    {
        return FALSE;
    }
    return TRUE;
}

int is_precedent(read_entry *r_entry, read_entry *node_data, flags *flag)
{
    int check;
    filestat f_stat;
    char *path;
    char *full_path;

    check = FALSE;
    path = my_strjoin(flag->path, "/");
    full_path = my_strjoin(path, r_entry->d_name);
    if (DT_LNK == r_entry->d_type)
        lstat(full_path, &f_stat);
    else
        stat(full_path, &f_stat);
    
    free(full_path);
    if (flag->t)
    {
        printf("%s\n", r_entry->d_name);
        check = is_time_precedent(f_stat, node_data, path);
        free(path);
        return check;
    }
    else if ((r_entry->d_type == node_data->d_type) || (r_entry->d_type != DT_DIR && node_data->d_type != DT_DIR))
    {
        free(path);
        if ((my_strcmp(r_entry->d_name, (char*)node_data->d_name)) <= 0)
            return TRUE;
        else
            return FALSE;
    }
    else if (r_entry->d_type != DT_DIR && node_data->d_type == DT_DIR)
    {
        free(path);
        return TRUE;
    }

    free(path);
    return FALSE;
}