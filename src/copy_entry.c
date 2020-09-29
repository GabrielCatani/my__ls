#include "../header/my_ls.h"

c_entry *copy_entry(struct dirent *r_entry, int a_flag)
{
    c_entry *cp_entry;
    struct stat filestat;

    cp_entry = (c_entry *)malloc(sizeof(cp_entry));
    if(!cp_entry)
        return NULL;
    
    if(a_flag == 0 && r_entry->d_name[0] == '.')
    {
        free(r_entry);
        free(cp_entry);
        return NULL;
    }

    //Copies name of the file entry (r_entry) to cp_entry
    cp_entry->name = (char *)malloc(sizeof(char) * my_strlen(r_entry->d_name, 0) + 1);
    cp_entry->name = my_strcpy(cp_entry->name, r_entry->d_name);
    
    //Save file status to filestat, and copies necessary info. to cp_entry
    // (file type, modification time - sec and nano sec.)
    stat(r_entry->d_name, &filestat);
    if(S_ISDIR(filestat.st_mode))
        cp_entry->type = d;
    else
        cp_entry->type = f;
    
    cp_entry->mod_time_s = filestat.st_mtim.tv_sec;
    cp_entry->mod_time_ns = filestat.st_mtim.tv_nsec;
    
    return cp_entry;
}