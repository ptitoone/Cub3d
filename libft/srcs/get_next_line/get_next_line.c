/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:57:46 by akotzky           #+#    #+#             */
/*   Updated: 2021/02/11 15:58:14 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	empty_and_return(char **line, int rd)
{
	ft_empty_line(line);
	if (rd == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static t_data	logs;

	if (fd < 0 || fd >= 1000)
		return (-1);
	if (!logs.buffer[0])
	{
		logs.rd = read(fd, logs.buffer, BUFFER_SIZE);
		if (logs.rd == 0 || logs.buffer[0] == '\n')
			return (empty_and_return(line, logs.rd));
	}
	if (logs.buffer[logs.pos] == '\n' && logs.pos < BUFFER_SIZE)
		logs.pos++;
	else if (logs.buffer[logs.pos] == '\n' && logs.pos == BUFFER_SIZE - 1)
		logs.rd = read(fd, logs.buffer, BUFFER_SIZE);
	while (ft_append_buff(fd, line, &logs) == 0)
	{
		if (logs.rd == 0)
			return (0);
		logs.pos = 0;
		ft_set_null_buff(logs.buffer, BUFFER_SIZE + 1);
	}
	return (1);
}
