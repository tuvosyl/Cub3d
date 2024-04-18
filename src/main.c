/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:55:39 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/18 18:11:19 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	parsing(&data, argc, argv);
	// data.mlx = mlx_init(1800, 900, "oui", true);
	// load_png(&data);
	// texture_to_image(&data);
	//create_collision_map(&data);
	if (DEBUG)
		printf_debug(&data);
	//start_game(&data);
	// mlx_image_to_window(data.mlx, data.images.north_image, 0, 0);
	// mlx_loop(data.mlx);
	// mlx_terminate(data.mlx);
	return (0);
}