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
		i++;
	}
	return (3);
}

void	ft_change_dir_rev(t_dir *dir)
{
	int		i;
	t_dir	*tmp;
	char	*stk;

	i = 0;
	while ((i = ft_cmp_dir(dir)) < 0)
	{
		tmp = dir;
		while (i > 0)
		{
			tmp = tmp->next;
			i--;
		}
		stk = tmp->elem;
		tmp->elem = tmp->next->elem;
		tmp->next->elem = ft_strdup(stk);
	}
}
