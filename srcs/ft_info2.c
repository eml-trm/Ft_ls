/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 14:26:56 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/24 14:26:57 by etermeau         ###   ########.fr       */
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

void	print_grp(t_file *file, int a, int tmp)
{
	static int	tot;
	t_file		*oth;
	char		*new;
	char		*str;

	oth = file;
	while (oth)
	{
		str = getgrgid(oth->data->st_gid)->gr_name;
		tmp = ft_strlen(str);
		if (tmp > tot)
			tot = tmp;
		oth = oth->next;
	}
	oth = file;
	str = getgrgid(oth->data->st_gid)->gr_name;
	tmp = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * tmp);
	while (tot > tmp++)
		new[a++] = ' ';
	a = 0;
	while (str[a++])
		new[tmp++] = str[a];
	new = ft_strcat(new, str);
	ft_putstr(new);
	ft_putstr(" ");
}

void	print_uid(t_file *file, int a, int tmp)
{
	static int	tot;
	t_file		*oth;
	char		*new;
	char		*str;

	oth = file;
	while (oth)
	{
		str = getpwuid(oth->data->st_uid)->pw_name;
		tmp = ft_strlen(str);
		if (tmp > tot)
			tot = tmp;
		oth = oth->next;
	}
	oth = file;
	str = getpwuid(oth->data->st_uid)->pw_name;
	tmp = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * tmp);
	while (tot > tmp++)
		new[a++] = ' ';
	a = 0;
	while (str[a++])
		new[tmp++] = str[a];
	new = ft_strcat(new, str);
	ft_putstr(new);
	ft_putstr(" ");
}

void	print_nbr_link(t_file *file, int a, int i)
{
	static int	bignb;
	t_file		*oth;
	int			nbr;
	char		*new;

	oth = file;
	while (oth)
	{
		nbr = oth->data->st_nlink;
		if (nbr > bignb)
			bignb = nbr;
		oth = oth->next;
	}
	oth = file;
	nbr = oth->data->st_nlink;
	i = ft_strlen(ft_itoa(bignb));
	new = (char *)malloc(sizeof(char) * (ft_strlen(ft_itoa(bignb))));
	while (i-- > (int)ft_strlen(ft_itoa(nbr)))
		new[a++] = ' ';
	new = ft_strcat(new, ft_itoa(nbr));
	if ((int)ft_strlen(ft_itoa(nbr)) >= bignb)
		ft_putnbr(nbr);
	else
		ft_putstr(new);
	ft_putstr(" ");
}

void	print_nbr_sze(t_file *file, int a, int i)
{
	static int	bignb;
	t_file		*oth;
	int			nbr;
	char		*new;

	oth = file;
	while (oth)
	{
		nbr = oth->data->st_size;
		if (nbr > bignb)
			bignb = nbr;
		oth = oth->next;

	}
	oth = file;
	nbr = oth->data->st_size;
	i = ft_strlen(ft_itoa(bignb));
	new = (char *)malloc(sizeof(char) * (ft_strlen(ft_itoa(bignb))));
	while (i-- > 1)
		new[a++] = ' ';
	new = ft_strcat(new, ft_itoa(nbr));
	if ((int)ft_strlen(ft_itoa(nbr)) >= bignb)
		ft_putnbr(nbr);
	else
		ft_putstr(new);
	ft_putstr(" ");
}


void	print_nbr_dev(t_file *file, int a, int i)
{
	static int	bignb;
	t_file		*oth;
	int			nbr;
	char		*new;

	oth = file;
	while (oth)
	{
		nbr = oth->data->st_dev;
		if (nbr > bignb)
			bignb = nbr;
		oth = oth->next;
	}
	oth = file;
	nbr = oth->data->st_dev;
	i = ft_strlen(ft_itoa(bignb));
	new = (char *)malloc(sizeof(char) * (ft_strlen(ft_itoa(bignb))));
	while (i-- > 1)
		new[a++] = ' ';
	new = ft_strcat(new, ft_itoa(nbr));
	if (ft_strlen(ft_itoa(nbr)) > 1)
		ft_putnbr(nbr);
	else
		ft_putstr(new);
	ft_putstr(" ");
}
// void	prnt(struct stat ret, struct passwd *uid, struct group *grp, t_file *fi)
// {
// 	char			*buf;

// 	buf = (char *)malloc(sizeof(char) * (ft_strlen(fi->content) + 1));
// 	ft_putstr(uid->pw_name);
// 	ft_putstr("  ");
// 	ft_putstr(grp->gr_name);
// 	ft_putstr("   ");
// 	if (S_ISCHR(ret.st_mode) || S_ISBLK(ret.st_mode))
// 	{
// 		ft_putnbr(ret.st_dev);
// 		ft_putnbr(ret.st_rdev);
// 	}
// 	else
// 		ft_putnbr(ret.st_size);
// 	ft_putstr("  ");
// 	ft_time(ret, 0, 0);
// 	ft_putstr("  ");
// 	ft_putstr(fi->content);
// 	if (S_ISLNK(ret.st_mode))
// 	{
// 		ft_putstr(" -> ");
// 		readlink(fi->content, buf, (ft_strlen(fi->content) + 1));
// 		ft_putstr(buf);
// 		free(buf);
// 	}
// }
