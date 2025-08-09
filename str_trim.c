/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi.shkoza <andi.shkoza@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:09:19 by andi.shkoza       #+#    #+#             */
/*   Updated: 2025/08/09 16:09:20 by andi.shkoza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strtrim_print(const char *s)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	while (i < len && ft_isspace(s[i]))
		i++;
	if (i == len)
		return (ft_strdup(""));
	j = len - 1;
	while (j > i && ft_isspace(s[j]))
		j--;
	return (ft_strndup(s + i, j - i + 1));
}
