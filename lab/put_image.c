#include "ikimono.h"

int	put_image(t_param *param)
{
	param->image.image = mlx_xpm_file_to_image(param->vars.mlx, "./image/kureshin.xpm", &param->image.width, &param->image.height);
	mlx_put_image_to_window(param->vars.mlx, param->vars.win, param->image.image, 100,100);
	return(0);
}