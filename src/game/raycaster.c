/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:18:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/06 14:22:04 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
		height = (data->screen_size.y * 0.5f) / tan(FOV * 0.5f) / rays[incr.x].distance * 5;
		if (height < 0)
			height = 0;
		if (height > data->screen_size.y)
			height = data->screen_size.y;
		incr.y = (data->screen_size.y / 2 - height / 2);
		while (incr.y != data->screen_size.y / 2 + height / 2)
		{
			color = ft_pixel(109, 37, 190, 255);
			mlx_put_pixel(data->camera_view, incr.x, incr.y, color);
			incr.y++;
		}
		incr.x++;
	}
	mlx_image_to_window(data->mlx, data->camera_view, 0, 0);
}

static t_raywall	single_raycast(t_data *data, float angle)
{
	t_2float	ray_pos;
	t_raywall	ray;

	(ray_pos) = data->player_pos;
	while (!is_wall(data, ray_pos))
	{
		ray_pos.x += cos(deg_to_rad(angle)) * RAY_SPEED;
		ray_pos.y += sin(deg_to_rad(angle)) * RAY_SPEED;
	}
	while (is_wall(data, ray_pos))
	{
		ray_pos.x -= cos(deg_to_rad(angle)) * (RAY_SPEED / 5);
		ray_pos.y -= sin(deg_to_rad(angle)) * (RAY_SPEED / 5);
	}
	ray.distance = sqrt(pow(data->player_pos.x - ray_pos.x, 2)
			+ pow(data->player_pos.y - ray_pos.y, 2));
	ray.distance = ray.distance * cos(deg_to_rad(data->player_dir - angle));
	if (ray.distance < 0.5f)
		ray.distance = 0.5f;
	return (ray);
}

static float	find_angle(t_data *data, int i)
{
	float	angle;

	angle = data->player_dir - (FOV / 2) + (i * FOV / data->screen_size.x);
	return (round_deg(angle));
}

// Raycasting function called when the player or the camera moves
void	new_raycast(t_data *data)
{
	t_raywall	*rays;
	int			i;

	i = 0;
	rays = malloc(sizeof(t_raywall) * data->screen_size.x);
	while (i != data->screen_size.x)
	{
		rays[i] = single_raycast(data, find_angle(data, i));
		i++;
	}
	draw_rays(data, rays);
	free(rays);
}
