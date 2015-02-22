/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 13:28:53 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/19 13:28:56 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <uuid/uuid.h>
#include "ft_ls.h"

void				ft_sort_date(char *str, int res, int next, int oth)
{
	int				i;

	i = 8;
	while (i < 11)
		write(1, &str[i++], 1);
	i = 4;
	while (i < 8)
		write(1, &str[i++], 1);
	if (res < 15778463 && next < oth)
	{
		i = 11;
		while (i < 16)
			write(1, &str[i++], 1);
	}
	else
	{
		i = 20;
		while (i < 25)
			write(1, &str[i++], 1);
		ft_putchar(' ');
	}
}

void				ft_time(t_file *file, int res, int oth)
{
	struct timespec	strc;
	int				next;
	time_t			date;
	char			*temps;
	char			*tps;

	date = time(&(strc.tv_sec));
	temps = ctime(&(file->data->st_mtimespec.tv_sec));
	tps = ft_strchr(temps, '\n');
	*tps = 0;
	res = ((date) - (file->data->st_mtimespec.tv_sec));
	oth = date;
	next = (file->data->st_mtimespec.tv_sec);
	ft_sort_date(temps, res, next, oth);
	ft_putstr(" ");
}

void				ft_data(char *fullname, t_file *new)
{
	struct stat		*ret;

	if (!(ret = (struct stat *)malloc(sizeof(struct stat))))
		ft_code_erreur(3, NULL);
	lstat(fullname, ret);
	new->data = ret;
	new->time_sec = new->data->st_mtime;
}

void				ft_data_dir(char *dirname, t_dir *new)
{
	struct stat		*ret;

	if (!(ret = (struct stat *)malloc(sizeof(struct stat))))
		ft_code_erreur(3, NULL);
	lstat(dirname, ret);
	new->info = ret;
	new->mtime = new->info->st_mtime;
}
