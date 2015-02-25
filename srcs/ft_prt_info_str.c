/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_info_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 14:26:56 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/24 14:26:57 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <pwd.h>
#include "ft_ls.h"

char				*init_grp(t_file *oth, char *str)
{
	struct group	*grp;

	grp = getgrgid(oth->data->st_gid);
	if (!grp)
		str = ft_itoa(oth->data->st_gid);
	else
		str = grp->gr_name;
	return (str);
}

void				print_grp(t_file *file, int a, int tmp)
{
	static int		tot;
	t_file			*oth;
	char			*new;
	char			*str;
	struct group	*grp;

	oth = file;
	while (oth)
	{
		str = init_grp(oth, str);
		tmp = ft_strlen(str);
		if (tmp > tot)
			tot = tmp;
		oth = oth->next;
	}
	oth = file;
	grp = getgrgid(oth->data->st_gid);
	str = grp->gr_name;
	tmp = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * tmp);
	while (tot > tmp++)
		new[a++] = ' ';
	new[a] = 0;
	ft_putstr(new = ft_strcat(str, new));
}

char				*init_uid(t_file *oth, char *str)
{
	struct passwd	*pwd;

	pwd = getpwuid(oth->data->st_uid);
	if (!pwd)
		str = ft_itoa(oth->data->st_uid);
	else
		str = pwd->pw_name;
	return (str);
}

void				print_uid(t_file *file, int a, int tmp)
{
	static int		tot;
	t_file			*oth;
	char			*new;
	char			*str;

	oth = file;
	while (oth)
	{
		str = init_uid(oth, str);
		tmp = ft_strlen(str);
		if (tmp > tot)
			tot = tmp;
		oth = oth->next;
	}
	oth = file;
	str = init_uid(oth, str);
	tmp = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * tmp - 1);
	while (tot > tmp++)
		new[a++] = ' ';
	ft_putstr(new = ft_strcat(str, new));
}
