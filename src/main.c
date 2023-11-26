# include "../includes/game_of_life.h"

int	init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (EXIT_FAILURE);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT, "Game of Life");
	if (!game->mlx.win)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	game_init(t_game *game)
{
	if (init_mlx(game) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	if (create_map(game) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	if (create_cells(game) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	if (create_background(game) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	game->pause = 0;
	game->change = 0;
}

int	main(void)
{
	t_game	game;

	game_init(&game);
	game_loop(&game);
	return (EXIT_SUCCESS);
}