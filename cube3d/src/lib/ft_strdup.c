/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:30:53 by mabboud           #+#    #+#             */
/*   Updated: 2025/11/16 20:30:54 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_strdup(char *src, char **dest)
{
	size_t	len;
	size_t	i;

	if (!src || !dest)
		return ;
	len = ft_strlen(src);
	*dest = malloc(len + 1);
	if (!*dest)
		return ;
	i = 0;
	while (i < len)
	{
		(*dest)[i] = src[i];
		i++;
	}
	(*dest)[i] = '\0';
}
