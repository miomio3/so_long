#include "ikimono.h"

int main(int argc, char **argv)
{
    char    *array;
    t_data  data;

    if(argc != 2 )
        print_arg_error();
    array = read_map(argv[1]);
    init_data(&data, array);
    /* int i;//debug
    int j;
    i = 0;
    j = 0;
    while(data.map[i])
    {
        printf("%c", data.map[i][j]);
        if(data.map[i][j] == '\n')
        {
            j = 0;
            i++;
        }
    } */
}