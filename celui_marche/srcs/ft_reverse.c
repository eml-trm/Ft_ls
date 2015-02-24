/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 15:25:43 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/14 15:25:45 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include "ft_ls.h"

int		ft_cmp_dir_rev(t_dir *dir)
{
	int		i;

	i = 0;
	if (dir == NULL)
		return (3);
	while (dir && dir->next)
	{
		if (ft_strcmp(dir->elem, dir->next->elem) < 0)
			return (i);
		dir = dir->next; 
	}
	return (3);
}

void	ft_change_dir_rev(t_dir *dir)
{
	int		i;
	t_dir	*tmp;
	char	printme;

	i = 0;
	printme = '\0';

	while ((i = ft_cmp_dir_rev(dir)) < 0)
	{printf("LALALALA\n");               //      ----------> A modifier ne fonctuonne pas 
		printf("i == %d\n", i);
		tmp = dir;
		while (i > 0)
		{
			tmp = tmp->next;
			i--;
		}
		ft_swap_dir(tmp, printme);
	}
}
