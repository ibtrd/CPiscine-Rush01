/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:47:08 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/02 01:12:56 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "rush01.h"

static uint8_t	get_grid_size(char *arg);
static void		ft_bzero(uint8_t *addr, uint64_t size);

int	init_grid(char *arg, t_grid *grid)
{
	grid->size = get_grid_size(arg);
	if (grid->size < GRIDSIZE_MIN || grid->size > GRIDSIZE_MAX)
		return (-1);
	grid->total = grid->size * grid->size;
	grid->map = malloc(sizeof(uint8_t) * grid->total);
	if (NULL == grid->map)
		return (-1);
	grid->views = malloc(sizeof(uint8_t) * grid->size * VIEWS);
	if (NULL == grid->views)
	{
		free(grid->map);
		return (-1);
	}
	ft_bzero(grid->map, sizeof(uint8_t) * grid->total);
	return (0);
}

static uint8_t	get_grid_size(char *arg)
{
	uint64_t	i;
	uint8_t		count;

	count = 0;
	i = 0;
	while (arg[i])
	{
		if (0 == i % 2)
		{
			if (arg[i] >= '1' && arg[i] <= '9')
				count++;
			else
				return (0);
		}
		else if (arg[i] != ' ' || arg[i + 1] == '\0')
			return (0);
		i++;
	}
	if (count % VIEWS)
		return (0);
	return (count / VIEWS);
}

static void	ft_bzero(uint8_t *addr, uint64_t size)
{
	uint64_t	i;

	i = 0;
	while (i < size)
	{
		addr[i] = 0;
		i++;
	}
}
