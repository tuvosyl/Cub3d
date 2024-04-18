/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:06:15 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/18 15:29:47 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	get_color(t_data *data, char *str, int type)
{
	t_3int	color;
	char	**buf;
	int		j;

	j = 0;
	while (str[j] != ' ')
		j++;
	while (str[j] == ' ')
		j++;
	buf = ft_split(&str[j], ',');
	color = (t_3int){ft_atoi(buf[0]), ft_atoi(buf[1]), ft_atoi(buf[2])};
	if (type == FLOOR)
		data->textures.floor_color = color;
	else if (type == CEILING)
		data->textures.ceiling_color = color;
}

static void	get_texture_path(t_data *data, char *str, int type)
{
	mlx_texture_t	*path;
	int		j;

	j = 0;
	while (str[j] != ' ')
		j++;
	while (str[j] == ' ')
		j++;
	path = mlx_load_png(ft_strdup(&str[j]));
	if (type == NORTH)
		data->textures.north_image = mlx_texture_to_image(data-> mlx, path);
	else if (type == SOUTH)
		data->textures.south_image = mlx_texture_to_image(data-> mlx, path);
	else if (type == WEST)
		data->textures.west_image = mlx_texture_to_image(data-> mlx, path);
	else if (type == EAST)
		data->textures.east_image = mlx_texture_to_image(data-> mlx, path);
}

static void	check_line(t_data *data, char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		get_texture_path(data, str, NORTH);
	else if (str[0] == 'S' && str[1] == 'O')
		get_texture_path(data, str, SOUTH);
	else if (str[0] == 'W' && str[1] == 'E')
		get_texture_path(data, str, WEST);
	else if (str[0] == 'E' && str[1] == 'A')
		get_texture_path(data, str, EAST);
	else if (str[0] == 'F')
		get_color(data, str, FLOOR);
	else if (str[0] == 'C')
		get_color(data, str, CEILING);
	else if (str[0] == ' ' || str[0] == '1' || str[0] == '0')
		return ;
	else
		return (ft_printf("Error\n\tWrong line in the map file\n"), exit (1));
}

static void	extract_value(t_data *data, int map_fd)
{
	char	*str;
	t_2int	i;

	i = (t_2int){0, 0};
	data->map.map_size = (t_2int){0, 0};
	while (1)
	{
		str = get_next_line(map_fd);
		if (!str)
			break ;
		check_line(data, str);
		deallocate(str, &data->garbage);
	}
}

void	parsing(t_data *data, int argc, char **argv)
{
	int	map_fd;

	if (argc != 2)
		return (ft_printf("Error\n\tWrong number of arguments\n"), exit (1));
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd < 0)
		return (ft_printf("Error\n\tCan't open the map file\n"), exit (1));
	extract_value(data, map_fd);
	close(map_fd);
	return (0);
}
