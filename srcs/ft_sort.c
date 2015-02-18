/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 16:51:16 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/08 17:56:34 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_ls.h"

int		ft_cmp_list(t_file *file)
{
	int		i;

	i = 0;
	while (file->next != NULL)
	{
		if (ft_strcmp(file->content, file->next->content) > 0)
			return (i);
		file = file->next;
		i++;
	}
	return (-1);
}

void	ft_change_list(t_file *file)
{
	int		i;
	t_file	*tmp;

	i = 0;
	while ((i = ft_cmp_list(file)) > -1)
	{
		tmp = file;
		while (i > 0)
		{
			tmp = tmp->next;
			i--;
		}
		ft_swap(tmp);
	}
}

int		ft_cmp_dir(t_dir *dir)
{
	t_dir	*tmp;
	int		i;

	i = 0;
	tmp = dir;
	if (tmp == NULL)
		return (-1);
	while (tmp->next)
	{
		if (ft_strcmp(tmp->elem, tmp->next->elem) > 0)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	ft_change_dir(t_dir *dir)
{
	int		i;
	t_dir	*tmp;
	char	*stk;

	while ((i = ft_cmp_dir(dir)) > -1)
	{
		tmp = dir;
		while (i > 0)
		{
			tmp = tmp->next;
			i--;
		}
		stk = ft_strdup(tmp->elem);
		tmp->elem = ft_strdup(tmp->next->elem);
		tmp->next->elem = ft_strdup(stk);
	}
}

void	ft_sort_arg(t_dir *dir, int *tab)
{
	*tab = *tab;
	if (tab[1] == 1)
	{
		if ((ft_cmp_dir_rev(dir) != (3)))
			ft_change_dir_rev(dir);
	}
	else
		if ((ft_cmp_dir(dir)) != (-1))
			ft_change_dir(dir);
}
