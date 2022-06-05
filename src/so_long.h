/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:07:34 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/06/02 10:26:33 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//-------------T_DATA-------------------
typedef struct s_data
{
	int					ac;
	char				*map;
	int					fd;
	char				*strfd;
	int					linelen;
	int					nblen;
	int					nbcheese;
	void				*mlx;
	void				*win;
	char				pov;
	unsigned int		nbmv;
	int					x;
	int					y;
	int					width;
	int					height;
	void				*empty;
	void				*bush;
	void				*cball;
	void				*oball;
	void				*cheese;
	void				*rrat;
	void				*lrat;
}				t_data;

//------------PARSING----------------
int		check_ber(char *map);
char	*get_strfd(int fd);
int		check_set(char c);
int		check_map(t_data *data);

//-------------GAME------------------
int		ft_clearall(t_data *data);
void	ft_loadmap(t_data *data);
int		ft_loopmv(int keycode, t_data *data);

#endif