/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_trip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi.shkoza <andi.shkoza@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:08:02 by andi.shkoza       #+#    #+#             */
/*   Updated: 2025/08/09 16:08:03 by andi.shkoza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	push_word(const t_dict *d, const char *k, int *first)
{
	const char	*w;

	w = dict_get(d, k);
	if (!w)
		return (ERR_DICT);
	if (!*first)
		ft_putchar(' ');
	ft_putstr(w);
	*first = 0;
	return (OK);
}

static int	push_hundreds(const t_dict *d, const char *g3, int *first)
{
	char	k[2];

	if (g3[0] == '0')
		return (OK);
	k[0] = g3[0];
	k[1] = '\0';
	if (push_word(d, k, first) != OK)
		return (ERR_DICT);
	if (push_word(d, "100", first) != OK)
		return (ERR_DICT);
	return (OK);
}

static int	push_tens_units(const t_dict *d, const char *g3, int *first)
{
	char	k[3];

	if (g3[1] == '1')
	{
		k[0] = g3[1];
		k[1] = g3[2];
		k[2] = '\0';
		return (push_word(d, k, first));
	}
	if (g3[1] > '1')
	{
		k[0] = g3[1];
		k[1] = '0';
		k[2] = '\0';
		if (push_word(d, k, first) != OK)
			return (ERR_DICT);
	}
	if (g3[2] == '0')
		return (OK);
	k[0] = g3[2];
	k[1] = '\0';
	return (push_word(d, k, first));
}

int	convert_trip(const t_dict *d, const char *g3, int *first)
{
	int	st;

	st = push_hundreds(d, g3, first);
	if (st != OK)
		return (st);
	return (push_tens_units(d, g3, first));
}
