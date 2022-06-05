/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:22:03 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/06/03 19:22:05 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_clearall(t_data *data)
{
	mlx_destroy_image(data->mlx, data->empty);
	mlx_destroy_image(data->mlx, data->bush);
	mlx_destroy_image(data->mlx, data->cball);
	mlx_destroy_image(data->mlx, data->oball);
	mlx_destroy_image(data->mlx, data->cheese);
	mlx_destroy_image(data->mlx, data->rrat);
	mlx_destroy_image(data->mlx, data->lrat);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->strfd);
	exit (0);
}

static void	ft_initxpm(t_data *data)
{
	data->empty = mlx_xpm_file_to_image(data->mlx, "img/empty.xpm",
			&data->width, &data->height);
	data->bush = mlx_xpm_file_to_image(data->mlx, "img/bush.xpm",
			&data->width, &data->height);
	data->cball = mlx_xpm_file_to_image(data->mlx, "img/cball.xpm",
			&data->width, &data->height);
	data->oball = mlx_xpm_file_to_image(data->mlx, "img/oball.xpm",
			&data->width, &data->height);
	data->cheese = mlx_xpm_file_to_image(data->mlx, "img/cheese.xpm",
			&data->width, &data->height);
	data->rrat = mlx_xpm_file_to_image(data->mlx, "img/rrat.xpm",
			&data->width, &data->height);
	data->lrat = mlx_xpm_file_to_image(data->mlx, "img/lrat.xpm",
			&data->width, &data->height);
}

static void	ft_putimg(t_data *data, int i)
{
	if (data->strfd[i] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->empty,
			(data->x * 64), (data->y * 64));
	else if (data->strfd[i] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->bush,
			(data->x * 64), (data->y * 64));
	else if (data->strfd[i] == 'E' && data->nbcheese != 0)
		mlx_put_image_to_window(data->mlx, data->win, data->cball,
			(data->x * 64), (data->y * 64));
	else if (data->strfd[i] == 'E' && data->nbcheese == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->oball,
			(data->x * 64), (data->y * 64));
	else if (data->strfd[i] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->cheese,
			(data->x * 64), (data->y * 64));
	else if (data->strfd[i] == 'P' && data->pov == 'r')
		mlx_put_image_to_window(data->mlx, data->win, data->rrat,
			(data->x * 64), (data->y * 64));
	else if (data->strfd[i] == 'P' && data->pov == 'l')
		mlx_put_image_to_window(data->mlx, data->win, data->lrat,
			(data->x * 64), (data->y * 64));
}

static void	ft_putnbr(unsigned int nb)
{
	char	x;

	if (nb > 9)
		ft_putnbr(nb / 10);
	x = '0' + (nb % 10);
	write(1, &x, 1);
}

void	ft_loadmap(t_data *data)
{
	int	i;

	i = 0;
	data->x = 0;
	data->y = 0;
	ft_putnbr(data->nbmv);
	write(1, "\n", 1);
	if (data->nbmv == 0)
		ft_initxpm(data);
	while (data->strfd[i])
	{
		if (data->strfd[i] == '\n')
		{
			data->x = -1;
			data->y++;
		}
		ft_putimg(data, i);
		i++;
		data->x++;
	}
}
