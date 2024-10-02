/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 02:48:20 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/02 02:59:20 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

uint8_t	*init_order(uint8_t	size)
{
	uint8_t	printed[GRIDSIZE_MAX][GRIDSIZE_MAX] = 
	uint8_t	*ptr;
	uint8_t i;
	uint8_t x ;
	uint8_t y ;

	printed = {0};
	ptr = malloc(sizeof(*ptr) * size * size);
	if (NULL == ptr)
		return (NULL);
	i = 0;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			ptr[i++] = 
			y++;
		}
		x++;
	}
	
}
