/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:58:43 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/06/03 21:58:44 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_mvupp(t_data *data, int linelen)
{
	int	i;

	i = 0;
	while (data->strfd[i])
	{
		if (data->strfd[i] == 'P' && data->strfd[i - (linelen + 1)] != '1')
		{
			if (data->strfd[i - (linelen + 1)] == 'C')
				data->nbcheese--;
			if (data->strfd[i - (linelen + 1)] == 'E')
			{
				if (data->nbcheese == 0)
					ft_clearall(data);
				else
					break ;
			}
			data->strfd[i] = '0';
			data->strfd[i - (linelen + 1)] = 'P';
			data->nbmv++;
			ft_loadmap(data);
			break ;
		}
		i++;
	}
}

static void	ft_mvdwn(t_data *data, int linelen)
{
	int	i;

	i = 0;
	while (data->strfd[i])
	{
		if (data->strfd[i] == 'P' && data->strfd[i + (linelen + 1)] != '1')
		{
			if (data->strfd[i + (linelen + 1)] == 'C')
				data->nbcheese--;
			if (data->strfd[i + (linelen + 1)] == 'E')
			{
				if (data->nbcheese == 0)
					ft_clearall(data);
				else
					break ;
			}
			data->strfd[i] = '0';
			data->strfd[i + (linelen + 1)] = 'P';
			data->nbmv++;
			ft_loadmap(data);
			break ;
		}
		i++;
	}
}

static void	ft_mvlft(t_data *data)
{
	int	i;

	i = 0;
	while (data->strfd[i])
	{
		if (data->strfd[i] == 'P' && data->strfd[i - 1] != '1')
		{
			if (data->strfd[i - 1] == 'C')
				data->nbcheese--;
			if (data->strfd[i - 1] == 'E')
			{
				if (data->nbcheese == 0)
					ft_clearall(data);
				else
					break ;
			}
			data->strfd[i] = '0';
			data->strfd[i - 1] = 'P';
			data->pov = 'l';
			data->nbmv++;
			ft_loadmap(data);
			break ;
		}
		i++;
	}
}

static void	ft_mvrgt(t_data *data)
{
	int	i;

	i = 0;
	while (data->strfd[i])
	{
		if (data->strfd[i] == 'P' && data->strfd[i + 1] != '1')
		{
			if (data->strfd[i + 1] == 'C')
				data->nbcheese--;
			if (data->strfd[i + 1] == 'E')
			{
				if (data->nbcheese == 0)
					ft_clearall(data);
				else
					break ;
			}
			data->strfd[i] = '0';
			data->strfd[i + 1] = 'P';
			data->pov = 'r';
			data->nbmv++;
			ft_loadmap(data);
			break ;
		}
		i++;
	}
}

int	ft_loopmv(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_clearall(data);
	else if (keycode == 'W' || keycode == 'w')
		ft_mvupp(data, data->linelen);
	else if (keycode == 'S' || keycode == 's')
		ft_mvdwn(data, data->linelen);
	else if (keycode == 'A' || keycode == 'a')
		ft_mvlft(data);
	else if (keycode == 'D' || keycode == 'd')
		ft_mvrgt(data);
	return (0);
}
