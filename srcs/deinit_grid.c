/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:05:01 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/01 23:07:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "rush01.h"

void	deinit_grid(t_grid *grid)
{
	free(grid->map);
	grid->map = NULL;
	free(grid->views);
	grid->views = NULL;
}
