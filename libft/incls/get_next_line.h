/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:52:00 by akotzky           #+#    #+#             */
/*   Updated: 2021/02/11 15:55:52 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# define BUFFER_SIZE 128

typedef struct s_data		t_data;

struct		s_data {
	char	buffer[BUFFER_SIZE + 1];
	int		pos;
	int		rd;
};

void		ft_set_null_buff(char *buffer, int len);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
int			ft_append_buff(int fd, char **line, t_data *logs);
int			ft_empty_line(char **line);

#endif
