#include "../includes/game_of_life.h"

char	**new_mtx(void)
{
	char	**new_mtx;
	int		cells_x;
	int		cells_y;

	cells_x = WIDTH / CELL_WIDTH;
	cells_y = HEIGHT / CELL_HEIGHT;
	new_mtx = malloc(sizeof(char *) * (cells_y + 1));
	if (!new_mtx)
		return (NULL);
	for (int i = 0; i < cells_y; i++)
	{
		new_mtx[i] = malloc(sizeof(char) * (cells_x + 1));
		if (!new_mtx[i])
			return (NULL);
		for (int j = 0; j < cells_x; j++)
			new_mtx[i][j] = '0';
		new_mtx[i][cells_x] = '\0';
	}
	new_mtx[cells_y] = NULL;
	return (new_mtx);
}

void	free_mtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}