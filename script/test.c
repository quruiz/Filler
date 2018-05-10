/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 17:03:48 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 20:03:33 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/filler.h"

int			main(void)
{
	char	*line;
	int		me;
	int		he;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (dprintf(1, "vm_error\n"));
	he = atoi(line);
	if (get_next_line(0, &line) <= 0)
		return (dprintf(1, "vm_error\n"));
	me = atoi(line);
	me < he ? dprintf(1, "LOOSE ") : dprintf(1, "WIN ");
	dprintf(1, "(me = %d him = %d)\n", me, he);
	return (0);
}
