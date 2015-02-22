/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 11:27:20 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/08 18:00:12 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_ls.h"

int		*init_zero(int *tab)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

void	straight_list(int *tab, t_dir *dir)
{
	t_dir	*tmp;

	tmp = dir;
	ft_sort_arg(tmp, tab);
	while (tmp)
	{
		ft_ls(tmp, tmp->elem, tab);
		if (tab[2] == 1)
			tmp->total = cal_total(tmp->start, tmp->elem);
		tmp = tmp->next;
	}
	if (tab[3] == 1)
	{
		ft_sort_time_dir(dir);
		ft_sort_time_file(dir->start);
	}
	if (tab[4] == 1)
		ft_recurse_sort(dir, tab);
}

int		main(int ac, char **av)
{
	int		tab[5];
	int		i;
	t_dir	*dir;
	int		c;

	ac = ac;
	init_zero(tab);
	dir = NULL;
	i = 0;
	while (av[++i])
	{
		if (*av[i] == '-')
			check_opt(tab, av[i]);
		else
			ft_add_dir(&dir, av[i], tab);
	}
	c = count(dir);
	if (c == 0)
		ft_add_dir(&dir, ".", tab);
	straight_list(tab, dir);
	if (tab[4] == 1)
		c = count(dir);
	ft_print_ls(dir, c, tab);
	return (0);
}
