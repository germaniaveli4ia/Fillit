/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trial.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblasphe <cblasphe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:10:53 by cblasphe          #+#    #+#             */
/*   Updated: 2020/01/16 22:07:29 by cblasphe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_coords_empty(char **grid, int *coords, int off_x, int off_y)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < TETRI_WIDTH * 2)
	{
		x = coords[i] + off_x;
		y = coords[i + 1] + off_y;
		if (grid[y][x] != '.')
			return (0);
		i += 2;
	}
	return (1);
}

int		ft_coords_exists(int *coords, int grid_size, int off_x, int off_y)
{
	int	i;
	int	max_x;
	int	max_y;

	i = 2;
	max_x = coords[0];
	max_y = coords[1];
	while (i < TETRI_WIDTH * 2)
	{
		if (max_x < coords[i])
			max_x = coords[i];
		if (max_y < coords[i + 1])
			max_y = coords[i + 1];
		i += 2;
	}
	return (off_x + max_x < grid_size && off_y + max_y < grid_size);
}

void	ft_draw_coords(char **grid, int *coords, char c, t_point point)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < TETRI_WIDTH * 2)
	{
		x = coords[i] + point.x;
		y = coords[i + 1] + point.y;
		grid[y][x] = c;
		i += 2;
	}
}

int		ft_place_tetri(char **grid, t_tetri *tetri, int size, t_point point)
{
	t_point zero;

	zero.x = 0;
	zero.y = 0;
	if (!tetri)
		return (1);
	if (!ft_coords_exists(tetri->coords, size, point.x, point.y))
		return (0);
	if (ft_coords_empty(grid, tetri->coords, point.x, point.y))
	{
		ft_draw_coords(grid, tetri->coords, tetri->c, point);
		END_CASE(ft_place_tetri(grid, tetri->next, size, zero));
		ft_draw_coords(grid, tetri->coords, '.', point);
	}
	if (ft_coords_exists(tetri->coords, size, point.x + 1, point.y))
	{
		point.x += 1;
		return (ft_place_tetri(grid, tetri, size, point));
	}
	else
	{
		point.x = 0;
		point.y += 1;
		return (ft_place_tetri(grid, tetri, size, point));
	}
}

int		ft_fillit(t_tetri *head)
{
	int		size;
	char	**grid;
	t_point	point;

	point.x = 0;
	point.y = 0;
	size = ft_find_min_grid_size(head);
	grid = ft_make_empty_grid(size);
	while (!ft_place_tetri(grid, head, size, point))
	{
		ft_free_grid(grid, size);
		grid = ft_make_empty_grid(++size);
	}
	ft_print_grid(grid, size);
	ft_free_grid(grid, size);
	ft_free_tetris(head);
	return (0);
}
