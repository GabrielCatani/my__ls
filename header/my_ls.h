#ifndef __MY_LS__H
#define __MY_LS_H
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#define TRUE '1'
#define FALSE '0'
typedef enum enum_f_type
{
    d, f;
} f_type;
typedef struct node_entry
{
    char *name;
    f_type type;
    time_t mod_time;
    struct node_entry *next;
} entry;
typedef struct flags_struct
{
    char a;
    char t;
} flags;
void my_putchar(char c);
void my_putstr(char *s);
int my_strlen(char *s, int len);
int my_strcmp(const char *s1, const char *s2);
flags *check_flags(int ac, char **av);
#endif