/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:18:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/04 03:56:23 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// need to add fog of war
uint32_t get_texture_pixel(mlx_image_t *texture, int x, int y) {
    int index = (y * texture->width + x) * 4; // Calcul de l'index dans le tableau de pixels
    return *(uint32_t *)(texture->pixels + index); // Retourner la couleur à cet index
}

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
void draw_rays(t_data *data, t_raywall *rays) {
    int height;
    uint32_t *texture;
    uint32_t color;
    t_2int incr;

    incr.x = 0;
    texture = malloc(sizeof(uint32_t) * TEXTURE_SIZE * TEXTURE_SIZE);
    mlx_delete_image(data->mlx, data->camera_view);
    data->camera_view = mlx_new_image(data->mlx, data->screen_size.x, data->screen_size.y);
    convert_to_hex(texture, data->textures.north_texture->pixels);
    while (incr.x < data->screen_size.x)
    {
        height = (int)(data->screen_size.y - rays[incr.x].distance * 32);
        if (height < 0)
            height = 0;
        incr.y = data->screen_size.y / 2 - height / 2;

        // Calcul de la coordonnée de texture x
        //int texture_x = (int)(incr.x * TEXTURE_SIZE) % TEXTURE_SIZE;  // Supposons que la largeur de la texture soit de 64 pixels

        while (incr.y < data->screen_size.y / 2 + height / 2)
        {
            // Calcul de la coordonnée de texture y
           // float fog_factor = 1.0 - (rays[incr.x].distance / MAX_DISTANCE * 10);
            int texture_y = ((incr.y - (data->screen_size.y / 2 - height / 2)) * TEXTURE_SIZE) / height;  // Supposons que la hauteur de la texture soit de 64 pixels
            texture_y = fmin(fmax(texture_y, 0), 63); // S'assurer que les coordonnées sont dans les limites
            color = texture[TEXTURE_SIZE * texture_y + rays[incr.x].texture_pos % TEXTURE_SIZE]; // Obtenir la couleur de la texture
            mlx_put_pixel(data->camera_view, incr.x, incr.y, color);
            incr.y++;
        }
        incr.x++;
    }

    // Afficher l'image de la vue de la caméra à la fenêtre
    mlx_image_to_window(data->mlx, data->camera_view, 0, 0);
}


static t_raywall	single_raycast(t_data *data, int raynum)
{
	t_2float	ray;
	t_raywall	raywall;

	raywall.distance = 0;
	raynum = raynum - data->screen_size.x / 2;
	ray.x = data->player_pos.x + cos(deg_to_rad(data->player_dir + 90)) * (FOV / 100) * raynum * (2.5f / data->screen_size.x);
	ray.y = data->player_pos.y + sin(deg_to_rad(data->player_dir + 90)) * (FOV / 100) * raynum * (2.5f / data->screen_size.x);
	while (!is_wall(data, ray))
	{
		ray.x += cos(deg_to_rad(data->player_dir)) * RAY_SPEED;
		ray.y += sin(deg_to_rad(data->player_dir)) * RAY_SPEED;
		raywall.distance += RAY_SPEED;
	}
    raywall.wall_type = check_wall_type(data, ray, raywall);
    raywall.texture_pos = check_texture_pos(data, ray, raywall);
    printf("raywall.texture_pos: %d\n", raywall.texture_pos);
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
