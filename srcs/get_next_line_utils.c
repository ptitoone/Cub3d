/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:23:47 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/16 11:26:50 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

void	ft_set_null_buff(char *buffer, int len)
{
	int		i;

	i = 0;
	while (i < len)
		buffer[i++] = 0;
}

int	ft_empty_line(char **line)
{
	*line = (char *)malloc(sizeof(char) * 1);
	if (*line == NULL)
		return (0);
	*(*line) = 0;
	return (0);
}

char	*ft_strdup_len(const char *str, int len)
{
	char	*sdup;
	int		i;

	i = 0;
	sdup = (char *)malloc(sizeof(char) * (ft_strlen(str) + len) + 1);
	if (sdup == NULL)
		return (NULL);
	ft_set_null_buff(sdup, ft_strlen(str) + len + 1);
	while (str && str[i] != 0)
	{
		sdup[i] = str[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}

static int	free_and_return(char **str, int ret)
{
	free(*str);
	*str = NULL;
	return (ret);
}

int	ft_append_buff(int fd, char **line, t_data *logs)
{
	char				*tmp;
	size_t				line_len;

	line_len = ft_strlen(*line);
	tmp = NULL;
	if (!logs->buffer[0])
	{
		logs->rd = read(fd, logs->buffer, BUFFER_SIZE);
		if (logs->rd == 0)
			return (0);
	}
	tmp = ft_strdup_len(*line, 0);
	free(*line);
	*line = ft_strdup_len(tmp, logs->rd);
	while (logs->pos < logs->rd)
	{
		if (logs->buffer[logs->pos] == '\n')
			return (free_and_return(&tmp, 1));
		(*line)[line_len] = logs->buffer[logs->pos];
		logs->pos++;
		line_len++;
	}
	return (free_and_return(&tmp, 0));
}
