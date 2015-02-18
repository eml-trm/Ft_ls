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

#include <stdlib.h>
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
		{
			ft_code_erreur(2);
			ft_code_erreur(3);
		}
		i++;
	}
}

// void	exec_opt(int *opt, char *av, t_file *otr)
// {
// /*	printf("opt[2] = %d\n", opt[1]);
// 	printf("opt[3] = %d\n", opt[3]);
// 	printf("opt[4] = %d\n", opt[4]);*/
// 	if (opt[0] == 1)
// 		ft_ls_a(ft_ls(av));
// 	else if (opt[1] == 1)
// 		ft_ls_r(ft_ls(av));
// 	else if (opt[2] == 1)
// 	{
// 		ft_putstr(av);
// 		ft_ls_l(ft_ls(av));
// 	}
// /*	else if (opt[2] == 1)
// 		return (0);
// 	else if (opt[4] == 1)
// 		return (0);*/
// 	else
// 		ft_print_ls(otr);
// }
