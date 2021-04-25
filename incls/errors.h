/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:30:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:26:31 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "cub.h"

# define ERR_FILE_EXT_INV	"Invalid file extension"
# define ERR_NO_MAP_FILE	"No map file specified"
# define ERR_TOO_MANY_ARGS	"Too many arguments"

# define ERR_MISSING_PARAM	"Missing parameter"
# define ERR_INVALID_PARAM	"Invalid parameter line"

# define ERR_RES_INV		"Invalid resolution format"
# define ERR_RES_DUP		"Duplicate resolution parameter"
# define ERR_RES_ZERO		"Resolution can't start or be zero"

# define ERR_TEX_NO_OF		"Failed to open texture/sprite file"
# define ERR_TEX_INV_SIZE	"Invalid texture size"
# define ERR_TEX_NULL		"No texture file path"
# define ERR_TEX_DUP		"Duplicate texture parameter"
# define ERR_RGB_INV		"Floor/Ceiling RGB value incorrect"

# define ERR_MAP_NF			"Map not found"
# define ERR_INV_LINE_A_MAP	"Invalid line after map."

# define ERR_MAP_DUP_POS	"Duplicate player position"
# define ERR_MAP_NO_POS		"No player position found"
# define ERR_MAP_INV		"Invalid map character"
# define ERR_MAP_INV_WALL	"Map must be surrounded by walls '1'"
# define ERR_MAP_TOO_SMALL	"Map size too small, must be minimum 3x3"

# define ERR_IMG_CREATE		"Failed to create new mlx_image"

# define ERR_MALLOC_FAIL	"Malloc failed"

# define ERR_MLX_FAIL		"MinilibX failed to init"

int							throw_error(char *error);
int							check_map_validity(t_params *p);
int							check_file_validity(char *map_file_name);
int							check_player_pos(t_params *p);
int							check_file_extention(const char *file_name);
int							check_args(int argc, const char *argv_1,
								const char *argv_2, int *save_bmp);
int							check_map_presence(char *map_file_name);
int							check_params(const char *map_file_name);

#endif
