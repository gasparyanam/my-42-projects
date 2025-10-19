/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visible_from_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:08:22 by agaspary          #+#    #+#             */
/*   Updated: 2025/10/19 21:08:30 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

int	visible_from_left(int *row);

int	visible_from_left(int *row)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < N)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i++;
	}
	return (count);
}
