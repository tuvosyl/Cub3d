/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:04:06 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/18 14:03:51 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	checking_init(&data, argc, argv);
	if (parsing(&data))
		return (1);	
	create_collision_map(&data);
	if (DEBUG)
		printf_debug(&data);
	return (0);
}