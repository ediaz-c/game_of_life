# include "../includes/game_of_life.h"

int	create_map(t_game *game)
{
	int	cells_x;
	int	cells_y;

	cells_x = WIDTH / CELL_WIDTH;
	cells_y = HEIGHT / CELL_HEIGHT;
	game->map = malloc(sizeof(char *) * (cells_y + 1));
	if (!game->map)
		return (EXIT_FAILURE);
	for (int i = 0; i < cells_y; i++)
	{
		game->map[i] = malloc(sizeof(char) * (cells_x + 1));
		if (!game->map[i])
			return (EXIT_FAILURE);
		for (int j = 0; j < cells_x; j++)
			game->map[i][j] = '0';
		game->map[i][cells_x] = '\0';
	}
	game->map[cells_y] = NULL;
	return (EXIT_SUCCESS);
}
