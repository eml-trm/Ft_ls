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

#include <stdio.h>
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
	new = ft_strcat(new, ft_itoa(nbr));
	if ((int)ft_strlen(ft_itoa(nbr)) >= bignb)
		ft_putnbr(nbr);
	else
		ft_putstr(new);
	ft_putstr(" ");
}


void	print_nbr_dev(t_file *file, int a, int i)
{
	// static int	bignb;
	// t_file		*oth;
	// int			nbr;
	// char		*new;

	// oth = file;
	// while (oth)
	// {
	// 	nbr = oth->data->st_dev;
	// 	if (nbr > bignb)
	// 		bignb = nbr;
	// 	oth = oth->next;
	// }
	// oth = file;
	// nbr = oth->data->st_dev;
	// i = ft_strlen(ft_itoa(bignb));
	// new = (char *)malloc(sizeof(char) * (ft_strlen(ft_itoa(bignb))));
	// while (i-- > (int)ft_strlen(ft_itoa(nbr)))
	// 	new[a++] = ' ';
	// new = ft_strcat(new, ft_itoa(nbr));
	// if (ft_strlen(ft_itoa(nbr)) > 1)
	// 	ft_putnbr(nbr);
	// else
	// 	ft_putstr(new);
	a = a;
	i = i;
	ft_putnbr(file->data->st_dev);
	ft_putstr(" ");
}

void	print_nbr_rdev(t_file *file, int a, int i)
{
// 	static int	bignb;
// 	t_file		*oth;
// 	int			nbr;
// 	char		*new;

// 	oth = file;
// 	while (oth)
// 	{
// 		nbr = oth->data->st_rdev;
// 		if (nbr > bignb)
// 			bignb = nbr;
// 		oth = oth->next;
// 	}
// 	oth = file;
// 	nbr = oth->data->st_rdev;
// 	i = ft_strlen(ft_itoa(bignb));
// 	new = (char *)malloc(sizeof(char) * (ft_strlen(ft_itoa(bignb))));
// 	while (i-- > (int)ft_strlen(ft_itoa(nbr)))
// 		new[a++] = ' ';
// 	new = ft_strcat(new, ft_itoa(nbr));
// 	if (ft_strlen(ft_itoa(nbr)) > 1)
// 		ft_putnbr(nbr);
// 	else
// 		ft_putstr(new);

	a = a;
	i = i;
	ft_putnbr(file->data->st_rdev);
	ft_putstr(" ");
}
