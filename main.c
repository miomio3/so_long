#include "ikimono.h"

int main(int argc, char **argv)
{
    char    *array;
    t_data  data;

    if(argc != 2 )
        print_arg_error();
    array = read_map(argv[1]);
    init_data(&data, array);
	run_animation(&data);
	return(0);
}