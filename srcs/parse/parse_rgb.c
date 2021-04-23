/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 11:22:58 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/10 14:44:25 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "throw_error.h"

static int	convert_rgb_to_color(char **rgb)
{
	return (ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
}

static int	split_rgb(char *str)
{
	char		**rgb;
	int			i;
	int			color;

	rgb = ft_split(str, ',');
	i = 0;
	color = 0;
	if (rgb == NULL)
		return (throw_error(ERR_MALLOC_FAIL));
	while (rgb[i] != NULL && ft_strlen(rgb[i]) <= 3)
		i++;
	if (i == 3)
		color = convert_rgb_to_color(rgb);
	else
		color = -1;
	i = 0;
	while (rgb[i] != NULL)
		free(rgb[i++]);
	free(rgb[i]);
	free(rgb);
	return (color);
}

int	extract_rgb_value(char *str)
{
	int				i;
	int				j;
	int				comma_count;

	i = 0;
	j = 0;
	comma_count = 0;
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i + j]) || str[i + j] == ',')
		if (str[i + j++] == ',')
			comma_count++;
	while (str[i + j] == ' ')
		i++;
	if (comma_count == 2 && !str[i + j])
	{
		i = split_rgb(&str[i]);
		if (i != -1)
			return (i);
	}
	return (throw_error(ERR_RGB_INV));
}
