#include "ikimono.h"

void	put_str(void)
{
	printf("OK\n");
}

void	put_image(t_vars vars, t_image image)
{
	int	i;

	image.image = mlx_xpm_file_to_image(vars.mlx, "./image/kureshin.xpm", &image.width, &image.height);
	image.addr = (int *)mlx_get_data_addr(image.image, &image.bit, &image.size, &image.endian);
	i = 0;
	while(image.addr[i])
		printf("%d", image.addr[i++]);
	mlx_put_image_to_window(vars.mlx, vars.win, image.image, 100,100);
}

int	main(void)
{
	t_image	image;
	t_vars	vars;
	t_param	*param;

	param = malloc(sizeof(t_param));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "IKIMONO");
	put_image(vars, image);
	mlx_hook(vars.win, 17, 1 << 17, close, &vars);
	mlx_loop(vars.mlx);
	free(param);
	return(0);
}

//  gcc test.c ./minilibx-linux/libmlx.a -lXext -lX11 //wsl
//  gcc test.c ./minilibx-linux/libmlx.a -lXext -lX11 //wsl
//  gcc test.c -Lmlx -lmlx -framework OpenGL -framework AppKit //校舎
//  gcc test.c -Lmlx -lmlx -framework OpenGL -framework AppKit //校舎