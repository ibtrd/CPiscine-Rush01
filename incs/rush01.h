/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:27:46 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/02 02:47:58 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

#include <stdio.h>
# include <stdint.h>

# define GRIDSIZE_MIN 3
# define GRIDSIZE_MAX 9
# define VIEWS 4

typedef struct s_grid
{
	uint8_t	size;
	uint8_t	*map;
	uint8_t	*views;
	uint8_t	total;
}	t_grid;

int		init_grid(char *arg, t_grid *grid);
void	deinit_grid(t_grid *grid);

int		parse_views(char *arg, t_grid *grid);

int		solve(t_grid *grid, uint8_t index);
void	display_grid(t_grid *grid);

#endif
