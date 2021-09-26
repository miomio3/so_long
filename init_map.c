#include "ikimono.h"

void	put_obj(t_characters characters, t_vars vars, int No, int i, int j)
{
	mlx_put_image_to_window(vars.mlx, vars.win, characters.obj[No].image, WIN_UNIT * i, WIN_UNIT * j);
}

void	put_TV(t_characters characters, t_vars vars, t_data data, int i, int j)
{
	mlx_put_image_to_window(vars.mlx, vars.win, characters.TV[data.TV_ver].image, WIN_UNIT * i, WIN_UNIT * j);
}

void	put_player(t_characters characters, t_vars vars, t_data data, int i, int j)
{
	mlx_put_image_to_window(vars.mlx, vars.win, characters.player[data.map[i][j] - KIYOE_PIECE][data.kiyoe_ver[0]][data.kiyoe_ver[1]].image, WIN_UNIT * i, WIN_UNIT * j);
}

void	init_map(t_characters characters, t_vars vars, t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(data.map[i])
	{
		while(data.map[i][j])
		{
			if(data.map[i][j] < '4')
				put_obj(characters, vars, data.map[i][j] - '0', i, j);
			else if(data.map[i][j] == '4')
				put_TV(characters, vars, data, i, j);
			else
				put_player(characters, vars, data, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}