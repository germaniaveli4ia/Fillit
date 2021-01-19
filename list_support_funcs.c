/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_support_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblasphe <cblasphe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:18:27 by cblasphe          #+#    #+#             */
/*   Updated: 2020/01/16 21:26:29 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_create(int *data, char c)
{
	t_tetri	*new;
	int		counter;

	counter = -1;
	if (!(new = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	new->coords = data;
	new->c = c;
	new->next = NULL;
	return (new);
}

t_tetri	*ft_add_first(t_tetri *cursor, int *info, char c)
{
	t_tetri *new_node;

	new_node = ft_create(info, c);
	new_node->next = cursor;
	return (cursor);
}

t_tetri	*ft_add_last(t_tetri *head, int *info)
{
	t_tetri		*cursor;
	t_tetri		*new_node;
	int			c;

	cursor = head;
	while (cursor->next)
		cursor = cursor->next;
	c = cursor->c;
	new_node = ft_create(info, ++c);
	cursor->next = new_node;
	return (head);
}

size_t	ft_len_tetris(t_tetri *cursor)
{
	size_t len;

	len = 0;
	while (cursor)
	{
		cursor = cursor->next;
		len++;
	}
	return (len);
}

void	ft_free_tetris(t_tetri *head)
{
	t_tetri *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		ft_memdel((void**)&tmp->coords);
		free(tmp);
	}
}
