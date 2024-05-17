/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:22:02 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/17 14:24:24 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	resize(int width, int height, void *params)
{
	t_data	*data;

	data = (t_data *)params;
	data->screen_size.x = width;
	data->screen_size.y = height;
	if (DEBUG)
		printf("Window | width: %d, height: %d\n", width, height);
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init(data->screen_size.x, data->screen_size.y, "Cub3D", true);
	if (!data->mlx)
		return ;
	texture_to_image(data);
	// tests :
	mlx_image_to_window(data->mlx, data->images.north_image, 0, 0);
	mlx_image_to_window(data->mlx, data->images.north_image, data->screen_size.x - 64, data->screen_size.y - 64);
	// ---
	mlx_resize_hook(data->mlx, resize, data);
	mlx_loop_hook(data->mlx, events, data);
	mlx_loop(data->mlx);
	delete_texture(data);
	mlx_terminate(data->mlx);
}
