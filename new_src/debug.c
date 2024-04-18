/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:59:51 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/18 14:53:13 by mgallais         ###   ########.fr       */
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
	ft_printf("\033[0;35mfloor_color :\033[0m\t%d,%d,%d,%d\n", data->ground_color.r, data->ground_color.g, data->ground_color.b, data->ground_color.l);
	ft_printf("\033[0;35mceiling_color :\033[0m\t%d,%d,%d,%d\n", data->ceilling_color.r, data->ceilling_color.g, data->ceilling_color.b, data->ceilling_color.l);
}