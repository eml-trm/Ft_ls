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
		if (c >= 2 && (check_param(tmp->elem) == 1))
		{
			ft_putstr(tmp->elem);
			ft_putendl(":");
		}
		file = tmp->start;
		if (tab[1] == 1)
			ft_ls_r(tmp->start, tab);
		else
		{
			while (file)
			{
				if (tab[2] == 1 && file == tmp->start)
				{
					ft_putstr("total ");
					ft_putnbr(tmp->total);
					ft_putchar('\n');
				}
				if (tab[2] == 1)
				{
					ft_print_info(file, tmp->elem);
					//ft_ls_l(file);

				}
				else
					ft_putendl(file->content);
				file = file->next;
			}
		}
		if (c >= 2 && tmp->next)
			ft_putchar('\n');
		tmp = tmp->next;
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

void	ft_ls_r(t_file *file, int *tab)
{
	t_file	*tmp;

	tmp = file;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		if (tab[2] == 1)
			print_right(tmp->data);
		ft_putstr(tmp->content);
		if (tmp->content)
			ft_putchar('\n');
		tmp = tmp->prev;
	}
}
