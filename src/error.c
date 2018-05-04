/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 01:37:16 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 18:07:57 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/filler.h"

void	free_tab(char **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_tab_int(int **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		filler_error(t_flr *box, char *code)
{
	if (code[0] == '1')
		free_tab(box->map, box->map_y);
	if (code[1] == '1')
		free_tab_int(box->hmap, box->hmap_y);
	if (code[2] == '1')
		free_tab_int(box->coor, 2);
	if (code[3] == '1')
		free(box);
	return (0);
}
