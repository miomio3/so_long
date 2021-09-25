#ifndef IKIMONO_H
#define IKIMONO_H

#include <stdio.h>
#include <stdlib.h>
#include  "./minilibx-linux/mlx.h"

typedef struct	s_vars{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_image{
	int		width;
	int		height;
	char	*path;
	void	*image;
	int		*addr;
	int		bit;
	int		size;
	int		endian;
}				t_image;

typedef struct	s_param{
	t_vars	vars;
	t_image	image;
}				t_param;

int	close_win(void);

#endif