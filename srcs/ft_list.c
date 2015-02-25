/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 09:35:24 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/08 17:49:38 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_add_list(t_file **alst, char *fullname, char *name, int *tab)
{
	t_file	*new;
	t_file	*tmp;

	new = ft_new_list(name);
	if (tab[2] == 1 || tab[3] == 1)
		ft_data(fullname, new);
	new->next = NULL;
	new->prev = NULL;
	tmp = NULL;
	list(alst, new, tmp);
}

void	list(t_file **alst, t_file *new, t_file *tmp)
{
	if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = (*alst);
		while (tmp)
		{
			if (!(tmp->next))
				break ;
			tmp = tmp->next;
		}
	}
	if (new == *alst)
		new->prev = NULL;
	else
	{
		tmp->next = new;
		new->prev = tmp;
	}
}

t_file	*ft_new_list(char *content)
{
	t_file *tmp;

	if (!(tmp = (t_file *)malloc(sizeof(t_file))))
		ft_code_erreur(3, NULL);
	tmp->content = ft_strdup(content);
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	ft_add_dir(t_dir **start, char *name, int *tab)
{
	t_dir	*new;

	new = ft_new_dir(name);
	if (tab[2] == 1 || tab[3] == 1)
		ft_data_dir(name, new);
	if (*start == NULL)
		*start = new;
	else
	{
		new->prev = NULL;
		new->next = (*start);
		(*start)->prev = new;
		(*start) = new;
	}
}

t_dir	*ft_new_dir(char *elem)
{
	t_dir	*tmp;

	tmp = (t_dir *)malloc(sizeof(t_dir));
	tmp->elem = ft_strdup(elem);
	tmp->prev = NULL;
	tmp->next = NULL;
	tmp->start = NULL;
	tmp->printme = 1;
	return (tmp);
}
