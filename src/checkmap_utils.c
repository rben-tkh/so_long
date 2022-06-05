/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:25:07 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/06/02 01:06:18 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_ber(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (map[i - 4] != '.')
		return (-1);
	if (map[i - 3] != 'b')
		return (-1);
	if (map[i - 2] != 'e')
		return (-1);
	if (map[i - 1] != 'r')
		return (-1);
	return (0);
}

static char	*get_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	int		i;
	int		j;

	if ((!s1 && !s2) || (s1 && !s2))
		return (0);
	if (!s1 && s2)
		return (s2);
	strjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strjoin)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';
	return (free(s1), strjoin);
}

char	*get_strfd(int fd)
{
	char	*strfd;
	char	*buffer;
	int		i;

	strfd = malloc(sizeof(char));
	if (!strfd)
		return (0);
	strfd[0] = '\0';
	buffer = malloc(sizeof(char) * 101);
	if (!buffer)
		return (0);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, 100);
		if (i == -1)
			return (free(buffer), NULL);
		buffer[i] = '\0';
		strfd = get_strjoin(strfd, buffer);
	}
	return (free(buffer), strfd);
}

int	check_set(char c)
{
	char	*set;
	int		i;

	set = "01CEP";
	i = 0;
	if (c == '\n')
		return (0);
	while (set[i])
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (-1);
}
