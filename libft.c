#include "ikimono.h"

void    ft_putstr(char *array)
{
    int i;

    i = ft_strlen(array);
    write(1, array, i);
}

void    ft_bzero(void *array, int n)
{
    int             i;
    unsigned char   *d;

    i = 0;
    d = array;
    while(i < n)
        d[i++] = '\0';
}

void    ft_strcopy(char *ret, char *array)
{
    int i;

    i = 0;
    while(array[i])
    {
        ret[i] = array[i];
        i++;
    }
}

int ft_strlen(char *array)
{
    int i;

    if(array == NULL)
        return(0);
    i = 0;
    while(array[i])
        i++;
    return(i);
}
