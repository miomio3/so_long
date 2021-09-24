#include  "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define ESC			53
#define KEY_EVENT	2

typedef struct	s_param{
	int	x;
	int	y;
}				t_param;

int	key_hook(int keycode, void *vars)
{
	printf("Hello from key_hook!\n");
	return(0);
}

int key(int keycode, t_param *param)
{
	if(keycode == ESC)
		exit(0);
	return(0);
}


	//mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_destroy_image(vars.mlx, image1.image);
	//mlx_loop_hook(vars.mlx, put_image, &vars);
	//mlx_hook(vars.win , KEY_EVENT, 0, key, param);