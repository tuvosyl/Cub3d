/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:18:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/30 14:25:54 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// need to add fog of war
void	draw_rays(t_data *data, t_raywall *rays)
{
	int		height;
	int		color;
	t_2int	incr;

	incr.x = 0;
	mlx_delete_image(data->mlx, data->camera_view);
	data->camera_view = mlx_new_image(data->mlx,
			data->screen_size.x, data->screen_size.y);
	while (incr.x != data->screen_size.x)
	{
		height = (int)(data->screen_size.y - rays[incr.x].distance * 30);
		if (height < 0)
			height = 0;
		incr.y = data->screen_size.y / 2 - height / 2;
		while (incr.y != data->screen_size.y / 2 + height / 2)
		{
			float fog_factor = 1.0 - (rays[incr.x].distance / MAX_DISTANCE * 10);
			color = ft_pixel(109 * fog_factor, 37 * fog_factor, 190 * fog_factor, 255);
			mlx_put_pixel(data->camera_view, incr.x, incr.y, color);
			incr.y++;
		}
		incr.x++;
	}
	mlx_image_to_window(data->mlx, data->camera_view, 0, 0);
}

// to change
static t_raywall	single_raycast(t_data *data, int raynum)
{
	t_2float	ray;
	t_raywall	raywall;

	raywall.distance = 0;
	raynum = raynum - data->screen_size.x / 2;
	ray.x = data->player_pos.x + cos(deg_to_rad(data->player_dir + 90)) * (FOV / 100) * raynum * (1.5f / data->screen_size.x);
	ray.y = data->player_pos.y + sin(deg_to_rad(data->player_dir + 90)) * (FOV / 100) * raynum * (1.5f / data->screen_size.x);
	while (!is_wall(data, ray))
	{
		ray.x += cos(deg_to_rad(data->player_dir + raynum / 100.0f)) * RAY_SPEED;
		ray.y += sin(deg_to_rad(data->player_dir + raynum / 100.0f)) * RAY_SPEED;
		raywall.distance += RAY_SPEED;
	}
	return (raywall);
}

// Raycasting function called when the player or the camera moves
void	new_raycast(t_data *data)
{
	t_raywall	*rays;
	int		i;

	i = 0;
	rays = malloc(sizeof(t_raywall) * data->screen_size.x);
	while (i != data->screen_size.x)
	{
		rays[i] = single_raycast(data, i);
		i++;
	}
	draw_rays(data, rays);
	free(rays);
}
