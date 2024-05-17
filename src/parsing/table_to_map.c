/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_to_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:29:14 by val               #+#    #+#             */
/*   Updated: 2024/05/17 14:19:31 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	player_dir(t_data *data)
{
	if (data->map.player_start == 'N')
		data->player_angle = 0;
	else if (data->map.player_start == 'E')
		data->player_angle = 90;
	else if (data->map.player_start == 'S')
		data->player_angle = 180;
	else if (data->map.player_start == 'W')
		data->player_angle = 270;
}

void table_to_map_2(t_data *data, int k, int i)
{
	char **map;
	int j;

	j = 0;
	map = (char **)malloc(sizeof(char *) * (k - i + 2));
	while (i <= k)
	{
		map[j] = ft_strdup(data->map.map[i]);
		i++;
		j++;
	}
	map[j] = NULL;
	free_split(data->map.map);
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
	data->map.player_start = '+';
	while(data->map.map[i] != NULL)
        i++;
	i -= 1;
	k = i;
    while(i != 0)
    {
		if (!data->map.map[i][j])
			return (table_to_map_2(data, k, i + 1));
		if (data->map.map[i][j] == '\n')
			return (table_to_map_2(data, k, i + 1));
        while(data->map.map[i][j])
        {
            if (data->map.map[i][j] == '1' || data->map.map[i][j] == ' ' || data->map.map[i][j] == '0' || data->map.map[i][j] == '\n')
				j++;
			else if ((data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S' || data->map.map[i][j] == 'W' || data->map.map[i][j] == 'E'))
			{
				if (data->map.player_start != '+')
				{
					free_data(data);
					exit_msg("Error\n↪\tMultiple player start\n");
				}
				data->map.player_start = data->map.map[i][j];
				data->map.map[i][j] = '0';
				data->player_pos.x = i + 0.5f;
				data->player_pos.y = j + 0.5f;
				player_dir(data);
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
