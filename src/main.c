/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 14:00:54 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 02:11:39 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/filler.h"

int		get_map(t_flr *box)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau ") == NULL)
		return (filler_error(box, "0001"));
	box->map_y = ft_atoi(ft_strchr(line, ' '));
	box->map_x = ft_atoi(ft_strrchr(line, ' '));
	ft_strdel(&line);
	if (!(box->map = malloc(sizeof(char *) * box->map_y)))
		return (filler_error(box, "0001"));
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < box->map_y)
	{
		get_next_line(0, &line);
		box->map[i] = line;
		i++;
	}
	return (1);
}

int     main(void)
{
	t_flr	*box;
	char	*line;

	if (!(box = malloc(sizeof(t_flr))))
		return (0);
	get_next_line(0, &line);
	if (ft_strstr(line, "$$$ exec p") == NULL)
		return (filler_error(box, "0001"));
	UPLAYER = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
	ft_strdel(&line);
	while (1)
	{
		if (get_map(box) == 0 || get_piece(box) == 0)
			return (0);
		box->hmap_y = box->map_y;
		create_hmap(box);
		solver(box);
		if (box->best[2] == 1000000)
			break ;
		filler_error(box, "1110");
	}
	filler_error(box, "1111");
}