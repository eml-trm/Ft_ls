/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 12:02:34 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/08 17:48:57 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_ls.h"

void	ft_code_erreur(int code)
{
	if (code == 0)
		ft_putstr_fd("usage : ./ft_ls [-option] [oth ...]\n", 2);
	else
	{
		ft_putstr_fd("ERROR: ", 2);
		if (code == 1)
			ft_putstr_fd("Can't open directory\n", 2);
		else if (code == 2)
			ft_putstr_fd("ls: illegal option -- -\n", 2);
		else if (code == 3)
			ft_putstr_fd("Malloc error\n", 2);
		else if (code == 4)
			ft_putstr_fd("Stat\n", 2);
		else if (code == 5)
			ft_putstr_fd("No such file or directory\n", 2);
	}
	exit (0);
}

int		check_param(char *str)
{
	struct stat 	info;

	if (stat(str, &info) == -1)
		ft_code_erreur(5);
	if (S_ISDIR(info.st_mode))
		return (1);
	return (0);
}
