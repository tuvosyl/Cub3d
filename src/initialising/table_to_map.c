/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_to_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:29:14 by val               #+#    #+#             */
/*   Updated: 2024/04/18 17:47:47 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void table_to_map_2(t_data *data, int k, int i)
{
	char **map;
	int j;

	j = 0;
	map = (char **)malloc(sizeof(char *) * (k - i + 1));
	while (i <= k)
	{
		map[j] = data->map.map[i];
		i++;
		j++;
	}
	map[j] = NULL;
	data->map.map = map;	
}

void	table_to_map(t_data *data)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	l = 0;
	while(data->map.map[i])
        i++;
	i -= 1;
	k = i;
    while(i != 0)
    {
		if (!data->map.map[i][j] || data->map.map[i][j] == '\n')
			return (table_to_map_2(data, k, i + 1));
        while(data->map.map[i][j])
        {
            if (data->map.map[i][j] == '1' || data->map.map[i][j] == ' ' || data->map.map[i][j] == '0' || data->map.map[i][j] == '\n')
				j++;
			else if ((data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S' || data->map.map[i][j] == 'W' || data->map.map[i][j] == 'E'))
			{
				data->map.player_start = data->map.map[i][j];
				data->map.map[i][j] = '0';
				data->player_pos.x = i;
				data->player_pos.y = j;
				j++;
			}
			else
				return (table_to_map_2(data, k, i + 1));
        }
		j = 0;
		if (l != 0)
			break ;
        i--;
    }
	exit(1) ;
}
