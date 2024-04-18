/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:59:51 by mgallais          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/18 13:45:18 by vsoltys          ###   ########.fr       */
=======
/*   Updated: 2024/04/18 10:41:10 by mgallais         ###   ########.fr       */
>>>>>>> ec4cc34193ab33f5d09556f168b5d9bb1c42c557
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void printf_debug(t_data *data)
{
	int i;

	i = 0;
	ft_printf("\033[0;35mmap :\033[0m\n");
	while(data->map.map[i])
	{
		ft_printf("\t\t%s\n", data->map.map[i]);
		i++;
	}
	ft_printf("\033[0;35mmap.player_start : \033[0m%c\n\n", data->map.player_start);
	ft_printf("\033[0;35mmap_path :\033[0m\t\t%s\n\n", data->map.map_path);
	ft_printf("\033[0;35mtexture_path_north :\033[0m\t%s\n", data->texture_path.north_texture);
	ft_printf("\033[0;35mtexture_path_south :\033[0m\t%s\n", data->texture_path.south_texture);
	ft_printf("\033[0;35mtexture_path_west  :\033[0m\t%s\n", data->texture_path.west_texture);
	ft_printf("\033[0;35mtexture_path_east  :\033[0m\t%s\n\n", data->texture_path.east_texture);
<<<<<<< HEAD
	ft_printf("\033[0;35mfloor_color :\033[0m\t%d,%d,%d\n", data->ground_color.r, data->ground_color.g, data->ground_color.b);
	ft_printf("\033[0;35mceiling_color :\033[0m\t%d,%d,%d\n", data->ceilling_color.r, data->ceilling_color.g, data->ceilling_color.b);
	printf_collision(data);
=======
	ft_printf("\033[0;35mfloor_color :\033[0m\t%d,%d,%d,%d\n", data->ground_color.r, data->ground_color.g, data->ground_color.b, data->ground_color.l);
	ft_printf("\033[0;35mceiling_color :\033[0m\t%d,%d,%d,%d\n", data->ceilling_color.r, data->ceilling_color.g, data->ceilling_color.b, data->ceilling_color.l);
>>>>>>> ec4cc34193ab33f5d09556f168b5d9bb1c42c557
}