/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblasphe <cblasphe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:43:53 by cblasphe          #+#    #+#             */
/*   Updated: 2020/01/16 21:35:12 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_min_grid_size(t_tetri *head)
{
	int		count;
	int		size;

	size = 2;
	count = ft_len_tetris(head);
	count *= 4;
	while (count > (size * size))
		++size;
	return (size);
}

void	ft_free_grid(char **grid, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&(grid[i]));
		i++;
	}
	free(grid);
	grid = NULL;
}

char	**ft_make_empty_grid(int size)
{
	int		i;
	char	**grid;

	i = 0;
	if (!(grid = (char **)malloc(sizeof(char*) * size)))
		return (NULL);
	while (i < size)
	{
		grid[i] = ft_strnew(size);
		ft_memset(grid[i], '.', size);
		i++;
	}
	return (grid);
}

void	ft_print_grid(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putendl(grid[i]);
		i++;
	}
}
