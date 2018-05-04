/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 14:03:17 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 18:11:35 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define OPLAYER ((box->player == 'O') ? 'X' : 'O')
# define UPLAYER box->player
# define MAPY box->map_y
# define MAPX box->map_x
# include "../libft/libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct			s_flr
{
	char				**map;
	int					**hmap;
	int					hmap_y;
	int					map_x;
	int					map_y;
	int					**coor;
	int					size;
	int					piece_x;
	int					piece_y;
	int					best[3];
	char				player;
}						t_flr;

int						get_piece(t_flr *box);
int						create_hmap(t_flr *box);
void					solver(t_flr *box);
int						filler_error(t_flr *box, char *code);

#endif
