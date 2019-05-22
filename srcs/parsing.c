#include "Fdf.h"

int		size_y(char *read)
{
	int index;
	int	ret;

	index = 0;
	ret = 0;
	while (read[index])
	{
		if (read[index] == '\n')
			ret++;
		index++;
	}
	return (ret);
}

int		init_tab(t_fdf *data, char *read)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->size_y = size_y(read);
	data->map = NULL;
	if (!(data->map = (t_pixel **)malloc(sizeof(t_pixel*) * data->size_y + 1)))
		return (-1);
	while (y < data->size_y)
	{
		data->map[y] = NULL;
		if (!(data->map[y] = (t_pixel *)malloc(sizeof(t_pixel) * data->size_x + 1)))
			return (-1);
		x = 0;
		while (x < data->size_x)
		{
			data->map[y][x].height = 0;
			data->map[y][x].new_x = 0;
			data->map[y][x].new_y = 0;
			x++;
		}
		y++;
	}
	return (0);
}

int		to_int_tab(t_fdf *data, char *read)
{
	int index;
	int	x;
	int	y;

	index = 0;
	x = 0;
	y = 0;
	if (init_tab(data, read) == -1)
		return (-1);
	while(read[index])
	{
		if (!ft_isdigit(read[index]) && read[index] != ' ' && read[index] != '\n')
			return (-1);
		if (read[index] == '\n')
		{
			x = 0;
			y++;
		}
		if (ft_isdigit(read[index]))
		{
			data->map[y][x].height = ft_atoi(&read[index]);
			if (data->map[y][x].height == 0)
				data->map[y][x].no_high = 1;
			index += ft_intlenght(ft_atoi(&read[index])) - 1;
			x++;
		}
		index++;
	}
	return (1);
}

int		read_map(t_fdf *data, int fd)
{
	char		*line;
	char		*temp;

	line = NULL;
	if (!(temp = malloc(sizeof(char) + 1)))
		return (-1);
	ft_bzero(temp, 1);
	get_next_line(fd, &line);
	data->size_x = ft_count_words(line, ' ');
	temp = ft_fstrjoin(&temp, &line, 0, 1);
	temp = ft_fstrjoin_end(&temp, "\n");
	while (get_next_line(fd, &line))
	{
		if ((int)ft_count_words(line, ' ') != data->size_x)
		{
			ft_strdel(&temp);
			ft_strdel(&line);
			return (-1);
		}
		temp = ft_fstrjoin(&temp, &line, 0, 1);
		temp = ft_fstrjoin_end(&temp, "\n");
	}
	if (to_int_tab(data, temp) == -1)
		return (-1);
	ft_strdel(&temp);
	return (1);
}
