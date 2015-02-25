/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 11:32:17 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/08 17:51:57 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	check_opt(int *opt, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			opt[0] = 1;
		if (str[i] == 'r')
			opt[1] = 1;
		if (str[i] == 'l')
			opt[2] = 1;
		if (str[i] == 't')
			opt[3] = 1;
		if (str[i] == 'R')
			opt[4] = 1;
		if (str[i] == '-' && str[i + 1] == '-')
			ft_code_erreur(0, NULL);
		if (str[i] == '-' && str[i + 2] == '-')
			ft_code_erreur(0, NULL);
		i++;
	}
}
