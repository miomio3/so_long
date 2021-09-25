#ifndef IKIMONO_H_
#define IKIMONO_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./minilibx-linux/mlx.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define ERROR   -1
#define NOERROR 1

typedef struct  s_vars
{
    void    *mlx;
    void    *win;
}               t_vars;

typedef struct  s_data
{
    char    **map;
    int     kiyoe_version[2];
    int     leader_version[2];
    int     hocchi_version[2];
    int     TV_version;
}               t_data;

//libft1
void    ft_putstr(char *array);
int     ft_strlen(char *array);
void    ft_bzero(void *array, int n);
void    ft_strcopy(char *ret, char *array);
//libft2
void    safe_free(char *array);
char    *ft_strjoin_free(char *array1, char *array2);
int     ft_len2nl(char *array);
int     count_nl(char *array);
//error
void    print_arg_error(void);
void    print_malloc_error(void);
//read_map
void    read_map(char *argv, char *array);

#endif