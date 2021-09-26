#include "ikimono.h"

void	init_image(t_image image, t_vars vars)
{
	image.image = mlx_xpm_file_to_image(vars.mlx, image.path, &image.width, &image.height);
	image.addr = (int *)mlx_get_data_addr (image.image, &image.bit, &image.size, &image.endian);
}

static void	init_player(t_image player[3][4][4], int who, int version, char *up_path, char *down_path, char *right_path, char *left_path)
{
	player[who][version][UP].path = up_path;
	player[who][version][DOWN].path = down_path;
	player[who][version][RIGHT].path = right_path;
	player[who][version][LEFT].path = left_path;
}

void	init_obj(t_image obj, char *path)
{
	obj.path = path;
}

void	init_character(t_characters *characters)
{
	init_player((*characters).player, KIYOE, NORMAL, "kureshin.xpm", "kureshin.xpm", "kureshin.xpm", "kureshin.xpm");
	init_obj((*characters).wall, "test.xpm");
}

void	init_pictures(t_characters characters, t_vars vars)
{
	init_character(&characters);
}