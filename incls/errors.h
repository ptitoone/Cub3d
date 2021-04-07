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

# define ERR_RES_INV		"Invalid resolution format"
# define ERR_RES_DUP		"Duplicate resolution parameter"
# define ERR_RES_NF			"Resolution not found"
# define ERR_RES_ZERO		"Resolution cant't start or be zero"

# define ERR_TEX_NO_OF		"Failed to open NORTH texture"
# define ERR_TEX_SO_OF		"Failed to open SOUTH texture"
# define ERR_TEX_WE_OF		"Failed to open WEST texture"
# define ERR_TEX_EA_OF		"Failed to open EAST texture"
# define ERR_TEX_INV		"Invalid texture format"
# define ERR_TEX_NULL		"No texture file path"
# define ERR_TEX_S_NF		"Sprite not found"
# define ERR_TEX_DUP		"Duplicate texture parameter"

# define ERR_MAP_DUP_POS	"Duplicate player position"
# define ERR_MAP_NO_POS		"No player position found"
# define ERR_MAP_INV		"Invalid map format"

# define ERR_MLX_FAIL		"MinilibX failed to init"

int							throw_error(char *error);

#endif
