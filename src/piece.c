/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   piece.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 16:29:01 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/14 13:39:43 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/filler.h"

int		get_piece_coor(t_flr *box, int i, int start, char *line)
{
	int j;

	j = 0;
	while (j < box->piece_x)
	{
		if (line[j] == '*')
		{
			box->coor[0] = ft_tab_realloc(box->coor[0], start, start + 1);
			box->coor[1] = ft_tab_realloc(box->coor[1], start, start + 1);
			box->coor[0][start] = i;
			box->coor[1][start] = j;
			start++;
		}
		j++;
	}
	return (start);
}

int		get_piece(t_flr *box)
{
	char	*line;
	int		start;
	int		i;

	i = -1;
	start = 0;
	get_next_line(0, &line);
	if (ft_strstr(line, "Piece ") == NULL)
	{
		ft_strdel(&line);
		return (filler_error(box, "1001"));
	}
	box->piece_y = ft_atoi(ft_strchr(line, ' '));
	box->piece_x = ft_atoi(ft_strrchr(line, ' '));
	ft_strdel(&line);
	if (!(box->coor = malloc(sizeof(int *) * 2)))
		return (filler_error(box, "1001"));
	while (++i < box->piece_y)
	{
		get_next_line(0, &line);
		start = get_piece_coor(box, i, start, line);
		ft_strdel(&line);
	}
	box->size = start;
	return (1);
}
