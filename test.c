#include  <mlx.h>//"./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define ESC			53
#define KEY_EVENT	2

typedef struct	s_vars{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_image{
	int		width;
	int		height;
	char	*path;
	void	*image;
}				t_image;

typedef struct	s_param{
	int	x;
	int	y;
}				t_param;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return(0);
}

int	close(void)
{
	exit(1);
	return(0);
}

int key(int keycode, t_param *param)
{
	if(keycode == ESC)
		exit(0);
	return(0);
}

int	put_image(t_vars *vars)
{
	int		width;
	int		height;
	void	*image;

	image = mlx_xpm_file_to_image(vars->mlx, "test.xpm", &width, &height);
	mlx_put_image_to_window(vars->mlx, vars->win, image, 50, 50);
	return(0);
}

int	main(void)
{
	t_image	image;
	t_vars	vars;
	t_param	*param;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	image.image = mlx_xpm_file_to_image(vars.mlx, "./image/test.xpm", &image.width, &image.height);
	mlx_put_image_to_window(vars.mlx, vars.win, image.image, 50, 50);
	//mlx_string_put ( vars.mlx, vars.win, 200, 200, 255, "CONTINUATION" );
	//mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_destroy_image(vars.mlx, image1.image);
	//mlx_hook(vars.win, 17, 1 << 17, close, &vars);//
	//mlx_loop_hook(vars.mlx, put_image, &vars);
	//mlx_hook(vars.win , KEY_EVENT, 0, key, param);
	mlx_loop(vars.mlx);
	return(0);
}

//  gcc test.c ./minilibx-linux/libmlx.a -lXext -lX11 //wsl
//  gcc test.c -Lmlx -lmlx -framework OpenGL -framework AppKit //校舎