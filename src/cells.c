# include "../includes/game_of_life.h"

t_img	*create_dead_cell(t_game *game)
{
	t_img	*dead;

	dead = malloc(sizeof(t_img));
	if (!dead)
		return (NULL);
	dead->img = mlx_new_image(game->mlx.mlx, CELL_WIDTH, CELL_HEIGHT);
	dead->addr = (int *)mlx_get_data_addr(dead->img, &dead->bits_per_pixel, &dead->line_length, &dead->endian);
	for (int i = 0; i < CELL_WIDTH; i++)
	{
		for (int j = 0; j < CELL_HEIGHT; j++)
			dead->addr[j * CELL_WIDTH + i] = 0x00000000; // Negro
	}
	return (dead);
}

t_img	*create_alive_cell(t_game *game)
{
	t_img	*alive;

	alive = malloc(sizeof(t_img));
	if (!alive)
		return (NULL);
	alive->img = mlx_new_image(game->mlx.mlx, CELL_WIDTH, CELL_HEIGHT);
	alive->addr = (int *)mlx_get_data_addr(alive->img, &alive->bits_per_pixel, &alive->line_length, &alive->endian);
	for (int i = 0; i < CELL_WIDTH; i++)
	{
		for (int j = 0; j < CELL_HEIGHT; j++)
			alive->addr[j * CELL_WIDTH + i] = 0x00FFFFFF; // Negro
			// alive->addr[j * CELL_WIDTH + i] = 0x00FF0080; // ROSA
	}
	return (alive);
}

int	create_cells(t_game *game)
{
	t_cell	*cells;

	cells = &game->cell;
	cells->dead = create_dead_cell(game);
	cells->alive = create_alive_cell(game);
	if (cells->dead == NULL || cells->alive == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}