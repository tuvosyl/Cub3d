/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:18:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/07 10:55:17 by mgallais         ###   ########.fr       */
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
// Fonction principale pour dessiner les rayons avec textures
// void draw_rays(t_data *data, t_raywall *rays)
// {
//     int height;
//     uint32_t *texture;
//     uint32_t color;
//     t_2int incr;

//     incr.x = 0;
//     texture = malloc(sizeof(uint32_t) * TEXTURE_SIZE * TEXTURE_SIZE);
//     mlx_delete_image(data->mlx, data->camera_view);
//     data->camera_view = mlx_new_image(data->mlx, data->screen_size.x, data->screen_size.y);
//     convert_to_hex(texture, data->textures.north_texture->pixels);
//     while (incr.x < data->screen_size.x)
//     {
//         height = (int)(data->screen_size.y - rays[incr.x].distance * 32);
//         if (height < 0)
//             height = 0;
//         incr.y = data->screen_size.y / 2 - height / 2;

//         // Calcul de la coordonnée de texture x
//         //int texture_x = (int)(incr.x * TEXTURE_SIZE) % TEXTURE_SIZE;  // Supposons que la largeur de la texture soit de 64 pixels

//         while (incr.y < data->screen_size.y / 2 + height / 2)
//         {
//             // Calcul de la coordonnée de texture y
//            // float fog_factor = 1.0 - (rays[incr.x].distance / MAX_DISTANCE * 10);
//             int texture_y = ((incr.y - (data->screen_size.y / 2 - height / 2)) * TEXTURE_SIZE) / height;  // Supposons que la hauteur de la texture soit de 64 pixels
//             texture_y = fmin(fmax(texture_y, 0), 63); // S'assurer que les coordonnées sont dans les limites
//             color = texture[TEXTURE_SIZE * texture_y + rays[incr.x].texture_pos % TEXTURE_SIZE]; // Obtenir la couleur de la texture
//             mlx_put_pixel(data->camera_view, incr.x, incr.y, color);
//             incr.y++;
//         }
//         incr.x++;
//     }

//     // Afficher l'image de la vue de la caméra à la fenêtre
//     mlx_image_to_window(data->mlx, data->camera_view, 0, 0);
// }

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
	uint8_t *pixels;
	t_2int	incr;

	texture = malloc(sizeof(uint32_t) * TEXTURE_SIZE * TEXTURE_SIZE);
	incr.x = 0;
	pixels = texture_pixel(data, rays);
	
	mlx_delete_image(data->mlx, data->camera_view);
	data->camera_view = mlx_new_image(data->mlx,
			data->screen_size.x, data->screen_size.y);
	convert_to_hex(texture, pixels);
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
			// float fog_factor = 1.0 - (rays[incr.x].distance / MAX_DISTANCE * 10);
			int texture_y = ((incr.y - (data->screen_size.y / 2 - height / 2)) * TEXTURE_SIZE) / height;
            //texture_y = fmin(fmax(texture_y, 0), 63); 
			color = texture[TEXTURE_SIZE * texture_y + (rays[incr.x].texture_pos)];
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

