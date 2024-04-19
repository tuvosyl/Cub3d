/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_to_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:11:49 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/19 16:15:31 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	read_lenght_2(t_data *data, char *str, int i)
{
	str = get_next_line(data->map.fd);
	if (!str)
		return ;
	i = 0;
	while (1)
	{
		free(str);
		str = get_next_line(data->map.fd);
		if (str == NULL)
			break ;
		data->map.map[i] = ft_strdup(str);
		i++;
	}
	close(data->map.fd);
}

void	read_lenght(t_data *data)
{
	char	*str;
	int		i;

	i = 0;
	data->map.map = NULL;
	data->map.fd = open(data->map.map_path, O_RDONLY);
	str = get_next_line(data->map.fd);
	if (!str)
		return ;
	while (1)
	{
		free(str);
		str = get_next_line(data->map.fd);
		if (str == NULL)
			break ;
		i++;
	}
	free(str);
	str = NULL;
	close(data->map.fd);
	data->map.map = (char **)malloc(sizeof(char *) * (i + 1));
	data->map.fd = open(data->map.map_path, O_RDONLY);
	read_lenght_2(data, str, i);
}

// void	read_lenght_2(t_data *data, char *str, int i)
// {
// 	i = 0;
// 	while (1)
// 	{
// 		str = get_next_line(data->map.fd);
// 		if (str == NULL)
// 			break ;
// 		data->map.map[i] = ft_strdup(str);
// 		i++;
// 		free(str);
// 	}
// 	free(str);
// 	data->map.map[i] = NULL;
// 	close(data->map.fd);
// }

// void	read_lenght(t_data *data)
// {
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	data->map.map = NULL;
// 	ft_printf("map_path = %s\n", data->map.map_path);
// 	data->map.fd = open(data->map.map_path, O_RDONLY);
// 	str = get_next_line(data->map.fd);
// 	if (!str)
// 		return ;
// 	while (1)
// 	{
// 		free(str);
// 		str = get_next_line(data->map.fd);
// 		if (str == NULL)
// 			break ;
// 		i++;
// 	}
// 	free(str);
// 	close(data->map.fd);
// 	data->map.map = (char **)malloc(sizeof(char *) * (i + 1));
// 	data->map.fd = open(data->map.map_path, O_RDONLY);
// 	read_lenght_2(data, str, i);
// }