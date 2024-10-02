/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:38:39 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/02 02:44:17 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_grid_valid(t_grid *grid, uint8_t curr);
int	check_duplicates(t_grid *grid, uint8_t curr);
int	check_views(t_grid *grid, uint8_t curr);
int	check_final_views(t_grid *grid, int8_t curr);

int solve(t_grid *grid, uint8_t index)
{
	uint8_t	res;
	const uint8_t	y = index / grid->size;
	const uint8_t	x = index % grid->size;

	if (index == grid->total)
		return (1);
	while (++grid->map[index] <= grid->size)
	{
		if (0 != is_grid_valid(grid, index))
			return (0);
		if (index % grid->size == grid->size)
			res = solve(grid, index + 1);
		else
			res = solve (grid,)
			return (1);
	}
	grid->map[index] = 0;
	return (0);
}

int	is_grid_valid(t_grid *grid, uint8_t curr)
{
	if (0 != check_duplicates(grid, curr))
		return (-1);
	if (grid->size - 1 != curr % grid->size)
		return (check_views(grid, curr));
	return (check_final_views(grid, curr));
	
}


int	check_duplicates(t_grid *grid, uint8_t curr)
{
	const uint8_t	cmp = grid->map[curr];
	uint8_t i;
	
	i = curr - (curr % grid->size);
	while (i < curr)
	{
		if (grid->map[i] == cmp)
			return (1);
		i++;
	}	
	i = curr % grid->size;
	while (i < curr)
	{
		if (grid->map[i] == cmp)
			return (1);
		i += grid->size;
	}
	return (0);
}

int	check_views(t_grid *grid, uint8_t curr)
{
	uint8_t	max;
	uint8_t	seen;
	uint8_t i;

	seen = 0;
	max = 0;
	i = curr - (curr % grid->size);
	while (i < curr)
	{
		if (grid->map[i] > max)
		{
			max = grid->map[i];
			seen++;
		}
		i++;
	}
	// printf("curr=%d | view = %d | seen=%d\n", curr, grid->views[grid->size * 2 + curr / grid->size], seen);
	// display_grid(grid);
	if (seen > grid->views[grid->size * 2 + curr / grid->size])
		return (1);
	return (0);
}

int	check_final_views(t_grid *grid, int8_t curr)
{
	uint8_t	max;
	uint8_t	seen;
	uint8_t view;
	uint8_t i;

	seen = 0;
	max = 0;
	i = curr - (curr % grid->size);
	while (i <= curr)
	{
		if (grid->map[i] > max)
		{
			max = grid->map[i];
			seen++;
		}
		i++;
	}
	if (seen != grid->views[grid->size * 2 + curr / grid->size])
		return (1);
	
	view = grid->views[grid->size * 3 + curr / grid->size];
	seen = 0;
	max = 0;
	i = curr - (curr % grid->size);
	while (curr >= i)
	{
		if (grid->map[curr] > max)
		{
			max = grid->map[curr];
			seen++;
		}
		curr--;	
	}
	// printf("curr=%d | view = %d | seen=%d\n", curr, view, seen);
	// display_grid(grid);
	if (seen != view)
		return (1);
	return (0);
}
