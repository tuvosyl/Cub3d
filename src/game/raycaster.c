/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:18:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/28 13:28:45 by vsoltys          ###   ########.fr       */
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
	data->camera_view = mlx_new_image(data->mlx,
			data->screen_size.x, data->screen_size.y);
	while (incr.x != data->screen_size.x)
	{
		height = (int)(data->screen_size.y - rays[incr.x] * 3);
		if (height < 0)
			height = 0;
		incr.y = data->screen_size.y / 2 - height / 2;
		while (incr.y != data->screen_size.y / 2 + height / 2)
		{
			color = ft_pixel(255, 255, 255, 255);
			mlx_put_pixel(data->camera_view, incr.x, incr.y, color);
			incr.y++;
		}
		incr.x++;
	}
	mlx_image_to_window(data->mlx, data->camera_view, 0, 0);
}

// to change
static float	single_raycast(t_data *data, float angle, int ray_num)
{
	t_2float	ray;
	float		distance;

	distance = 0;
	ray = data->player_pos;
	(void)ray_num;
	while (!is_wall(data, ray))
	{
		ray.x += cos(deg_to_rad(angle)) * RAY_SPEED;
		ray.y += sin(deg_to_rad(angle)) * RAY_SPEED;
		distance++;
	}
	return (distance * cos(deg_to_rad(data->player_dir - angle)));
}

static float	find_angle(t_data *data, int i)
{
	float	angle;

	angle = data->player_dir - (FOV / 2) + (i * FOV / data->screen_size.x);
	if (angle < 0)
		angle += 360;
	if (angle > 360)
		angle -= 360;
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
		rays[i] = single_raycast(data, find_angle(data, i), i);
		i++;
	}
	draw_rays(data, rays);
	free(rays);
}
