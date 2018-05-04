/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 17:31:16 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 18:08:31 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/filler.h"

void	save_score(t_flr *box, int i, int j, int score)
{
	box->best[0] = i;
	box->best[1] = j;
	box->best[2] = score;
}

int		is_possible(t_flr *box, int i, int j)
{
	int		cross;
	int		score;
	int		x;
	int		y;
	int		k;

	k = 0;
	cross = 0;
	score = 0;
	while (k < box->size)
	{
		y = i + box->coor[0][k];
		x = j + box->coor[1][k];
		if (box->hmap[y][x] == -1)
			return (0);
		if (box->hmap[y][x] == -2)
			cross++;
		if (box->hmap[y][x] > 0)
			score += box->hmap[y][x];
		k++;
	}
	if (cross == 1 && score < box->best[2])
		save_score(box, i, j, score);
	return (1);
}

void	solver(t_flr *box)
{
	int		i;
	int		j;

	i = 0;
	save_score(box, 0, 0, 1000000);
	while (i < (box->map_y - box->piece_y))
	{
		j = 0;
		while (j < (box->map_x - box->piece_x))
		{
			is_possible(box, i, j);
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", box->best[0], box->best[1]);
}
