#include "ikimono.h"

int ft_len2nl(char *array)
{
    int i;

    i = 0;
    while(array[i] != '\n')
        i++;
    return(i);
}

int check_0last_line(char *array)
{
    int i;

    i = 0;
    while(array[i] != '\n' && array[i] != '\0')
    {
        if(array[i] != '1')
            return(ERROR);
        i++;
    }
    return(NOERROR);
}

int check_map(char *array)
{
    int line_len;
    int i;

    if(check_0last_line(array) == ERROR)
        return(ERROR);
    line_len = ft_len2nl(array) + 1;
    i = line_len;
    while(array[i + line_len + 1])
    {
        if(array[i] != '1' || array[i + line_len - 2] != '1')
            return(ERROR);
        i = i + line_len;
    }
    if(i == line_len || check_0last_line(&array[i]) == ERROR)
        return(ERROR);
    return(NOERROR);
}

char *read_arg(char *argv)
{
    int     fd;
    char    array[101];
    char    *ret;

    fd = open(argv, O_RDONLY);
    ft_bzero(array, 101);
    ret = NULL;
	if (fd == -1)
	{
		printf("fail\n");
		exit(-1);
	}
    while(read(fd, array, 100) > 0)
        ret = ft_strjoin_free(ret, array);
    if(ret == NULL)
        exit(-1);
    return(ret);
}

int read_map(char *argv, char *array)
{
    array = read_arg(argv);
    if(array[0] == '\0' || check_map(array) == ERROR)
    {
        safe_free(array);
        arg_error();
        exit(-1);
    }
    return(NOERROR);
}
