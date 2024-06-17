/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:01:23 by vsoltys           #+#    #+#             */
/*   Updated: 2024/06/17 17:23:04 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <fcntl.h>
#include <stdio.h>


// char	*extract_rgb_2(char *str, int *i, int *which_value)
// {
// 	int		counter;
// 	int		counter_temp;
// 	char	*temp;

// 	counter = 0;
// 	counter_temp = 0;
// 	while (ft_isdigit(str[*i]) == 1 && str[*i] && str[*i] != ',')
// 	{
// 		(*i)++;
// 		counter++;
// 	}
// 	temp = malloc(sizeof(char) * counter + 1);
// 	*i -= counter;
// 	while (counter_temp != counter)
// 	{
// 		temp[counter_temp] = str[*i + counter_temp];
// 		counter_temp++;
// 	}
// 	temp[counter_temp] = '\0';
// 	*i += counter;
// 	(*which_value)++;
// 	return (temp);
// }

void extract_value_2_2(t_data *data, char *str)
{
	if (str[0] == 'E' && str[1] == 'A')
	{
		if (data->texture_path.east_texture == NULL)
			data->texture_path.east_texture = extract_texture_path(str);
		else
			exit_msg(data, "double east texture", 1);
	}
	if (str[0] == 'F')
	{
		if (data->textures.floor_color.r == -1)
			data->textures.floor_color
				= extract_rgb(data, str, data->textures.floor_color);
		else
			exit_msg(data, "double definition of floor color", 1);
	}
	if (str[0] == 'C')
	{
		if (data->textures.ceiling_color.r == -1)
			data->textures.ceiling_color = extract_rgb(data, str,
					data->textures.ceiling_color);
		else
			exit_msg(data, "double definition of ceiling color", 1);
	}
}
