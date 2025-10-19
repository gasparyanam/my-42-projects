#include <unistd.h>
#define N 4

int	visible_from_left(int *row);
int	visible_from_right(int *row);

int	check_all(int grid[N][N], int *top, int *bottom, int *left, int *right)
{
	int	i;
	int	j;
	int	col[N];
	int	row[N];

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			row[j] = grid[i][j];
			col[j] = grid[j][i];
			j++;
		}
		if (visible_from_left(row) != left[i])
			return (0);
		if (visible_from_right(row) != right[i])
			return (0);
		if (visible_from_left(col) != top[i])
			return (0);
		if (visible_from_right(col) != bottom[i])
			return (0);
		i++;
	}
	return (1);
}

