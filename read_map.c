#include "ikimono.h"

int check_0last_line(char *array, int line_len)
{
    int i;

    i = 0;
    while(i < line_len - 1)
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

    line_len = ft_len2nl(array) + 1;
    if(check_0last_line(array, line_len) == ERROR)
        return(ERROR);
    i = line_len;
    while(array[i + line_len -1])
    {
        if(array[i] != '1' || array[i + line_len - 2] != '1')
            return(ERROR);
        i = i + line_len;
		//printf("%c\n", array[i + line_len -1]);debug
    }
    if(i == line_len || check_0last_line(&array[i], line_len) == ERROR)
        return(ERROR);
    return(NOERROR);
}

char *read_arg(char *argv)
{
    int     fd;
    char    *array;
    char    *ret;

    fd = open(argv, O_RDONLY);
    array = malloc(sizeof(char) * 101);
    if(array == NULL)
        exit(-1);
    ft_bzero(array, 101);
    ret = NULL;
	if (fd == -1)
	{
		printf("File_open failed\n");
		exit_free(array);
	}
    while(read(fd, array, 100) > 0)
	{
		ret = ft_strjoin_free(ret, array);
        if(ret == NULL)
            exit_free(array);
		ft_bzero(array, 100);
	}
    free(array);
    return(ret);
}

char    *read_map(char *argv)
{
    char    *array;

    array = read_arg(argv);
    if(array[0] == '\0' || check_map(array) == ERROR)
    {
        safe_free(array);
        print_arg_error();
    }
    return(array);
}
