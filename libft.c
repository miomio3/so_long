#include "ikimono.h"

void    ft_putstr(char *array)
{
    int i;

    i = ft_strlen(array);
    write(1, array, i);
}

void    ft_bzero(char array[101], int n)
{
    int          	i;
    unsigned char   *d;

    i = -1;
	d = (unsigned char *)array;
    while(++i < n)
	{
		printf("%d回目", i);
        d[i] = '\0';
	}
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
