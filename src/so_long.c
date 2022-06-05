/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:08:30 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/06/02 10:28:31 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_errors(t_data *data)
{
	if (data->ac != 2)
	{
		write(2, "Error\nInvalid argument\n", 23);
		return (-1);
	}
	data->fd = open(data->map, O_RDONLY);
	if (data->fd == -1)
	{
		write(2, "Error\nNo such file\n", 19);
		return (-1);
	}
	if (check_map(data) == -1)
	{
		write(2, "Error\nInvalid map\n", 18);
		return (close(data->fd), -1);
	}
	return (close(data->fd), 0);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.ac = ac;
	data.map = av[1];
	if (check_errors(&data) == -1)
		return (0);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (data.linelen * 64),
			(data.nblen * 64), "SO_LONG");
	data.pov = 'r';
	data.nbmv = 0;
	ft_loadmap(&data);
	mlx_key_hook(data.win, ft_loopmv, &data);
	mlx_hook(data.win, 17, 0, ft_clearall, &data);
	mlx_loop(data.mlx);
	return (0);
}
