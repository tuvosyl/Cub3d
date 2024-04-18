/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:44:25 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/18 13:44:36 by vsoltys          ###   ########.fr       */
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

// Custom defines
# define WHITESPACES "\t\n\v\f\r "

/*###########################################################################*/
/*                                 Includes                                  */
/*###########################################################################*/
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/DailyLib/dailylib.h"
# include "../lib/libft/libft.h"
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

typedef struct s_map // ok pour celle la
{
	char 		**map;
	t_2int		map_size;
	t_2int		*collision_map;
	char		*map_path;
	char		player_start;
	t_2int		player_pos;		
	int			fd;
}	t_map;

typedef struct s_texture
{
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*east_texture;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*north_image;
	mlx_image_t	*south_image;
	mlx_image_t	*west_image;
	mlx_image_t	*east_image;
}	t_image;

typedef struct s_texture_path // mais celle la sert vraiment a rien
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
} t_texture_path;

// Main Structure
// Walls are cube shaped so we only need one point to represent it
// Walls have a size of 1x1
typedef struct s_data
{
	mlx_t			*mlx;
	t_map			map;
	t_texture 		texture;
	t_image 		image;
	t_texture_path	texture_path;
	t_3RGB 			ground_color;
	t_3RGB			ceilling_color;
	t_2int			player_pos;
}	t_data;

/*###########################################################################*/
/*                                 Fonctions                                 */
/*###########################################################################*/

int				checking_init(t_data *data, int argc, char **argv);
int 			extract_value(t_data *data);
void			table_to_map(t_data *data);
void			create_collision_map(t_data *data);
bool			check_collision(t_data *data, t_2int pos);
int				parsing(t_data *data);
void			load_png(t_data *data);
void			texture_to_image(t_data *data);
void			error(void);
void 			printf_debug(t_data *data);


#endif
