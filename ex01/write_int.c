/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:07:29 by agaspary          #+#    #+#             */
/*   Updated: 2025/10/19 21:07:35 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_int(int val);

void	write_int(int val)
{
	char	buf[16];
	int		i;
	int		neg;

	if (val == 0)
		return ((void)write(1, "0", 1));
	neg = 0;
	if (val < 0)
	{
		neg = 1;
		val = -val;
	}
	i = 0;
	while (val > 0)
	{
		buf[i++] = '0' + (val % 10);
		val /= 10;
	}
	if (neg)
		buf[i++] = '-';
	while (--i >= 0)
		write(1, &buf[i], 1);
}
