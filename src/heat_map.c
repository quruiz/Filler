/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heat_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 16:27:52 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 02:10:39 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/filler.h"

int		check_around(t_flr *box, int y, int x, int c)
{
	if (x - 1 >= 0 && y - 1 >= 0 && box->hmap[y - 1][x - 1] == c)
		return (1);
	if (y - 1 >= 0 && box->hmap[y - 1][x] == c)
		return (1);
	if (x + 1 < box->map_x && y - 1 >= 0 && box->hmap[y - 1][x + 1] == c)
		return (1);
	if (x - 1 >= 0 && box->hmap[y][x - 1] == c)
		return (1);
	if (x + 1 < box->map_x && box->hmap[y][x + 1] == c)
		return (1);
	if (x - 1 >= 0 && y + 1 < box->map_y && box->hmap[y + 1][x - 1] == c)
		return (1);
	if (y + 1 < box->map_y && box->hmap[y + 1][x] == c)
		return (1);
	if (x + 1 < box->map_x && y + 1 < box->map_y && box->hmap[y + 1][x + 1] == c)
		return (1);
	return (0);
}

void	fill_hmap(t_flr *box, int c)
{
	int		i;
	int		j;

	i = 0;
	while (i < box->map_y)
	{
		j = 0;
		while (j < box->map_x)
		{
			if (check_around(box, i, j, c) && box->hmap[i][j] == 0)
			{
				if (c == -1)
					box->hmap[i][j] = 1;
				else
					box->hmap[i][j] = c + 1;
			}
			j++;
		}
		i++;
	}
}

void	init_hmap(t_flr *box, char *line, int len, int j)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (line[i] == OPLAYER || line[i] == OPLAYER + 32)
			box->hmap[j][i] = -1;
		if (line[i] == UPLAYER || line[i] == UPLAYER + 32)
			box->hmap[j][i] = -2;
		if (line[i] == '.')
			box->hmap[j][i] = 0;
		i++;
	}
}

int		create_hmap(t_flr *box)
{
	int 	i;
	int		max;

	i = 0;
	max = ((box->map_x > box->map_y) ? box->map_x : box->map_y);
	if (!(box->hmap = malloc(sizeof(int *) * box->map_y + 1)))
		return (filler_error(box, "1011"));
	while (i < box->map_y)
	{
		if (!(box->hmap[i] = malloc(sizeof(int) * box->map_x + 1)))
		{
			box->hmap_y = i;
			return (filler_error(box, "1111"));
		}
		init_hmap(box, (box->map[i] + 4), box->map_x, i);
		i++;
	}
	i = 1;
	fill_hmap(box, -1);
	while (i < max)
	{
		fill_hmap(box, i);
		i++;
	}
	return (0);
}