/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:25:21 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/20 11:25:22 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <uuid/uuid.h>
#include "ft_ls.h"

void	right_usr(struct stat *data)
{
	ft_putstr((data->st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((data->st_mode & S_IWUSR) ? "w" : "-");
	if ((data->st_mode & S_ISUID) && (data->st_mode & S_IXUSR))
		ft_putstr("s");
	else if ((data->st_mode & S_ISUID))
		ft_putstr("S");
	else if(data->st_mode & S_IXUSR)
		ft_putstr("x");
	else
		ft_putstr("-");
}

void	right_grp(struct stat *data)
{
	ft_putstr((data->st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((data->st_mode & S_IWGRP) ? "w" : "-");
	if ((data->st_mode & S_ISGID) && (data->st_mode & S_IXGRP))
		ft_putstr("s");
	else if ((data->st_mode & S_ISGID))
		ft_putstr("S");
	else if ((data->st_mode & S_IXGRP))
		ft_putstr("x");
	else
		ft_putstr("-");
}

void	right_oth(struct stat *data)
{
	ft_putstr((data->st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((data->st_mode & S_IWOTH) ? "w" : "-");
	if ((data->st_mode & S_ISVTX) && (data->st_mode & S_IXGRP)
	 && (data->st_mode & S_IXUSR))
		ft_putstr("t");
	else if ((data->st_mode & S_ISVTX))
		ft_putstr("T");
	else if(data->st_mode & S_IXOTH)
		ft_putstr("x");
	else
		ft_putstr("-");
}

void	print_right(struct stat *data)
{
	if (S_ISDIR(data->st_mode))
		ft_putstr("d");
	else if (S_ISFIFO(data->st_mode))
		ft_putstr("p");
	else if (S_ISCHR(data->st_mode))
		ft_putstr("c");
	else if (S_ISBLK(data->st_mode))
		ft_putstr("b");
	else if (S_ISLNK(data->st_mode))
		ft_putstr("l");
	else if (S_ISSOCK(data->st_mode))
		ft_putstr("s");
	else
		ft_putstr("-");
	right_usr(data);
	right_grp(data);
	right_oth(data);
	ft_putstr("  ");
}

size_t	cal_total(t_file *file, char *dirname)
{
	struct stat ret;
	size_t 		cal;
	char 		*fullname;

	cal = 0;

	while (file && file->content)
	{
		fullname = ft_strcjoin(dirname, file->content, '/');
		if (stat(fullname, &ret) == -1)
			ft_code_erreur(4);
		cal += (ret.st_blocks);
		file = file->next;
	}
	return (cal);
}

// void	ft_sort_date(char *str, int res, int next, int oth)
// {
// 	int	a;
// 	int	i;

// 	i = 8;
// 	a = 11;
// 	while (i < a)
// 		write(1, &str[i++], 1);
// 	i = 4;
// 	a = 8;
// 	while (i < a)
// 		write(1, &str[i++], 1);
// 	if (res < 15778463 && next < oth)
// 	{
// 		i = 11;
// 		a = 16;
// 		while (i < a)
// 			write(1, &str[i++], 1);
// 	}
// 	else
// 	{
// 		i = 20;
// 		a = 25;
// 		while (i < a)
// 			write(1, &str[i++], 1);
// 	}
// }

// void	ft_time(struct stat ret, int res, int oth)
// {
// 	struct timespec	strc;
// 	int				next;
// 	time_t			date;
// 	char			*temps;
// 	char			*tps;

// 	date = time(&(strc.tv_sec));
// 	temps = ctime(&(ret.st_mtimespec.tv_sec));
// 	tps = ft_strchr(temps, '\n');
// 	*tps = 0;
// 	res = ((date) - (ret.st_mtimespec.tv_sec));
// 	oth = date;
// 	next = (ret.st_mtimespec.tv_sec);
// 	ft_sort_date(temps, res, next, oth);
// }

