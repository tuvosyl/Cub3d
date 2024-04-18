/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:05:21 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/15 17:29:58 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int all_around_0(char **map, int i, int j)
{
	if ((map[i][j + 1] != '1' && map[i][j + 1] != '0') || (map[i][j -  1] != '1' && map[i][j - 1] != '0'))
		return(printf("map not close\n"), 1);
	if ((map[i + 1][j] != '1' && map[i + 1][j] != '0') || (map[i + 1][j] != '1' && map[i + 1][j] != '0'))
		return(printf("map not close\n"), 1);
	return (0);
}

int map_close(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while(data->map.map[i][j])
		{
			if (data->map.map[i][j] == '0')
			{
				if (all_around_0(data->map.map, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int parsing(t_data *data)
{
	if (map_close(data))
		return (1);
	return (0);
}