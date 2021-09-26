#include "ikimono.h"

t_vars	make_window(t_data data)
{
	t_vars 			vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data.width * WIN_UNIT, data.height * WIN_UNIT, "IKIMONO");
	return(vars);
}

void	run_animation(t_data data)
{
	t_characters	characters;
	t_vars 			vars;

	vars = make_window(data);
	init_map(data);
	mlx_loop(vars.mlx);
}