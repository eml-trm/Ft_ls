/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 11:16:31 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/08 17:52:33 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include "libft.h"
#include "ft_ls.h"

void	ft_print_ls(t_dir *tmp, int c, int *tab)
{
	t_file	*file;

	while (tmp)
	{
		if (tmp->printme == 0)
		{
			ft_code_erreur(5, tmp->elem);
			tmp = tmp->next;
			continue;
		}
		if (c >= 2 && (check_param(tmp->elem) == 1))
		{
			ft_putstr(tmp->elem);
			ft_putendl(":");
		}
		file = tmp->start;
		if (tab[1] == 1 && check_param(tmp->elem) == 1)
		{
			if (tab[2] == 1 && (file == tmp->start))
			{
				ft_putstr("total ");
				ft_putnbr(tmp->total);
				ft_putchar('\n');
			}
			ft_ls_r(tmp->start, tmp, tab);
		}
		else
			ft_loop_prnt(file, tmp, tab);
		if (c >= 2 && tmp->next)
			ft_putchar('\n');
		tmp = tmp->next;
	}
}

void	ft_loop_prnt(t_file *file, t_dir *tmp, int *tab)
{
	while (file)
	{
		if (tab[2] == 1 && (file == tmp->start) && check_param(tmp->elem) == 1)
		{
			ft_putstr("total ");
			ft_putnbr(tmp->total);
			ft_putchar('\n');
		}
		if (tab[2] == 1)
			ft_print_info(file, tmp->elem);
		else
			ft_putendl(file->content);
		file = file->next;
	}
}

int		count(t_dir *dir)
{
	int		i;

	i = 0;
	while (dir)
	{
		i++;
		dir = dir->next;
	}
	return (i);
}

void	ft_ls_r(t_file *file, t_dir *dir, int *tab)
{
	t_file	*tmp;

	tmp = file;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		if (tab[2] == 1)
			ft_print_info(tmp, dir->elem);
		else
			ft_putendl(tmp->content);
		tmp = tmp->prev;
	}
}
