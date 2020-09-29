#ifndef __MY_LS__H
#define __MY_LS_H
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define TRUE '1'
#define FALSE '0'
//simple enum to distiguish entries between files and directories
typedef enum enum_f_type
{
    d, f
} f_type;
//Copy of file entry read from open directory
typedef struct copy_entry
{
    char *name;
    f_type type;
    time_t mod_time_s;
    time_t mod_time_ns;
} c_entry;
//check wich flags were passed on as CLI arguments
typedef struct flags_struct
{
    char a;
    char t;
} flags;
//Node of linked list used to organize entries read and copied (c_entry)
//lexicographic, modified time (-t), dir or file
typedef struct node_entry
{
    struct node_entry *next;
    c_entry *data;
} node_entry;
void my_putchar(char c);
void my_putstr(char *s);
int my_strlen(char *s, int len);
int my_strcmp(const char *s1, const char *s2);
flags *check_flags(int ac, char **av);
char *my_strcpy(char *dst, const char *src);
c_entry *copy_entry(struct dirent *r_entry, int a_flag);
node_entry *create_node(c_entry *data);
void insert_node(node_entry **head, c_entry *data);
#endif