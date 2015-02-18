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

void	ft_sort_time_file(t_file *file)
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

void	ft_swap(t_file *file)
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

void	ft_data(char *fullname, t_file *new)
{
	struct stat *ret;

	if (!(ret = (struct stat *)malloc(sizeof(struct stat))))
		ft_code_erreur(3);
	if (lstat(fullname, ret) == -1)
			ft_code_erreur(4);
	new->data = ret;
	new->time_sec = new->data->st_mtime;
}

// void	ft_sort_time_dir(t_dir *dir)
// {
// 	t_dir	*tmp;
// 	t_dir	*tmp2;
// 	char	*swap;

// 	tmp = dir;
// 	while (tmp && tmp->next)
// 	{
// 		tmp2 = tmp->next;
// 		if (tmp->start->time_sec < tmp2->start->time_sec)
// 		{
// 			swap = tmp->elem;
// 			tmp->elem = tmp2->elem;
// 			tmp2->elem = swap;
// 			tmp = dir;
// 		}
// 		else
// 			tmp = tmp->next;
// 	}
// }

/* ===========> A faire TRI des repertoires en -t */
