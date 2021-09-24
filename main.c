#include "ikimono.h"

int main(int argc, char **argv)
{
    char    *array;

    if(argc != 2 )
        arg_error();
    if(read_map(argv[1], array) == ERROR)
        return(-1);
}