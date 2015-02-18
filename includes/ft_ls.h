/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 18:10:07 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/08 17:46:18 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <dirent.h>
#include <string.h>
#include "libft.h"

typedef struct		s_file
{
	char			*content;
	struct s_file	*next;
	struct s_file	*prev;
	struct stat		*data;
	time_t			time_sec;
}					t_file;

typedef struct		s_dir
{
	char			*elem;
	t_file			*start;
	struct s_dir	*next;
	struct s_dir	*prev;
	size_t			total;
}					t_dir;

/* Vrac */
void				read_dir(t_dir *param, char *str, int *tab);
int					check_param(char *str);
t_file				*init(void);
int					count(t_dir *dir);

/* opt -l et -t */
void				print_nbr_dev(t_file *file, int a, int i);
void				print_uid(t_file *file, int a, int tmp);
void				print_grp(t_file *file, int a, int tmp);
void				print_nbr_sze(t_file *file, int a, int i);
void				print_nbr_link(t_file *file, int a, int i);
void				ft_print_info(t_file *file);
void				ft_sort_time_dir(t_dir *dir);
void				ft_sort_time_file(t_file *file);
void				ft_data(char *fullname, t_file *file);
void				ft_swap(t_file *file);
void				prnt(struct stat ret, struct passwd *uid,
	struct group *grp, t_file *fi);
void				right_oth(struct stat *data);
void				right_grp(struct stat *data);
void				right_usr(struct stat *data);
void				ft_sort_date(char *str, int res, int next, int oth);
void				ft_time(struct stat ret, int res, int oth);
size_t				cal_total(t_file *file, char *fullname);
void				print_right(struct stat *data);

/* opt -r */
void				ft_change_dir_rev(t_dir *dir);
int					ft_cmp_dir_rev(t_dir *dir);

/* traitement des repertoires paramètres -> t_dir */
int					ft_cmp_dir(t_dir *dir);
void				ft_change_dir(t_dir *dir);
t_dir				*ft_new_dir(char *elem);
void				ft_add_dir(t_dir **alst, char *name);

/* traitement des contenus -> t_file */
void				list(t_file **alst, t_file *new, t_file *tmp);
int					ft_cmp_list(t_file *file);
void				ft_change_list(t_file *file);
t_file				*ft_new_list(char *content);
void				ft_add_list(t_file **alst, char *fnam, char *nam, int *tab);

/* Fonctions de ls */
void				straight_list(int *tab, t_dir *dir);
void				ft_sort_arg(t_dir *dir, int *tab);
void				check_opt(int *opt, char *str);
void				exec_opt(int *opt, char *av, t_file *otr);
void				ft_code_erreur(int code);

/* Fonctions d'options */
void				ft_ls(t_dir *dir, char *str, int *tab);
void				ft_ls_l(t_file *file);
void				ft_ls_r(t_file *file, int *tab);
void				ft_print_ls(t_dir *dir, int c, int *tab);

#endif