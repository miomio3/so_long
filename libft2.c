#include "ikimono.h"

void    safe_free(char *array)
{
    if(array == NULL)
        return;
    free(array);
    array = NULL;
}

char    *ft_strjoin_free(char *array1, char *array2)
{
    char    *ret;
    int     n;
    int     array1_len;

    array1_len = ft_strlen(array1);//ヌル文字を含まない長さ
    n = array1_len + ft_strlen(array2);
    ret = malloc(sizeof(char) * (n + 1));
    if(ret == NULL)
        exit(-1);
    if(array1 != NULL)
        ft_strcopy(ret, array1);
    ft_strcopy(&ret[array1_len], array2);
    safe_free(array1);
    return(ret);
}

int ft_len2nl(char *array)
{
    int i;

    i = 0;
    while(array[i] != '\n')
        i++;
    return(i);
}

int count_nl(char *array)
{
    int i;
    int ret;

    i = 0;
    ret = 0;
    while(array[i])
    {
        if(array[i] == '\n')
            ret++;
        i++;
    }
    return(ret + 1);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*p;

	i = ft_strlen(s);
	p = malloc(sizeof(char) * i + 1);
	ft_strcopy(p, s);
	p[i] = '\0';
	return(p);
}