/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:25:21 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/25 16:35:49 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			right_usr(t_strucstat *data)
{
	ft_putstr((data->st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((data->st_mode & S_IWUSR) ? "w" : "-");
	if ((data->st_mode & S_ISUID) && (data->st_mode & S_IXUSR))
		ft_putstr("s");
	else if ((data->st_mode & S_ISUID))
		ft_putstr("S");
	else if (data->st_mode & S_IXUSR)
		ft_putstr("x");
	else
		ft_putstr("-");
}

void			right_grp(t_strucstat *data)
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

void			right_oth(t_strucstat *data)
{
	ft_putstr((data->st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((data->st_mode & S_IWOTH) ? "w" : "-");
	if ((data->st_mode & S_ISVTX) && (data->st_mode & S_IXGRP)
		&& (data->st_mode & S_IXUSR))
		ft_putstr("t");
	else if ((data->st_mode & S_ISVTX))
		ft_putstr("T");
	else if (data->st_mode & S_IXOTH)
		ft_putstr("x");
	else
		ft_putstr("-");
}

void			print_right(t_strucstat *data)
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

size_t			cal_total(t_file *file, char *dirname)
{
	struct stat	ret;
	size_t		cal;
	char		*fullname;

	cal = 0;
	while (file && file->content)
	{
		fullname = ft_strcjoin(dirname, file->content, '/');
		stat(fullname, &ret);
		cal += (ret.st_blocks);
		file = file->next;
	}
	return (cal);
}
