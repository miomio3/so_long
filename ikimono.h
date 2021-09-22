#ifndef IKIMONO_H
#define IKIMONO_H

#include <stdio.h>
#include <stdlib.h>
#include  "./minilibx-linux/mlx.h"
#include <sysexits.h>

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

int	close(void);
//int	put_image(t_param *param);


# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define IMG_WIDTH 400
# define IMG_HEIGHT 300

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	//You don't need to understand the 3 values below.
	//After declaration, it will be automatically initialized when passed to mlx_get_data_addr function.
	//아래 3개 값은 이해 안해도 사용하는데 지장이 없음. 
	//선언한뒤 함수의 인자로만 잘 넣어주면 알아서 정보를 받아나옴.
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;


#endif