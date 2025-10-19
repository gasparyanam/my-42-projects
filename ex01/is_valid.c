/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:09:47 by agaspary          #+#    #+#             */
/*   Updated: 2025/10/19 21:09:53 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

int	is_valid(int grid[N][N], int row, int col, int num);

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
