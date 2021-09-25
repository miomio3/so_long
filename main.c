#include "ikimono.h"

int main(int argc, char **argv)
{
    char    *array;
    t_data  data;

    if(argc != 2 )
        print_arg_error();
    read_map(argv[1], array);
    init_data(array);
}