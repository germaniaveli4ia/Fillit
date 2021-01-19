/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblasphe <cblasphe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:12:15 by cblasphe          #+#    #+#             */
/*   Updated: 2020/01/19 14:52:44 by cblasphe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_validate_tetri_chars(const char *tmp)
{
	int		i;
	int		hashes;
	int		returns;
	int		dots;

	i = 0;
	hashes = 0;
	returns = 0;
	dots = 0;
	if (ft_strlen(tmp) != TETRI_SIZE)
		return (0);
	while (tmp[i])
	{
		if (tmp[i] == '#')
			hashes++;
		else if (tmp[i] == '\n' && (i % 5 == 4))
			returns++;
		else if (tmp[i] == '.')
			dots++;
		else
			break ;
		i++;
	}
	return (tmp[i] == '\0' && hashes == TETRI_WIDTH && returns == TETRI_WIDTH);
}

int		ft_tabcmp(int *tab, int *arr)
{
	int		i;
	int		n;

	i = 0;
	n = 8;
	while (i < n && tab[i] == arr[i])
		i++;
	return (i == n);
}

int		ft_compare_templates(int *points)
{
	return (ft_tabcmp(points, I) || ft_tabcmp(points, IH)
	|| ft_tabcmp(points, O) || ft_tabcmp(points, L)
	|| ft_tabcmp(points, LR) || ft_tabcmp(points, LD)
	|| ft_tabcmp(points, LL) || ft_tabcmp(points, J)
	|| ft_tabcmp(points, JR) || ft_tabcmp(points, JD)
	|| ft_tabcmp(points, JL) || ft_tabcmp(points, T)
	|| ft_tabcmp(points, TR) || ft_tabcmp(points, TD)
	|| ft_tabcmp(points, TL) || ft_tabcmp(points, S)
	|| ft_tabcmp(points, SR) || ft_tabcmp(points, Z) || ft_tabcmp(points, ZR));
}

int		*ft_validate_tetri_map(char *map)
{
	int		*intmap;

	if (!map || !*map)
		return (NULL);
	if (!ft_validate_tetri_chars(map))
		return (NULL);
	intmap = ft_store_coords(map);
	if (!ft_compare_templates(intmap))
	{
		ft_memdel((void**)&intmap);
		return (NULL);
	}
	return (intmap);
}

int		ft_validate_slashes(char *filename, t_tetri *head)
{
	int		fd;
	char	line[1];
	int		slashes;
	int		tetris_len;

	slashes = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0 || !head)
		return (0);
	while (read(fd, &line, 1))
	{
		if (line[0] == '\n')
			slashes++;
	}
	close(fd);
	tetris_len = ft_len_tetris(head);
	return (tetris_len * TETRI_WIDTH + tetris_len - 1 == slashes);
}
