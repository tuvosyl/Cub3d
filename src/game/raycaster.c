/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:18:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/22 16:44:43 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_rays(t_data *data, float *rays)
{
	int		height;
	int		i;

	i = 0;
	while (i != data->screen_size.x)
	{
		height = data->screen_size.y - rays[i] * 2;
		// do something
		i++;
	}
}

static int	single_raycast(t_data *data, double angle) // to change
{
	t_2float	ray;
	int			distance;

	distance = 0;
	ray = data->player_pos;
	while (!is_wall(data, ray))
	{
		ray.x += cos(angle) * PLAYER_SPEED;
		ray.y += sin(angle) * PLAYER_SPEED;
		distance++;
	}
	return (distance * cos(angle - data->player_dir));
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
	rays = malloc(sizeof(int) * data->screen_size.x);
	while (i != data->screen_size.x)
	{
		rays[i] = single_raycast(data, find_angle(data, i));
		i++;
	}
	printf("rays[%d] = %f\n", data->screen_size.x / 2, rays[data->screen_size.x / 2]);
	draw_rays(data, rays);
	free(rays);
}
