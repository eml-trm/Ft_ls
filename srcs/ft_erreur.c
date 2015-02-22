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
#include <stdbool.h>
#include "libft.h"
#include "ft_ls.h"

// void	ft_code_erreur(int code, char *str)
// {
// 	if (code == 0)
// 		ft_putstr_fd("usage : ./ft_ls [-option] [oth ...]\n", 2);
// 	else
// 	{
// 		ft_putstr_fd("ERROR: ", 2);
// 		if (code == 1)
// 			ft_putstr_fd("Permission denied: \n", 2);
// 		else if (code == 2)
// 			ft_putstr_fd("ls: illegal option -- -", 2);
// 		else if (code == 3)
// 		{
// 			ft_putstr_fd("Malloc error", 2);
// 			exit(0);
// 		}
// 		else if (code == 4)
// 			ft_putstr_fd("Stat", 2);
// 		else if (code == 5)
// 			ft_putstr_fd("No such file or directory: \n", 2);
// 		else if (code == 7)
// 			ft_putstr_fd("Permission denied: \n", 2);
// 	}
// 	ft_putendl(str);
// }

void	ft_code_erreur(int code, char *str)
{
	if (code == 0)
	{
		ft_putstr_fd("ls: illegal option -- - \n", 2);
		ft_putstr_fd("usage : ./ft_ls [-option] [file ...]\n", 2);
		exit(0);
	}
	else if (code == 3)
	{
		ft_putstr_fd("Malloc error", 2);
		exit(0);
	}
	else
	{
		ft_putstr_fd("ERROR: ", 2);
		ft_putstr(str);
		if (code == 1)
			ft_putstr_fd("  Permission denied \n", 2);
		else if (code == 5)
			ft_putstr_fd(" : No such file or directory ", 2);
		else if (code == 7)
			ft_putstr_fd(" : Permission denied \n", 2);
	}
}

int		check_param(char *str)
{
	struct stat	info;

	if (stat(str, &info) == -1)
		return (3);
	if (S_ISDIR(info.st_mode))
		return (1);
	return (0);
}
