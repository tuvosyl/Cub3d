/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:45:29 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/17 14:31:07 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	events(void *params)
{
	t_data	*data;
	static t_2int	previous_screen_size = {1920, 1080};

	data = (t_data *)params;

	// tests :
	int	x;
	int	y;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (x > data->screen_size.x / 2)
		printf("+");
	else if (x < data->screen_size.x / 2)
		printf("-");
	mlx_set_mouse_pos(data->mlx, data->screen_size.x / 2, data->screen_size.y / 2);
	if (data->screen_size.x != previous_screen_size.x || data->screen_size.y != previous_screen_size.y)
	{
		data->images.north_image->instances[1].x = data->screen_size.x - 64;
		data->images.north_image->instances[1].y = data->screen_size.y - 64;
		previous_screen_size.x = data->screen_size.x;
		previous_screen_size.y = data->screen_size.y;
	}
	// ---
}