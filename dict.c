/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi.shkoza <andi.shkoza@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:08:24 by andi.shkoza       #+#    #+#             */
/*   Updated: 2025/08/09 16:08:25 by andi.shkoza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

const char	*dict_get(const t_dict *d, const char *key)
{
	int	i;

	i = 0;
	while (i < d->size)
	{
		if (ft_strcmp(d->arr[i].key, key) == 0)
			return (d->arr[i].val);
		i++;
	}
	return (NULL);
}

void	dict_free(t_dict *d)
{
	int	i;

	i = 0;
	while (i < d->size)
	{
		free(d->arr[i].key);
		free(d->arr[i].val);
		i++;
	}
	d->size = 0;
}
