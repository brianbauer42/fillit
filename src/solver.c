/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:50:09 by tpan              #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		reset_solution(char **grid)
{
	int i;

	i = 0;
	while (grid[i++])
		free(grid[i]);
	free(grid);
}

/*
** 
*/

int		attempt_place(t_etris *piece, char **tet_map, int col, int row)
{
	int i;
	int colrow;
	int **type;
	i = 0;
	colrow = (col * 10) + r;
	type = tet->type;
	while (i++ <4)
	{
		if ((type[i][1] < 0) && (col + type[i][1] < 0))
			return (0);
		if	(type[i] != '.')
			return (0);
	}
	place_piece(piece, tet_map, colrow, t_etris->letter);
	return (1);
}

/*
**
*/

static int		solve_grid(t_etris *piece, char **map, int map_size) 
{
	int			col;
	int			row;
	t_coord		coords;

	row = 0;
	while (row < (map_size - piece->height) + 1)
	{
		col = 0;
		while (col < (map_size - piece->width) + 1)
		{
			if (attempt_place(piece, map, col, row))
			{
				if (solve_grid(piece->next, map, map_size))
					return(1);
				coords->row = row;
				coords->col = col;
				//colrow = (col * 10) + row;
				place_piece(piece, map, coords, '.');
			}
			col++;
		}
		row++;
	}
	return (0);
}

void	place_piece(t_etris *piece, t_etris **small_grid, int colrow, char mark)
{
	int i;
	int j;

	i = 0;
	while (i < piece->height)
	{
		j = 0;
		while (j < piece->width)
		{
			if (piece->x[j][i] == '#')
				map->array[t_etris->y + j][t_etris->x + i] = mark;
			j++;
		}
		i++;
	}
}
