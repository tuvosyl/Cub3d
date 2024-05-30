/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:18:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/30 15:24:12 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// need to add fog of war
uint32_t get_texture_pixel(mlx_image_t *texture, int x, int y) {
    int index = (y * texture->width + x) * 4; // Calcul de l'index dans le tableau de pixels
    return *(uint32_t *)(texture->pixels + index); // Retourner la couleur à cet index
}

// Fonction principale pour dessiner les rayons avec textures
void draw_rays(t_data *data, t_raywall *rays) {
    int height;
    uint32_t color;
    t_2int incr;
    uint8_t rgba[4];

    incr.x = 0;
    mlx_delete_image(data->mlx, data->camera_view);
    data->camera_view = mlx_new_image(data->mlx, data->screen_size.x, data->screen_size.y);

    while (incr.x < data->screen_size.x) {
        height = (int)(data->screen_size.y - rays[incr.x].distance * 32);
        if (height < 0)
            height = 0;
        incr.y = data->screen_size.y / 2 - height / 2;

        // Calcul de la coordonnée de texture x
        int texture_x = (int)(incr.x * TEXTURE_SIZE) % TEXTURE_SIZE;  // Supposons que la largeur de la texture soit de 64 pixels

        while (incr.y < data->screen_size.y / 2 + height / 2)
        {
            // Calcul de la coordonnée de texture y
            float fog_factor = 1.0 - (rays[incr.x].distance / MAX_DISTANCE * 10);
            int texture_y = ((incr.y - (data->screen_size.y / 2 - height / 2)) * TEXTURE_SIZE) / height;  // Supposons que la hauteur de la texture soit de 64 pixels
            texture_y = fmin(fmax(texture_y, 0), 63); // S'assurer que les coordonnées sont dans les limites

            // Obtenir la couleur de la texture
            color = get_texture_pixel(data->images.east_image, texture_x, texture_y);
            rgba[0] = ((color >> 24) & 0xFF) * fog_factor;
            rgba[1] = ((color >> 16) & 0xFF) * fog_factor;
            rgba[2] = ((color >> 8) & 0xFF) * fog_factor;
            rgba[3] = (color & 0xFF) * fog_factor;
          //  printf("color: r: %d, g: %d, b: %d, a: %d\n", rgba[0], rgba[1], rgba[2], rgba[3]);
            color = (rgba[0] << 24) | (rgba[1] << 16) | (rgba[2] << 8) | rgba[3];
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
	ray.x = data->player_pos.x + cos(deg_to_rad(data->player_dir + 90)) * (FOV / 100) * raynum * (1.5f / data->screen_size.x);
	ray.y = data->player_pos.y + sin(deg_to_rad(data->player_dir + 90)) * (FOV / 100) * raynum * (1.5f / data->screen_size.x);
	while (!is_wall(data, ray))
	{
		ray.x += cos(deg_to_rad(data->player_dir)) * RAY_SPEED;
		ray.y += sin(deg_to_rad(data->player_dir)) * RAY_SPEED;
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
