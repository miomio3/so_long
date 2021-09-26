#include "ikimono.h"

void	run_animation(t_data data)
{
	t_characters	characters;
	t_vars 			vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 900, "IKIMONO");
	init_map(characters, data);
	mlx_loop(vars.mlx);
}