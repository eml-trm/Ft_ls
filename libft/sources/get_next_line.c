/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 17:46:03 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/03 10:16:21 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_copy(char **line, char **str)
{
	int		len;
	char	*mem;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	mem = (char*)ft_memalloc(sizeof(char) * len + 1);
	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
	{
		mem[len] = (*str)[len];
		len++;
	}
	mem[len] = '\0';
	if (*line)
		*line = ft_strjoin(*line, mem);
	else
		*line = *str;
	if ((*str)[len] == '\n')
	{
		*str = &(*str)[len + 1];
		return (1);
	}
	return (0);
}

int		get_next_read(int fd, char **str)
{
	int		i;
	char	*buff;

	buff = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	i = read(fd, buff, BUFF_SIZE);
	if (i == -1)
		return (-1);
	*str = buff;
	return (i);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	static char *str;

	*line = 0;
	if (BUFF_SIZE < 1 || !line)
		return (-1);
	if (str != 0)
	{
		if (get_next_copy(line, &str) == 1)
			return (1);
	}
	ret = 1;
	while (ret)
	{
		ret = get_next_read(fd, &str);
		if (ret == -1)
			return (-1);
		if (get_next_copy(line, &str) == 1)
			return (1);
	}
	return (ret);
}
