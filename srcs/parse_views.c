/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_views.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:43:54 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/02 00:01:03 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	parse_views(char *arg, t_grid *grid)
{
	uint64_t	i;
	uint8_t		view;

	i = 0;
	while (i < grid->size * VIEWS)
	{
		view = arg[i * 2] - '0';
		if (view > grid->size)
			return (-1);
		grid->views[i] = view;
		i++;
	}
	return (0);
}
