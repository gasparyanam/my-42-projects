/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <youremail@example.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 00:00:00 by yourname          #+#    #+#             */
/*   Updated: 2025/10/19 00:00:00 by yourname         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define N 4

int my_atoi(const char *s);
void write_str(const char *s);
void write_int(int val);
int visible_from_left(int *row);
int visible_from_right(int *row);
int is_valid(int grid[N][N], int row, int col, int num);
int check_all(int grid[N][N], int *top, int *bottom, int *left, int *right);
int solve(int grid[N][N], int *top, int *bottom, int *left, int *right,
			int row, int col);

int	main(int argc, char *argv[])
{
	int	top[N];
	int	bottom[N];
	int	left[N];
	int	right[N];
	int	grid[N][N];
	int	i;
	int	j;

	if (argc != 17)
	{
		write_str("Использование: ");
		write_str(argv[0]);
		write_str(" <4 сверху> <4 снизу> <4 слева> <4 справа>\n");
		return (1);
	}
	i = -1;
	while (++i < N)
		top[i] = my_atoi(argv[1 + i]);
	i = -1;
	while (++i < N)
		bottom[i] = my_atoi(argv[5 + i]);
	i = -1;
	while (++i < N)
		left[i] = my_atoi(argv[9 + i]);
	i = -1;
	while (++i < N)
		right[i] = my_atoi(argv[13 + i]);
	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
			grid[i][j] = 0;
	}
	if (solve(grid, top, bottom, left, right, 0, 0))
	{
		write_str("Решение найдено:\n");
		i = -1;
		while (++i < N)
		{
			j = -1;
			while (++j < N)
			{
				write_int(grid[i][j]);
				if (j < N - 1)
					write_str(" ");
			}
			write_str("\n");
		}
	}
	else
		write_str("Решение не найдено.\n");
	return (0);
}

