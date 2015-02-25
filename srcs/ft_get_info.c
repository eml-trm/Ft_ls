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

#include <time.h>
#include "ft_ls.h"

void				ft_sort_date(char *str, int res, int next, int oth)
{
	int				a;
	int				i;

	i = 8;
	a = 11;
	while (i < a)
		write(1, &str[i++], 1);
	i = 4;
	a = 8;
	while (i < a)
		write(1, &str[i++], 1);
	if (res < 15778463 && next < oth)
	{
		i = 11;
		a = 16;
		while (i < a)
			write(1, &str[i++], 1);
	}
	else
	{
		i = 20;
		a = 25;
		while (i < a)
			write(1, &str[i++], 1);
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
	if (lstat(fullname, ret) == -1)
		ft_code_erreur(4, NULL);
	new->data = ret;
	new->time_sec = new->data->st_mtime;
}

void				ft_data_dir(char *dirname, t_dir *new)
{
	struct stat		*ret;

	if (!(ret = (struct stat *)malloc(sizeof(struct stat))))
		ft_code_erreur(3, NULL);
	if (lstat(dirname, ret) == -1)
		ft_code_erreur(4, NULL);
	new->info = ret;
	new->mtime = new->info->st_mtime;
}
