/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:11:33 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/06/02 00:07:50 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall(char *strfd, t_data *data)
{
	int	i;

	i = 0;
	while (strfd[i] != '\n')
	{
		if (strfd[i] != '1')
			return (-1);
		i++;
	}
	if (i < 3)
		return (-1);
	data->linelen = i;
	while (strfd[i])
		i++;
	i -= data->linelen;
	while (strfd[i])
	{
		if (strfd[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_mid(char *strfd, t_data *data)
{
	int	i;

	i = 0;
	data->nblen = 1;
	while (strfd[i])
	{
		if (check_set(strfd[i]) == -1)
			return (-1);
		if (i > 0 && strfd[i - 1] == '\n' && strfd[i] != '1')
			return (-1);
		if (strfd[i + 1] == '\n' && strfd[i] != '1')
			return (-1);
		if (strfd[i] == '\n')
			data->nblen++;
		i++;
	}
	if (data->nblen < 3)
		return (-1);
	return (0);
}

static int	check_linelen(char *strfd, int linelen)
{
	int	i;
	int	j;

	i = 0;
	while (strfd[i])
	{
		j = 0;
		while (strfd[i] != '\n' && strfd[i])
		{
			j++;
			i++;
		}
		if (j != linelen)
			return (-1);
		if (strfd[i])
			i++;
	}
	return (0);
}

static int	check_char(t_data *data)
{
	int	*tab;
	int	i;
	int	c;

	tab = malloc(sizeof(int) * 127);
	if (!tab)
		return (0);
	i = 0;
	while (i < 127)
		tab[i++] = 0;
	i = 0;
	while (data->strfd[i])
	{
		if (data->strfd[i] == 'E' || data->strfd[i] == 'C'
			|| data->strfd[i] == 'P')
		{
			c = data->strfd[i];
			tab[c]++;
		}
		i++;
	}
	if (tab['E'] < 1 || tab['C'] < 1 || tab['P'] != 1)
		return (free(tab), -1);
	data->nbcheese = tab['C'];
	return (free(tab), 0);
}

int	check_map(t_data *data)
{
	if (check_ber(data->map) == -1)
		return (-1);
	data->strfd = get_strfd(data->fd);
	if (!data->strfd)
		return (free(data->strfd), -1);
	if (check_wall(data->strfd, data) == -1)
		return (free(data->strfd), -1);
	if (check_mid(data->strfd, data) == -1)
		return (free(data->strfd), -1);
	if (check_linelen(data->strfd, data->linelen) == -1)
		return (free(data->strfd), -1);
	data->nbcheese = 0;
	if (check_char(data) == -1)
		return (free(data->strfd), -1);
	return (0);
}
