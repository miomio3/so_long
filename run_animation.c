#include "ikimono.h"

t_vars	make_window(t_data data)
{
	t_vars 			vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data.width * WIN_UNIT, data.height * WIN_UNIT, "IKIMONO");
	return(vars);
}

void	free_players(t_characters *characters)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while((*characters).player[++i])
		while((*characters).player[i][++j])
			safe_free((*characters).player[i][j]);
}

int	malloc_players(t_characters *characters)
{
	int	i;
	int	j;
	int	k;
	i = -1;
	j = -1;
	k = -1;

	(*characters).player = malloc(sizeof(t_image **) * (CHARA_NUM));
	if((*characters).player == NULL)
		return(ERROR);
	(*characters).player[CHARA_NUM] = NULL;
	while(++i < CHARA_NUM)
	{
		(*characters).player[i] = malloc(sizeof(t_image *) * VER_NUM);
		if((*characters).player[i] == NULL)
		{
			free_players(characters);
			return(ERROR);
		}
		(*characters).player[i][VER_NUM] = NULL;
		while(++j < VER_NUM)
		{
			(*characters).player[i][j] = malloc(sizeof(t_image) * DIRE_NUM);
			if((*characters).player[i][j] == NULL)
			{
				free_players(characters);
				return(ERROR);
			}
		}
	}
}

int	malloc_obj()
{
	
}

void	run_animation(t_data *data)
{
	t_characters	characters;
	t_vars 			vars;

	//vars = make_window(data);
	if(malloc_characters(&characters) == ERROR);
		free_data_exit(data);//途中
	init_characters_path(&characters);
	init_characters_image(&characters, vars);
	//mlx_put_image_to_window(vars.mlx, vars.win, characters.obj[0].image, WIN_UNIT * 0, WIN_UNIT * 0);
	//put_obj(characters, vars, 1, 0, 0);
	//init_map(characters, vars, data);
	//mlx_loop(vars.mlx);
}