/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:42:14 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/07 17:13:02 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	rgb_to_hex(t_data *data, t_3RGB color, int depth)
{
	int	red;
	int	green;
	int	blue;
	int black;

	black = depth * 255 / (data->screen_size.y / 2);
	red = color.r * (255 - black) / 255;
	green = color.g * (255 - black) / 255;
	blue = color.b * (255 - black) / 255;
	return (ft_pixel(red, green, blue, 255));
}

void	background(t_data *data)
{
	t_2int	pos;
	int		color;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < data->screen_size.y)
	{
		pos.x = 0;
		if (pos.y > data->screen_size.y / 2)
			color = rgb_to_hex(data, data->textures.floor_color, data->screen_size.y - pos.y);
		else
			color = rgb_to_hex(data, data->textures.ceiling_color, pos.y);
		while (pos.x < data->screen_size.x)
		{
			mlx_put_pixel(data->camera_view, pos.x, pos.y, color);
			pos.x++;
		}
		pos.y++;
	}
}
