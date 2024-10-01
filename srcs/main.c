/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:27:12 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/01 22:43:57 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "rush01.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (1);
	}
	(void)av;
	return (0);
}
