/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:55:39 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/18 15:45:15 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	parsing(&data, argc, argv);
	//checking(&data);
	//create_collision_map(&data);
	if (DEBUG)
		printf_debug(&data);
	//start_game(&data);
	return (0);
}