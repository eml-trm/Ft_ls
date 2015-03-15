/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 20:52:04 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/26 20:52:06 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	print_cyan(char *str)
{
	ft_putstr(CYAN);
	ft_putstr(str);
	ft_putstr(RESET);
}

void	print_magenta(char *str)
{
	ft_putstr(MAGENTA);
	ft_putstr(str);
	ft_putstr(RESET);
}

void	print_red(char *str)
{
	ft_putstr(RED);
	ft_putstr(str);
	ft_putstr(RESET);
}

void	ft_print_in_color(char *str)
{
	if (check_param(str) == 1)
		print_cyan(str);
	else if (check_param(str) == 2)
		print_magenta(str);
	else if (check_param(str) == 4)
		print_red(str);
	else
		ft_putstr(str);
	ft_putchar('\n');
}

void	ft_print_in_color_l(char *str)
{
	if (check_param(str) == 1)
		print_cyan(str);
	else if (check_param(str) == 2)
		print_magenta(str);
	else if (check_param(str) == 4)
		print_red(str);
	else
		ft_putstr(str);
}
