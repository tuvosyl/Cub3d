/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:22:02 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/17 11:58:00 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// raycaster est dans la boucle du jeu pour qu'elle fonctionne a chaque frame
//   on peut la mettre a la fin de player_commands si probleme de performances
void	start_game(t_data *data)
{
	data->mlx = mlx_init(1920, 1080, "Cub3D", true);
	if (!data->mlx)
		return ;
	texture_to_image(data);
	//mlx_loop_hook(data->mlx, player_commands, data);
	//mlx_loop_hook(data->mlx, raycaster, data);
	mlx_loop(data->mlx);
	delete_texture(data);
	mlx_terminate(data->mlx);
}
