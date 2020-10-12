#ifndef __MY_LS__H
#define __MY_LS_H
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef struct dirent read_entry;
typedef struct stat filestat;
//simple enum to distiguish entries between files and directories
typedef enum enum_f_type
{
    d, f
} f_type;
//check wich flags were passed on as CLI arguments
typedef struct flags_struct
{
    int a;
    int t;
    int dirs;
    char **path;
} flags;
//Node of linked list used to organize entries read and copied (c_entry)
//lexicographic, modified time (-t), dir or file
typedef struct node_entry
{
    struct node_entry *next;
    void *data;
} node_entry;
void my_putchar(char c);
void my_putstr(char *s);
int my_strlen(char *s, int len);
int my_strcmp(const char *s1, const char *s2);
flags *check_args(int ac, char **av, flags **fs);
char *my_strcpy(char *dst, const char *src);
node_entry *create_node(void *data);
void front_insert_node(node_entry **head, read_entry *data);
void place_entry(node_entry **head, read_entry *r_entry, flags *flag, char *dir);
void print_list(node_entry **head);
void insert_node(node_entry **node, read_entry *data);
int is_precedent(read_entry *r_entry, read_entry *node_data, flags *flag, char* dir);
void clean_list(node_entry **head);
char *my_strjoin(char *s1, char *s2);
void clean_flags_passed(flags **flags_passed);
void clear_flags_passed(flags **flags_passed);
#endif