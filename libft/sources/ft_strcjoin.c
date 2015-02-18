/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:29:18 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/30 17:15:52 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strcjoin(char *s1, char *s2, char c)
{
	char	*tmp;
	int		i;
	
	i = 0;
	tmp = NULL;
	if (s1 && s2)
	{
		tmp = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
		if (!tmp)
			return (NULL);
		tmp = ft_strcpy(tmp, s1);
		while (tmp[i])
			i++;
		tmp[i] = c;
		tmp = ft_strcat(tmp, s2);
	}
	else
		return (NULL);
	return (tmp);
}
