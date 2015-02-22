/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 15:42:22 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/21 15:42:25 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_ls.h"

void		ft_add_end(t_dir *dir, char *fullname)
{
	t_dir	*tmp;
	t_dir	*new;

	tmp = dir;
	new = ft_new_endlist(fullname);
	new->next = NULL;
	new->prev = NULL;
	while (tmp)
	{
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	tmp->next = new;
	new->prev = tmp;
}

t_dir		*ft_new_endlist(char *elem)
{
	t_dir	*tmp;

	if (!(tmp = (t_dir *)malloc(sizeof(t_dir))))
		ft_code_erreur(3, NULL);
	tmp->elem = ft_strdup(elem);
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void		ft_recursive(char *fullname, t_dir *dir)
{
	if (check_param(fullname) == 1)
		ft_add_end(dir, fullname);
}

void		ft_recurse_sort(t_dir *dir, int *tab)
{
	if (tab[3] == 1)
	{
		ft_sort_time_dir(dir);
		ft_sort_time_file(dir->start);
	}
	else
		ft_sort_arg(dir, tab);
}
