/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblasphe <cblasphe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:23:44 by cblasphe          #+#    #+#             */
/*   Updated: 2020/01/11 20:40:02 by cblasphe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*ft_normalize_y(int *points)
{
	int y;
	int miny;

	y = 1;
	miny = points[y];
	while (y < TETRI_WIDTH * 2)
	{
		if (miny > points[y])
			miny = points[y];
		y += 2;
	}
	y = 1;
	while (y < TETRI_WIDTH * 2)
	{
		points[y] = points[y] - miny;
		y += 2;
	}
	return (points);
}

int	*ft_normalize_x(int *points)
{
	int x;
	int minx;

	x = 0;
	minx = points[x];
	while (x < TETRI_WIDTH * 2 - 1)
	{
		if (minx > points[x])
			minx = points[x];
		x += 2;
	}
	x = 0;
	while (x < TETRI_WIDTH * 2 - 1)
	{
		points[x] = points[x] - minx;
		x += 2;
	}
	return (points);
}

int	*ft_normalize_coords(int *points)
{
	ft_normalize_x(points);
	ft_normalize_y(points);
	return (points);
}

int	*ft_store_coords(char *buf)
{
	int x;
	int y;
	int i;
	int *points;

	x = 0;
	y = 0;
	i = 0;
	if (!(points = (int *)malloc(sizeof(int) * (TETRI_WIDTH * 2))))
		return (NULL);
	while (*buf)
	{
		if (*buf == '#')
		{
			points[i++] = x;
			points[i++] = y;
		}
		x = (*buf == '\n') ? 0 : x + 1;
		if (*buf == '\n')
			y++;
		buf++;
	}
	ft_normalize_coords(points);
	return (points);
}
