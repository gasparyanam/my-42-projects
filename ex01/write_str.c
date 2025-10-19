/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:07:02 by agaspary          #+#    #+#             */
/*   Updated: 2025/10/19 21:07:09 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_str(const char *s);

void	write_str(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (len > 0)
		write(1, s, len);
}
