#include "cub.h"

static void	init_headers(char tag[2], int header[13], int width, int height)
{
	tag[0] = 'B';
	tag[1] = 'M';
	header[0] = 0x00;
	header[1] = 0x00;
	header[2] = 0x36;
	header[3] = 0x28;
	header[4] = width;
	header[5] = height;
	header[6] = 0x200001;
	header[7] = 0x00;
	header[8] = 0x00;
	header[9] = 0x002e23;
	header[10] = 0x002e23;
	header[11] = 0x00;
	header[12] = 0x00;
}

void	save_view(t_params *p)
{
	int		fd;
	int		header[13];
	char	tag[2];
	int		col;
	int		row;

	init_headers(tag, header, p->win_w, p->win_h);
	fd = open("view.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	header [0] = sizeof(tag) + sizeof(header) + (p->win_w * p->win_h) * 4;
	write(fd, tag, sizeof(tag));
	write(fd, header, sizeof(header));
	row = p->win_h - 1;
	while (row >= 0)
	{
		col = -1;
		while (++col < p->win_w)
			write(fd, (char *)p->frame.addr
				+ row * p->frame.line_len + col * 4, 4);
		row--;
	}
	close(fd);
}
