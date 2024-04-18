/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dailylib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:59:32 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/18 13:44:13 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAILILIB_H
# define DAILILIB_H

/*###########################################################################*/
/*                                  Defines                                  */
/*###########################################################################*/
// Custom defines
# define WHITESPACES "\t\n\v\f\r "

/*###########################################################################*/
/*                                 Includes                                  */
/*###########################################################################*/
// Standard includes
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

/*###########################################################################*/
/*                                Structures                                 */
/*###########################################################################*/
// Structure for 2 integers
typedef struct s_2int
{
	int		x;
	int		y;
}	t_2int;

// Structure for 3 integers
typedef struct s_3int
{
	int		x;
	int		y;
	int		z;
}	t_3int;

// Structure for 4 integers (red, green, blue, light)
typedef struct s_4int
{
	int		r;
	int		g;
	int		b;
	int		l;
}	t_4int;

typedef struct s_RGB
{
	int		r;
	int		g;
	int		b;
}	t_3RGB;

#endif