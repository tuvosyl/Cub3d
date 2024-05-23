/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:18:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/23 15:02:11 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_rays(t_data *data, float *rays)
{
	int		height;
	int		color;
	t_2int	incr;

	incr.x = 0;
	mlx_delete_image(data->mlx, data->camera_view);
	data->camera_view = mlx_new_image(data->mlx, data->screen_size.x, data->screen_size.y);
	while (incr.x != data->screen_size.x)
	{
		height = (int)(data->screen_size.y - rays[incr.x] * 2);
		if (height < 0)
			height = 0;
		incr.y = data->screen_size.y / 2 - height / 2;
		while (incr.y != data->screen_size.y / 2 + height / 2)
		{
			if (rays[incr.x] > MAX_DISTANCE)
				color = 0xFF000000;
			else
				color = 0xFF000000 + (int)(255 * (1 - rays[incr.x] / MAX_DISTANCE));
			mlx_put_pixel(data->camera_view, incr.x, incr.y, color);
			incr.y++;
		}
		incr.x++;
	}
	mlx_image_to_window(data->mlx, data->camera_view, 0, 0);
}

static float	single_raycast(t_data *data, double angle)
{
	t_2float	ray;
	float		distance;

	distance = 0;
	ray = data->player_pos;
	while (!is_wall(data, ray))
	{
		ray.x += cos(deg_to_rad(angle)) * PLAYER_SPEED;
		ray.y += sin(deg_to_rad(angle)) * PLAYER_SPEED;
		distance++;
	}
	return (distance  * cos(deg_to_rad(angle - data->player_dir)));
}

static double	find_angle(t_data *data, int i)
{
	double	angle;

	angle = data->player_dir - (FOV / 2) + (i * FOV / data->screen_size.x);
	return (angle);
}

// Raycasting function called when the player or the camera moves
void	new_raycast(t_data *data)
{
	float	*rays;
	int		i;

	i = 0;
	rays = malloc(sizeof(float) * data->screen_size.x);
	while (i != data->screen_size.x)
	{
		rays[i] = single_raycast(data, find_angle(data, i));
		i++;
		// printf("rays[%d] = %f\n", i, rays[i]);
	}
	//printf("rays[%d] = %f\n", data->screen_size.x / 2, rays[data->screen_size.x / 2]);
	draw_rays(data, rays);
	free(rays);
}
