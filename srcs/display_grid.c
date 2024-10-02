/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:54:44 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/02 00:36:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <rush01.h>

void	display_grid(t_grid *grid)
{
	uint8_t y;
	uint8_t x;
	ssize_t	wr;
	char	c;

	y = 0;
	while (y < grid->size)
	{
		x = 0;
		while (x < grid->size)
		{
			c = grid->map[y * grid->size + x] + '0';
			wr = write(STDOUT_FILENO, &c, 1);
			if (x != grid->size - 1)
				wr = write(STDOUT_FILENO, " ", 1);
			x++;
		}
		wr = write(STDOUT_FILENO, "\n", 1);
		y++;
	}
	(void)wr;
	return;
}

