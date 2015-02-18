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
	if (check_param(str) == 1)
		read_dir(param, str, tab);
	else
		ft_putendl(str);
}

t_file	*init()
{
	t_file *file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		ft_code_erreur(3);
	if (!(file->data = (struct stat *)malloc(sizeof(struct stat))))
		ft_code_erreur(3);
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
	dir = NULL;
	if (!(dir = opendir(str)))
		ft_code_erreur(1);
	while ((ret = readdir(dir)))
	{
		fullname = ft_strcjoin(str, ret->d_name, '/');
		if ((tab[0] != 1) && (ret->d_name[0] == '.'))
			continue;
		ft_add_list(&file, fullname, ret->d_name, tab);
	}
	if ((ft_cmp_list(file)) != (-1))
		ft_change_list(file);
	param->total = cal_total(file, str);
	if (tab[3] == 1)
	{
		ft_sort_time_file(file);
		//ft_sort_time_dir(param);
	}
	param->start = file;
}

void	ft_print_info(t_file *file)
{
	print_right(file->data);
	print_nbr_link(file, 0, 0);
	print_uid(file, 0, 0);
	print_grp(file, 0, 0);
	// if (S_ISCHR(file->data->st_mode) || S_ISBLK(file->data->st_mode))
	// {
	// 	printf("ici");
	// 	print_nbr_dev(file, 0, 0);
	// 	print_nbr_rdev(file, 0, 0);
	// }
	// else
	// {
		print_nbr_sze(file, 0, 0);
		// printf("else");
	//}
	ft_time(file, 0, 0);
	ft_putstr(file->content);
	ft_putchar('\n');
}

// void				ft_ls_l(t_file *file)
// {
// 		prnt(ret, uid, group, file);
// 		ft_putchar('\n');
// }
