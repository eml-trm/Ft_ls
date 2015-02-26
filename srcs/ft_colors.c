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
	ft_putchar('\n');
}

void	print_magenta(char *str)
{
	ft_putstr(MAGENTA);
	ft_putstr(str);
	ft_putstr(RESET);
	ft_putchar('\n');
}

void	print_red(char *str)
{
	ft_putstr(RED);
	ft_putstr(str);
	ft_putstr(RESET);
	ft_putchar('\n');
}
