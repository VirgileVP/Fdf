/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 14:57:45 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 14:57:46 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		manage_height(t_fdf *data, char *read, t_coord *coord, int *index)
{
	if (ft_isdigit(read[*index]) || read[*index] == '-')
	{
		data->map[coord->y][coord->x].height = (double)ft_atoi(&read[*index]);
		data->map[coord->y][coord->x].no_height =
		(data->map[coord->y][coord->x].height == 0) ? 1 : 0;
		*index += ft_intlenght(ft_atoi(&read[*index])) - 1;
		coord->x++;
	}
}

int			to_int_tab(t_fdf *data, char *read)
{
	int		index;
	t_coord	coord;

	index = 0;
	coord.x = 0;
	coord.y = 0;
	if (init_tab(data, read) == -1)
		return (-1);
	while (read[index])
	{
		if (!ft_isdigit(read[index]) && read[index] != '-'
		&& read[index] != ' ' && read[index] != '\n')
			return (-1);
		if (read[index] == '\n')
		{
			coord.x = 0;
			coord.y++;
		}
		manage_height(data, read, &coord, &index);
		index++;
	}
	return (1);
}

char		*read_map2(t_fdf *data, int fd, char *line, char *temp)
{
	while (get_next_line(fd, &line) == 1)
	{
		if ((int)ft_count_words(line, ' ') != data->size_x)
		{
			ft_strdel(&temp);
			ft_strdel(&line);
			return (NULL);
		}
		if (!(temp = ft_fstrjoin(&temp, &line, 0, 1)))
			return (NULL);
		if (!(temp = ft_fstrjoin_end(&temp, "\n")))
			return (NULL);
	}
	return (temp);
}

int			read_map(t_fdf *data, int fd)
{
	char	*line;
	char	*temp;

	if (!(temp = malloc(sizeof(char) + 1)))
		return (-1);
	ft_bzero(temp, 1);
	get_next_line(fd, &line);
	data->size_x = ft_count_words(line, ' ');
	if (!(temp = ft_fstrjoin(&temp, &line, 0, 1)))
		return (-1);
	if (!(temp = ft_fstrjoin_end(&temp, "\n")))
		return (-1);
	if (!(temp = read_map2(data, fd, line, temp)))
		return (-1);
	if (to_int_tab(data, temp) == -1)
		return (-1);
	
	
	int y;
	y = 0;
	printf("map = %20p\n", data->map);
	while (y < data->size_y)
	{
		printf("map[%2d] : %16p\n", y, data->map[y]);
		y++;
	}
	printf("temp : %19p\n", temp);
	ft_strdel(&temp);
	ft_strdel(&line);
	return (1);
}
