/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visible_from_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:09:06 by agaspary          #+#    #+#             */
/*   Updated: 2025/10/19 21:09:13 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

int	visible_from_right(int *row);

int	visible_from_right(int *row)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = N - 1;
	while (i >= 0)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i--;
	}
	return (count);
}
