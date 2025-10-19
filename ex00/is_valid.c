#include <unistd.h>
#define N 4

int	is_valid(int grid[N][N], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

