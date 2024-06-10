/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:18:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/10 09:19:30 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	convert_to_hex(uint32_t *texture_map, uint8_t *pixels)
{
	int	i;
	t_4int color;

	i = 0;
	while (i < TEXTURE_SIZE * TEXTURE_SIZE)
	{
		color.r = pixels[i * 4];
		color.g = pixels[i * 4 + 1];
		color.b = pixels[i * 4 + 2];
		color.l = pixels[i * 4 + 3];
		texture_map[i] = ft_pixel(color.r, color.g, color.b, color.l);
		i++;
	}
}

uint8_t *texture_pixel(t_data *data, t_raywall *rays)
{
	if (rays->wall_type == EAST)
		return (data->textures.east_texture->pixels);
	else if (rays->wall_type == WEST)
		return (data->textures.west_texture->pixels);
	else if (rays->wall_type == NORTH)
		return (data->textures.north_texture->pixels);
	else if (rays->wall_type == SOUTH)
		return (data->textures.south_texture->pixels);
	return (NULL);
}
void	draw_rays(t_data *data, t_raywall *rays)
{
	int		height;
	uint32_t *texture;
    uint32_t color;
	t_2int	incr;

	incr.x = 0;

	while (incr.x != data->screen_size.x)
	{
		height = (data->screen_size.y * 0.5f) / tan(FOV * 0.5f) / rays[incr.x].distance * 5;
		incr.y = (data->screen_size.y / 2 - height / 2);
		while (incr.y != data->screen_size.y / 2 + height / 2)
		{
			if (incr.y < 0 || incr.y >= data->screen_size.y)
			{
				incr.y++;
				continue;
			}
			if (rays[incr.x].wall_type == EAST)
				texture = data->textures.east_pixel;
			else if (rays[incr.x].wall_type == WEST)
				texture = data->textures.west_pixel;
			else if (rays[incr.x].wall_type == NORTH)
				texture = data->textures.north_pixel;
			else if (rays[incr.x].wall_type == SOUTH)
				texture = data->textures.south_pixel;
			//float fog_factor = 1.0 - (rays[incr.x].distance / MAX_DISTANCE * 10);
			int texture_y = ((incr.y - (data->screen_size.y / 2 - height / 2)) * TEXTURE_SIZE) / height;
            //texture_y = fmin(fmax(texture_y, 0), 63); 
			color = texture[TEXTURE_SIZE * texture_y + (rays[incr.x].texture_pos)];
			mlx_put_pixel(data->camera_view, incr.x, incr.y, color);
			incr.y++;
		}
		incr.x++;
	}
}

static t_raywall	single_raycast(t_data *data, float angle)
{
	t_2float	ray_pos;
	t_raywall	ray;

	(ray_pos) = data->player_pos;
	while (!is_wall(data, ray_pos, false))
	{
		ray_pos.x += cos(deg_to_rad(angle)) * RAY_SPEED;
		ray_pos.y += sin(deg_to_rad(angle)) * RAY_SPEED;
	}
	while (is_wall(data, ray_pos, false))
	{
		ray_pos.x -= cos(deg_to_rad(angle)) * (RAY_SPEED / 5);
		ray_pos.y -= sin(deg_to_rad(angle)) * (RAY_SPEED / 5);
	}
	ray.distance = sqrt(pow(data->player_pos.x - ray_pos.x, 2)
			+ pow(data->player_pos.y - ray_pos.y, 2));
	ray.distance = ray.distance * cos(deg_to_rad(data->player_dir - angle));
	if (ray.distance < 0.5f)
		ray.distance = 0.5f;
	ray.wall_type = check_wall_type(ray_pos, angle);
	ray.texture_pos = check_texture_pos(ray_pos, ray);
	if (DEBUG)
	{
		printf("ray.distance = %f\n", ray.distance);
		printf_wall_type(ray.wall_type);
		printf("ray.texture_pos = %d\n", ray.texture_pos);
	}
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

