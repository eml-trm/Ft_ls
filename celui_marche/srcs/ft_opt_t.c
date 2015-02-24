/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 13:42:08 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/11 13:42:10 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"

void		ft_sort_time_file(t_file *file)
{
	t_file	*tmp;
	t_file	*tmp2;

	tmp = file;
	while (tmp && tmp->next)
	{
		tmp2 = tmp->next;
		if (tmp->time_sec < tmp2->time_sec)
		{
			ft_swap(tmp);
			tmp = file;
		}
		else
			tmp = tmp->next;
	}
}

void		ft_swap(t_file *file)
{
	char	*swap;
	time_t	tswap;
	void	*sswap;

	swap = file->content;
	tswap = file->time_sec;
	sswap = file->data;
	file->content = file->next->content;
	file->time_sec = file->next->time_sec;
	file->data = file->next->data;
	file->next->content = swap;
	file->next->time_sec = tswap;
	file->next->data = sswap;
}

void		ft_swap_dir(t_dir *dir, char printme)
{
	char	*swap;
	t_file	*lswap;
	void	*sswap;
	time_t	tswap;
	size_t	bswap;

	swap = dir->elem;
	lswap = dir->start;
	sswap = dir->info;
	tswap = dir->mtime;
	bswap = dir->total;
	printme = dir->printme;
	dir->elem = dir->next->elem;
	dir->start = dir->next->start;
	dir->info = dir->next->info;
	dir->mtime = dir->next->mtime;
	dir->total = dir->next->total;
	dir->printme = dir->next->printme;
	dir->next->elem = swap;
	dir->next->start = lswap;
	dir->next->info = sswap;
	dir->next->mtime = tswap;
	dir->next->total = bswap;
	dir->next->printme = printme;
}

void		ft_sort_time_dir(t_dir *dir)
{
	t_dir	*tmp;
	t_dir	*tmp2;
	char 	printme;

	tmp = dir;
	printme = '\0';
	while (tmp && tmp->next)
	{
		tmp2 = tmp->next;
		if (tmp->mtime < tmp2->mtime)
		{
			ft_swap_dir(tmp, printme);
			tmp = dir;
		}
		else
			tmp = tmp->next;
	}
}
