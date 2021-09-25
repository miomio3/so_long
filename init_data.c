#include "ikimono.h"

void    free_data(t_data *data, int n)
{
    int i;

    i = 0;
    while(i < n)
    {
        free((*data).map[i]);
        i++;
    }
    free((*data).map);
}

int malloc_map(t_data *data, int width, int height)
{
    int i;

    (*data).map = malloc(sizeof(char *) * height + 1); //最後はNULLを詰める用
    if((*data).map == NULL)
    {
        ft_putstr("Malloc Error\n");
        return(ERROR);
    }
    i = 0;
    while(i < height)
    {
        (*data).map[i] = malloc(sizeof(char) * width + 1); //最後はヌル文字を詰める用
        if((*data).map[i] == NULL)
        {
            free_data(data, i);
            ft_putstr("Malloc Error\n");
            return(ERROR);
        }
        i++;
    }
    (*data).map[i] = NULL;
}

void    copy_array(t_data *data, char *array)
{
    int i;
    int j;
    int n;

    i = 0;
    j = 0;
    n = 0;
    while(array[n])
    {
        (*data).map[i][j] = array[n];
        j++;
        n++;
        if(array[n] == '\n' || array[n] == '\0')
        {
            (*data).map[i][j] = '\0';
            j = 0;
            i++;
            n++;
        }
    }
    (*data).map[i] = NULL;
}

void    init_player(t_data *data)
{
    (*data).kiyoe_ver[0] = 0;
    (*data).kiyoe_ver[1] = 0;
    (*data).leader_ver[0] = 0;
    (*data).leader_ver[1] = 0;
    (*data).hocchi_ver[0] = 0;
    (*data).hocchi_ver[1] = 0;
    (*data).TV_ver = 0;
}

void    init_data(t_data *data, char *array)
{
    int width;
    int height;

    width = ft_len2nl(array);
    height = count_nl(array);
    if(malloc_map(data, width, height) == ERROR)
    {
        safe_free(array);
        exit(-1);
    }
    copy_array(data, array);
    init_player(data);
    safe_free(array);
}