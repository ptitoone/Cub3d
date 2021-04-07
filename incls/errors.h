/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:30:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 11:30:55 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_RES_INV		"Invalid resolution format"
# define ERR_RES_DUP		"Duplicate resolution parameter"
# define ERR_RES_NF			"Resolution not found"

# define ERR_TEX_NO_NF		"North texture not found"
# define ERR_TEX_SO_NF		"South texture not found"
# define ERR_TEX_WE_NF		"West texture not found"
# define ERR_TEX_EA_NF		"East texture not found"
# define ERR_TEX_INV		"Invalid texture format"
# define ERR_TEX_NULL		"No texture file path"
# define ERR_TEX_S_NF		"Sprite not found"
# define ERR_TEX_DUP		"Duplicate texture parameter"

# define ERR_MAP_DUP_POS	"Duplicate player position"
# define ERR_MAP_INV		"Invalid map format"

#endif
