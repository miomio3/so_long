#include "ikimono2.h"

void	put_image(t_vars vars, t_image image)
{
	image.image = mlx_xpm_file_to_image(vars.mlx, "./image/kureshin.xpm", &image.width, &image.height);
	mlx_put_image_to_window(vars.mlx, vars.win, image.image, 100,100);
	image.image = mlx_xpm_file_to_image(vars.mlx, "./image/test.xpm", &image.width, &image.height);
	mlx_put_image_to_window(vars.mlx, vars.win, image.image, 500,850);
}

int	main(void)
{
	t_image	image;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 900, "IKIMONO");
	put_image(vars, image);
	//mlx_hook(vars.win, 17, 1 << 17, close_win, &vars);
	mlx_loop(vars.mlx);
	return(0);
}

//  gcc test.c ./minilibx-linux/libmlx.a -lXext -lX11 //wsl
//  gcc test.c ./minilibx-linux/libmlx.a -lXext -lX11 //wsl
//  gcc test.c -Lmlx -lmlx -framework OpenGL -framework AppKit //校舎
//  gcc test.c -Lmlx -lmlx -framework OpenGL -framework AppKit //校舎