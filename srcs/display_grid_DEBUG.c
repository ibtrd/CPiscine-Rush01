/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid_DEBUG.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:54:44 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/02 01:04:37 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <rush01.h>

void	display_line(t_grid *grid, uint8_t line);

void	display_grid(t_grid *grid)
{
	printf("  \e[33m");
	int i = 0;
	while (i < grid->size)
		printf("%d ",grid->views[i++]);
	printf(" \n\e[0m");
	i = 0;
	while (i < grid->size)
		display_line(grid, i++);
	i = 0;
	printf("  \e[33m");
	while (i < grid->size)
		printf("%d ",grid->views[grid->size + i++]);
	printf(" \n\e[0m");
}

void	display_line(t_grid *grid, uint8_t line)
{
	uint8_t i;
	uint8_t start;

	printf("\e[33m%d\e[0m ", grid->views[grid->size * 2 + line]);
	start = line * grid->size;
	i = 0;
	while (i < grid->size)
		printf("%d ", grid->map[start + i++]);
	printf("\e[33m%d\e[0m\n", grid->views[grid->size * 3 + line]);
}


// void	display_grid(t_grid *grid)
// {
// 	printf("  \e[33m");
// 	int i = 0;
// 	while (i < grid->size)
// 		printf("%d ",grid->views[i++]);
// 	printf(" \n\e[0m");
// 	i = 0;
// 	while (i < grid->size)
// 		display_line(grid, i++);
// 	i = 0;
// 	printf("  \e[33m");
// 	while (i < grid->size)
// 		printf("%d ",grid->views[grid->size + i++]);
// 	printf(" \n\e[0m");
// }

// void	display_line(t_grid *grid, uint8_t line)
// {
// 	uint8_t i;
// 	uint8_t start;

// 	printf("\e[33m%d\e[0m ", grid->views[grid->size * 2 + line]);
// 	start = line * grid->size;
// 	i = 0;
// 	while (i < grid->size)
// 		printf("%d ", grid->map[start + i++]);
// 	printf("\e[33m%d\e[0m\n", grid->views[grid->size * 3 + line]);
// }
