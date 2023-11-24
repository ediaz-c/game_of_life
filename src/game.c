#include "../includes/game_of_life.h"

int	update(t_game *game)
{
	char	**new_map;
	char	**tmp;

	if (game->pause == 0)
	{
		new_map = update_map(game);
		tmp = game->map;
		game->map = new_map;
		free_mtx(tmp);
		print_cells(game);
		usleep(100000);
	}
	return (EXIT_SUCCESS);
}

void	game_loop(t_game *game)
{
	mlx_hook(game->mlx.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx.win, 17, 1L << 17, close_window, game);
	mlx_mouse_hook(game->mlx.win, mouse_click, game);
	mlx_loop_hook(game->mlx.mlx, update, game);
	mlx_loop(game->mlx.mlx);
}