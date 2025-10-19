/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:10:12 by agaspary          #+#    #+#             */
/*   Updated: 2025/10/19 21:10:19 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

int	check_row(int grid[N][N], int row);
int	check_col(int grid[N][N], int col);
int	check_all(int grid[N][N]);

int	check_row(int grid[N][N], int row)
{
	int	i;
	int	seen[5];
	int	num;

	i = 0;
	while (i < 5)
	{
		seen[i] = 0;
		i++;
	}
	i = 0;
	while (i < N)
	{
		num = grid[row][i];
		if (num < 1 || num > N || seen[num])
			return (0);
		seen[num] = 1;
		i++;
	}
	return (1);
}

int	check_col(int grid[N][N], int col)
{
	int	i;
	int	seen[5];
	int	num;

	i = 0;
	while (i < 5)
	{
		seen[i] = 0;
		i++;
	}
	i = 0;
	while (i < N)
	{
		num = grid[i][col];
		if (num < 1 || num > N || seen[num])
			return (0);
		seen[num] = 1;
		i++;
	}
	return (1);
}

int	check_all(int grid[N][N])
{
	int	row;
	int	col;

	row = 0;
	while (row < N)
	{
		if (!check_row(grid, row))
			return (0);
		row++;
	}
	col = 0;
	while (col < N)
	{
		if (!check_col(grid, col))
			return (0);
		col++;
	}
	return (1);
}
