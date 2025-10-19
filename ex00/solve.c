#include <unistd.h>
#define N 4

int	is_valid(int grid[N][N], int row, int col, int num);
int	check_all(int grid[N][N], int *top, int *bottom, int *left, int *right);

int	solve(int grid[N][N], int *top, int *bottom, int *left, int *right,
			int row, int col)
{
	int	next_row;
	int	next_col;
	int	num;

	if (row == N)
		return (check_all(grid, top, bottom, left, right));
	if (col == N - 1)
		next_row = row + 1;
	else
		next_row = row;
	next_col = (col + 1) % N;
	num = 1;
	while (num <= N)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, top, bottom, left, right, next_row, next_col))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

