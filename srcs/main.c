/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:27:12 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/02 02:48:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "rush01.h"

int	main(int ac, char **av)
{
	t_grid	grid;
	uint8_t	*order;

	if (ac != 2 || 0 != init_grid(av[1], &grid))
	{
		return (1 && write(STDERR_FILENO, "Error\n", 6));
	}
	if (0 != parse_views(av[1], &grid) || 1 != solve(&grid, 0))
	{
		deinit_grid(&grid);
		return (1 && write(STDERR_FILENO, "Error\n", 6));
	}
	display_grid(&grid);
	deinit_grid(&grid);
	return (0);
}
