#include  "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
}

int	close(void)
{
	exit(1);
	return(0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	//mlx_string_put ( vars.mlx, vars.win, 200, 200, 98, "CONTINUATION" );
	//mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 33, 1 << 17, close, &vars);//
	mlx_loop(vars.mlx);
}

//  gcc test.c ./minilibx-linux/libmlx.a -lXext -lX11