#include "ikimono.h"

int	main(void)
{
	t_mlx	*mlx;
	int		count_w;
	int		count_h;
	t_img	img;

	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

	//The reason why I cast to (int *): If I let this as void * type, whenever I refer to the array values, I need to multiply them by 4.
	//Check out keuhdall's github linked in my README for more information.

	//여기서 (int *)를 안해주고 img.data가 void *이면 밑에 배열값들을 참조할 때 다 4를 곱해야한다.
	//그렇기 때문에 int *로 캐스팅해주는편이 좋다고 한다.
	//keuhdall's github가면 더 자세한 내용을 볼 수 있습니다.

	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (count_w % 2)
				img.data[count_h * IMG_WIDTH + count_w] = 0xFFFFFF;
			else
				img.data[count_h * IMG_WIDTH + count_w] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}