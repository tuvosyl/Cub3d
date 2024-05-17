/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_to_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:11:49 by vsoltys           #+#    #+#             */
/*   Updated: 2024/05/17 17:06:00 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	read_lenght_2(t_data *data, char *str, int i)
{
	int		len;
	
	i = 0;
	len = 0;
	while (1)
	{
		str = get_next_line(data->map.fd);
		if (str == NULL)
			break ;
		data->map.map[i] = ft_strdup(str);
		free(str);
		i++;
	}
	data->map.map[i] = NULL;
	close(data->map.fd);
}

void	read_lenght(t_data *data)
{
	char	*str;
	int		i;

	i = 0;
	data->map.map = NULL;
	data->map.fd = open(data->map.map_path, O_RDONLY);
	while (1)
	{
		str = get_next_line(data->map.fd);
		if (str == NULL)
			break ;
		i++;
		free(str);
	}
	free(str);
	str = NULL;
	close(data->map.fd);
	data->map.map = (char **)malloc(sizeof(char *) * (i + 1));
	data->map.fd = open(data->map.map_path, O_RDONLY);
	read_lenght_2(data, str, i);
}
