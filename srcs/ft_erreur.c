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

#include "libft.h"
#include "ft_ls.h"

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
		ft_putstr(str);
		if (code == 1)
			ft_putstr_fd(" ls: Permission denied \n", 2);
		else if (code == 5)
			ft_putstr_fd(" : No such file or directory ", 2);
		else if (code == 7)
			ft_putstr_fd(" : Permission denied \n", 2);
	}
}

int		check_param(char *str)
{
	struct stat	info;

	if (lstat(str, &info) == -1)
		return (3);
	if (S_ISDIR(info.st_mode))
		return (1);
	if (S_ISLNK(info.st_mode))
		return (2);
	if (info.st_mode & S_IXUSR && info.st_mode & S_IXGRP
	&& info.st_mode & S_IXOTH)
		return (4);
	return (0);
}

void	check_exist(char *str, t_dir *tmp)
{
	DIR				*dir;
	struct dirent	*ret;

	if (!(dir = opendir(".")))
		ft_code_erreur(1, str);
	while ((ret = readdir(dir)))
	{
		if (ft_strcmp(tmp->elem, ret->d_name) == 0)
			tmp->printme = 0;
		else
			tmp->printme = 5;
	}
	if (tmp->printme == 5)
		ft_code_erreur(5, str);
}
