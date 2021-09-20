#include  "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_image{
	int		width;
	int		height;
	char	*path;
	void	*image;
	void	*addr;
	int		bit;
	int		size_line;
	int		endian;
}				t_image;

int	main(void)
{
	t_image	image;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
    mlx_string_put ( vars.mlx, vars.win, 200, 200, 500, "CONTINUATION" );
	mlx_loop(vars.mlx);
	return(0);
}