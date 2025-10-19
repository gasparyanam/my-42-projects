/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:24:15 by agaspary          #+#    #+#             */
/*   Updated: 2025/10/19 21:25:53 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define N 4

void	write_str(const char *s);
void	write_int(int val);
int		my_atoi(const char *s);
int		solve(int grid[N][N], int row, int col);

void	init_grid(int grid[N][N])
{
	int	i;
	int	j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
			grid[i][j] = 0;
	}
}

void	fill_arrays(int edges[N][N], char *argv[])
{
	int	i;

	i = 0;
	while (i < N)
	{
		edges[0][i] = my_atoi(argv[1 + i]);
		edges[1][i] = my_atoi(argv[5 + i]);
		edges[2][i] = my_atoi(argv[9 + i]);
		edges[3][i] = my_atoi(argv[13 + i]);
		i++;
	}
}

void	print_grid(int grid[N][N])
{
	int	i;
	int	j;

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

int	main(int argc, char *argv[])
{
	int	grid[N][N];
	int	edges[N][N];

	if (argc != 17)
		return (write_str("Usage: ./a.out <16 numbers>\n"), 1);
	fill_arrays(edges, argv);
	init_grid(grid);
	if (solve(grid, 0, 0))
	{
		write_str("Solution found:\n");
		print_grid(grid);
	}
	else
		write_str("No solution.\n");
	return (0);
}
