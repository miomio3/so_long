#include  "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close(void)
{
	exit(0);
	return(0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	i= 0;
		while (i < 1000)
		{
				j = 0;
				while (j < 1000)
				{
						mlx_pixel_put(mlx, mlx_win, i, j, 127);
						j++;
				}
				i++;
		}
    mlx_hook(mlx_win, 17, 1 << 17, close, &img);
	mlx_loop(mlx);
}