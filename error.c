#include "ikimono.h"

void print_arg_error(void)
{
    ft_putstr("Arg Error\n");
    exit(-1);
}

void    free_exit(char *array)
{
    ft_putstr("Malloc_error");
    free(*array);
    exit(-1);
}

void    free_data_exit(t_data *data)
{
    int i;

    ft_putstr("Malloc_error");
    i = -1;
    while((*data).map[++i])
        free((*data).map[i]);
    free((*data).map);
}
