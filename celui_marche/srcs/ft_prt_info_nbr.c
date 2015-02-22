/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_info_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:59:47 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/18 10:59:50 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <uuid/uuid.h>
#include "ft_ls.h"

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
	char		*hlp;

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
	while (i-- > (int)ft_strlen(ft_itoa(nbr)))
		new[a++] = ' ';
	if (S_ISCHR(oth->data->st_mode) || S_ISBLK(oth->data->st_mode))
	{
		new = print_nbr_major(oth, 0, 0);
		ft_putstr(new);
		hlp = (char *)malloc(sizeof(char) * (oth->data->st_rdev));
		hlp = print_nbr_minor(oth, 0, 0);
		ft_putstr(", ");
		ft_putstr(hlp);
	}
	else
	{
		new = ft_strcat(new, ft_itoa(nbr));
		ft_putstr(new);
	}
	ft_putstr(" ");
}

char	*print_nbr_major(t_file *file, int a, int i)
{
	static int	bignb;
	t_file		*oth;
	int			nbr;
	char		*new;

	oth = file;
	while (oth)
	{
		nbr = major(file->data->st_dev);
		if (nbr > bignb)
			bignb = nbr;
		oth = oth->next;
	}
	oth = file;
	nbr = major(file->data->st_rdev);
	i = ft_strlen(ft_itoa(bignb));
	new = (char *)malloc(sizeof(char) * (ft_strlen(ft_itoa(bignb))));
	while (i-- > (int)ft_strlen(ft_itoa(nbr)))
		new[a++] = ' ';
	new = ft_strcat(new, ft_itoa(nbr));
	return (new);
}

char	*print_nbr_minor(t_file *file, int a, int i)
{
	static int	bignb;
	t_file		*oth;
	int			nbr;
	char		*new;

	oth = file;
	while (oth)
	{
		nbr = minor(file->data->st_rdev);
		if (nbr > bignb)
			bignb = nbr;
		oth = oth->next;
	}
	oth = file;
	nbr = minor(file->data->st_rdev);
	i = ft_strlen(ft_itoa(bignb));
	new = (char *)malloc(sizeof(char) * (ft_strlen(ft_itoa(bignb))));
	while (i-- > (int)ft_strlen(ft_itoa(nbr)))
		new[a++] = ' ';
	new = ft_strcat(new, ft_itoa(nbr));
	return (new);
}
