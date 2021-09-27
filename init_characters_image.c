#include "ikimono.h"

void	make_image(t_image image, t_vars vars)
{
	image.image = mlx_xpm_file_to_image(vars.mlx, image.path, &image.width, &image.height);
	//image.addr = (int *)mlx_get_data_addr (image.image, &image.bit, &image.size, &image.endian);
}

void	init_characters_image(t_characters *characters, t_vars vars)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	k = -1;
	/* while(++i < CHARA_NUM)
	{
		while(++j < 1)//VER_NUM)
		{
			while(++k < DIRE_NUM)
				make_image((*characters).player[i][j][k], vars);
			k = -1;
		}
		j = -1;
	} */
	i = -1;
	//while(++i < OBJ_NUM)
		//make_image((*characters).obj[i], vars);
	make_image((*characters).obj[0], vars);
	printf("%s", (*characters).obj[0].path);
	//mlx_put_image_to_window(vars.mlx, vars.win, (*characters).obj[0].image, WIN_UNIT * 0, WIN_UNIT * 0);
}

