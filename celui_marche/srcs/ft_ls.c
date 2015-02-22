/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 16:55:32 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/20 19:37:20 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <uuid/uuid.h>
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include "libft.h"
#include "ft_ls.h"

void	ft_ls(t_dir *param, char *str, int *tab)
{
	t_file *file;
	if (check_param(str) == 1)
		read_dir(param, str, tab);
	else if (check_param(str) == 3)
		param->printme = 0;
	else
		ft_add_list(&file, param->elem, param->elem, tab);
}

t_file	*init(void)
{
	t_file *file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		ft_code_erreur(3, NULL);
	if (!(file->data = (struct stat *)malloc(sizeof(struct stat))))
		ft_code_erreur(3, NULL);
	file->content = NULL;
	file->next = NULL;
	file->prev = NULL;
	file->data = NULL;
	file->time_sec = 0;
	file = NULL;
	return (file);
}

void	read_dir(t_dir *param, char *str, int *tab)
{
	DIR				*dir;
	struct dirent	*ret;
	t_file			*file;
	char			*fullname;

	file = init();

	if (!(dir = opendir(str)))
	{
		ft_code_erreur(1, str);
		return ;
	}
	while ((ret = readdir(dir)))
	{
		fullname = ft_strcjoin(str, ret->d_name, '/');
		if (tab[4] == 1)
		{
			if (!(ft_strequ(ret->d_name, ".") || ft_strequ(ret->d_name, "..")))
			ft_recursive(fullname, param);
		}
		if ((tab[0] != 1) && (ret->d_name[0] == '.'))
			continue;
		ft_add_list(&file, fullname, ret->d_name, tab);
	}
	if ((ft_cmp_list(file)) != (-1))
		ft_change_list(file);
	param->start = file;
}

void	ft_print_info(t_file *file, char *dir)
{
	static char	buf[2048];
	char		*join;

	print_right(file->data);
	print_nbr_link(file, 0, 0);
	print_uid(file, 0, 0);
	print_grp(file, 0, 0);
	print_nbr_sze(file, 0, 0);
	ft_time(file, 0, 0);
	ft_putstr(file->content);
	if (S_ISLNK(file->data->st_mode))
	{
		join = ft_strcjoin(dir, file->content, '/');
		ft_putstr(" -> ");
		ft_memset(buf, 0, 2048);
		readlink(join, buf, 2048);
		ft_putstr(buf);
		free(join);
	}
	ft_putchar('\n');
}
