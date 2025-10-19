/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:20:01 by agaspary          #+#    #+#             */
/*   Updated: 2025/10/19 22:06:48 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:20:01 by agaspary          #+#    #+#             */
/*   Updated: 2025/10/19 22:20:00 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

int	is_valid(int grid[N][N], int row, int col, int num);
int	check_all(int grid[N][N]);
int	visible_from_left(int *row);
int	visible_from_right(int *row);
int	visible_from_top(int grid[N][N], int col);
int	visible_from_bottom(int grid[N][N], int col);

int	check_visibility(int grid[N][N], int edges[N][N], int row, int col)
{
	if (col == N - 1)
	{
		if ((visible_from_left(grid[row])) != edges[2][row])
			return (0);
		if ((visible_from_right(grid[row])) != edges[3][row])
			return (0);
	}
	if (row == N - 1)
	{
		if ((visible_from_top(grid, col)) != edges[0][col])
			return (0);
		if ((visible_from_bottom(grid, col)) != edges[1][col])
			return (0);
	}
	return (1);
}

void	next_pos(int row, int col, int *next_row, int *next_col)
{
	if (col == N - 1)
	{
		*next_row = row + 1;
		*next_col = 0;
	}
	else
	{
		*next_row = row;
		*next_col = col + 1;
	}
}

int	solve(int grid[N][N], int edges[N][N], int row, int col)
{
	int	num;
	int	next_row;
	int	next_col;

	next_pos(row, col, &next_row, &next_col);
	if (row == N)
		return (1);
	num = 1;
	while (num <= N)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (check_visibility(grid, edges, row, col))
				if (solve(grid, edges, next_row, next_col))
					return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	visible_from_top(int grid[N][N], int col)
{
	int	i;
	int	max;
	int	count;
	int	val;

	i = 0;
	max = 0;
	count = 0;
	while (i < N)
	{
		val = grid[i][col];
		if (val > max)
		{
			max = val;
			count++;
		}
		i++;
	}
	return (count);
}

int	visible_from_bottom(int grid[N][N], int col)
{
	int	i;
	int	max;
	int	count;
	int	val;

	i = N - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		val = grid[i][col];
		if (val > max)
		{
			max = val;
			count++;
		}
		i--;
	}
	return (count);
}
