/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblasphe <cblasphe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:22:46 by cblasphe          #+#    #+#             */
/*   Updated: 2020/01/19 15:53:36 by cblasphe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_cleanup(char **map, char **line, t_tetri *head)
{
	if (map && *map)
		ft_strdel(map);
	if (line && *line)
		ft_strdel(line);
	ft_free_tetris(head);
	return (NULL);
}

char	*ft_concat(char *map, char *line)
{
	char	*tmp;
	char	*res;

	tmp = map;
	map = ft_strjoin(map, line);
	ft_strdel(&tmp);
	tmp = map;
	res = ft_strjoin(map, "\n");
	ft_strdel(&tmp);
	map = NULL;
	return (res);
}

t_tetri	*ft_collect_tetris(int fd)
{
	char	*line;
	char	*map;
	int		*intmap;
	t_tetri	*head;

	head = NULL;
	map = NULL;
	line = NULL;
	while (get_next_line(fd, &line) || line || map)
	{
		if (line && ft_strlen(line))
			map = (map) ? ft_concat(map, line) :
			ft_concat(ft_strdup(""), line);
		else
		{
			if (!(intmap = ft_validate_tetri_map(map)))
				return (ft_cleanup(&map, &line, head));
			head = (head == NULL) ? ft_create(intmap, 'A') :
			ft_add_last(head, intmap);
			ft_strdel(&map);
		}
		ft_strdel(&line);
	}
	map ? ft_strdel(&map) : map;
	return (head);
}

int		ft_process_file(char *filename)
{
	int		fd;
	t_tetri	*head;

	head = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("error");
		return (0);
	}
	head = ft_collect_tetris(fd);
	close(fd);
	if (fd < 0 || !ft_validate_slashes(filename, head)
		|| !head || ft_len_tetris(head) > 26)
	{
		ft_cleanup(NULL, NULL, head);
		ft_putendl("error");
		return (0);
	}
	ft_fillit(head);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_process_file(argv[1]);
	return (0);
}
