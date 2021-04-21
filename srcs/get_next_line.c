/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:24:29 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/16 11:26:50 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	empty_and_return(int rd, char **str)
{
	ft_empty_line(str);
	if (rd > 0)
		return (1);
	else
		return (0);
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
			return (empty_and_return(logs.rd, line));
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
