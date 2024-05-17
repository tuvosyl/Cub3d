/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:44:25 by vsoltys           #+#    #+#             */
/*   Updated: 2024/05/17 17:49:03 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*###########################################################################*/
/*                                  Defines                                  */
/*###########################################################################*/
// Program settings define
# ifdef DEBUG
#  define DEBUG 1
# else
#  define DEBUG 0
# endif

# ifdef BONUS
#  define BONUS 1
# else
#  define BONUS 0
# endif

// Cub3D defines
# define NORTH   0
# define SOUTH   1
# define WEST    2
# define EAST    3
# define FLOOR 	 4
# define CEILING 5

#define PLAYER_SPEED 0.1

// Custom defines
# define WHITESPACES "\t\n\v\f\r "
# define M_PI 3.14159265358979323846

/*###########################################################################*/
/*                                 Includes                                  */
/*###########################################################################*/
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/DailyLib/dailylib.h"
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <math.h>

/*###########################################################################*/
/*                                Structures                                 */
/*###########################################################################*/

typedef struct s_map
{
	char 		**map;
	int			fd;
	char		*map_path;
	t_2float	*collision_map;
	t_2int		map_size;
	char		player_start;
}	t_map;

typedef struct s_textures
{
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*east_texture;
	t_3RGB		floor_color;
	t_3RGB		ceiling_color;
}	t_textures;

typedef struct s_image
{
	mlx_image_t	*north_image;
	mlx_image_t	*south_image;
	mlx_image_t	*west_image;
	mlx_image_t	*east_image;
}	t_image;

typedef struct s_texture_path
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
} t_texture_path;

// Main Structure
typedef struct s_data
{
	mlx_t			*mlx;
	t_map			map;
	t_textures 		textures;
	t_texture_path	texture_path;
	t_image			images;
	t_2float		player_pos;
	t_2int			screen_size;
	float			player_dir;
	mlx_image_t		*player_img;
}	t_data;

/*###########################################################################*/
/*                                 Fonctions                                 */
/*###########################################################################*/

void	parsing(t_data *data, int argc, char **argv);
int		tcheck_max_rgb_value(char *temp);
void	printf_debug(t_data *data);
void	read_lenght(t_data *data);
void	table_to_map(t_data *data);
void 	load_png(t_data *data);
void	texture_to_image(t_data *data);
void	delete_texture(t_data *data);
void	free_data(t_data *data);
void	exit_msg(char *msg);
void	tcheck_file(t_data *data);
int 	is_wall(t_data *data, t_2float pos);
int		is_sprite(t_data *data, t_2float pos);
void	start_game(t_data *data);
void	events(void *data);
double	deg_to_rad(double deg);
int		move_forward(t_data *data);
int		move_backward(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
void	find_map_size_and_player_pos(t_data *data);

#endif
