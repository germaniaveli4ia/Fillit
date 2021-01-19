/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblasphe <cblasphe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:20:22 by cblasphe          #+#    #+#             */
/*   Updated: 2020/01/19 14:49:19 by cblasphe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define TETRI_WIDTH 4
# define TETRI_SIZE 20
# define END_CASE(x) if (x) return (1);

# define I (int [8]) {0,0,0,1,0,2,0,3}
# define IH (int [8]) {0,0,1,0,2,0,3,0}
# define O (int [8]) {0,0,1,0,0,1,1,1}
# define L (int [8]) {0,0,0,1,0,2,1,2}
# define LR (int [8]) {0,0,1,0,2,0,0,1}
# define LD (int [8]) {0,0,1,0,1,1,1,2}
# define LL (int [8]) {2,0,0,1,1,1,2,1}
# define J (int [8]) {1,0,1,1,0,2,1,2}
# define JR (int [8]) {0,0,0,1,1,1,2,1}
# define JD (int [8]) {0,0,1,0,0,1,0,2}
# define JL  (int [8]) {0,0,1,0,2,0,2,1}
# define T (int [8]) {1,0,0,1,1,1,2,1}
# define TR (int [8]) {0,0,0,1,1,1,0,2}
# define TD (int [8]) {0,0,1,0,2,0,1,1}
# define TL (int [8]) {1,0,0,1,1,1,1,2}
# define S (int [8]) {1,0,2,0,0,1,1,1}
# define SR (int [8]) {0,0,0,1,1,1,1,2}
# define Z (int [8]) {0,0,1,0,1,1,2,1}
# define ZR (int [8]) {1,0,0,1,1,1,0,2}

typedef struct		s_tetri
{
	int				*coords;
	char			c;
	struct s_tetri	*next;
}					t_tetri;
typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

int					ft_validate_tetri_chars(const char *tmp);
int					ft_tabcmp(int *tab, int *arr);
int					ft_compare_templates(int *coords);
int					*ft_store_coords(char *buf);
int					*ft_validate_tetri_map(char *map);
int					ft_validate_slashes(char *filename, t_tetri *head);

int					ft_fillit(t_tetri *head);

t_tetri				*ft_create(int *data, char c);
t_tetri				*ft_add_first(t_tetri *head, int *info, char c);
t_tetri				*ft_add_last(t_tetri *head, int *info);
size_t				ft_len_tetris(t_tetri *cursor);
void				ft_free_tetris(t_tetri *head);

char				**ft_make_empty_grid(int size);
void				ft_free_grid(char **grid, int size);
void				ft_print_grid(char **grid, int size);
int					ft_find_min_grid_size(t_tetri *head);

#endif
