/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi.shkoza <andi.shkoza@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:08:07 by andi.shkoza       #+#    #+#             */
/*   Updated: 2025/08/09 16:08:08 by andi.shkoza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	pad_left_trip(char *dst, const char *src)
{
	size_t	n;

	n = ft_strlen(src);
	dst[0] = '0';
	dst[1] = '0';
	dst[2] = '0';
	dst[3] = '\0';
	if (n >= 1)
		dst[2] = src[n - 1];
	if (n >= 2)
		dst[1] = src[n - 2];
	if (n >= 3)
		dst[0] = src[n - 3];
}

static const char	*scale_key(int gi)
{
	if (gi == 1)
		return ("1000");
	if (gi == 2)
		return ("1000000");
	if (gi == 3)
		return ("1000000000");
	if (gi == 4)
		return ("1000000000000");
	if (gi == 5)
		return ("1000000000000000");
	return (NULL);
}

static int	slice_trip(const char *num, int gi, char trip[4])
{
	size_t	len;
	int		start;
	int		end;
	int		slen;
	char	*seg;

	len = ft_strlen(num);
	start = (int)len - (gi + 1) * 3;
	if (start < 0)
		start = 0;
	end = (int)len - gi * 3;
	if (end > (int)len)
		end = (int)len;
	slen = end - start;
	seg = ft_strndup(num + (size_t)start, (size_t)slen);
	if (!seg)
		return (ERR_OOM);
	pad_left_trip(trip, seg);
	free(seg);
	return (OK);
}

int	emit_group(const t_dict *d, const char *num, int gi, int *first)
{
	char		trip[4];
	const char	*sc;

	if (slice_trip(num, gi, trip) != OK)
		return (ERR_OOM);
	if (trip[0] == '0' && trip[1] == '0' && trip[2] == '0')
		return (OK);
	if (convert_trip(d, trip, first) != OK)
		return (ERR_DICT);
	sc = scale_key(gi);
	if (sc && push_word(d, sc, first) != OK)
		return (ERR_DICT);
	return (OK);
}

int	convert_number(const t_dict *d, const char *num)
{
	int	groups;
	int	gi;
	int	first;

	if (ft_strlen(num) == 1 && num[0] == '0')
	{
		first = 1;
		return (push_word(d, "0", &first));
	}
	groups = (int)((ft_strlen(num) + 2) / 3);
	gi = groups - 1;
	first = 1;
	while (gi >= 0)
	{
		if (emit_group(d, num, gi, &first) != OK)
			return (ERR_DICT);
		gi--;
	}
	return (OK);
}
