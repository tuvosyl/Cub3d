/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_to_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentins <valentins@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:11:49 by vsoltys           #+#    #+#             */
/*   Updated: 2024/05/21 17:10:12 by valentins        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	read_lenght_2(t_data *data, char *str, int i)
{
	i = 0;
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
