/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi.shkoza <andi.shkoza@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:08:13 by andi.shkoza       #+#    #+#             */
/*   Updated: 2025/08/09 16:08:14 by andi.shkoza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	push_entry(t_dict *d, char *k, char *v)
{
	if (d->size >= DICT_MAX)
		return (ERR_OOM);
	d->arr[d->size].key = k;
	d->arr[d->size].val = v;
	d->size++;
	return (OK);
}

static int	parse_line_full(t_dict *d, const char *line)
{
	size_t	len;
	size_t	c;
	char	*k;
	char	*v;

	len = ft_strlen(line);
	c = 0;
	while (c < len && line[c] != ':')
		c++;
	if (c == len)
		return (OK);
	k = normalize_key_digits(line);
	if (!k)
		return (ERR_DICT);
	v = ft_strtrim_print(line + c + 1);
	if (!v)
		return (free(k), ERR_OOM);
	return (push_entry(d, k, v));
}

static int	load_lines(t_dict *d, char *buf, size_t n)
{
	size_t	i;
	size_t	start;
	char	*line;

	i = 0;
	start = 0;
	while (i <= n)
	{
		if (i == n || buf[i] == '\n')
		{
			line = ft_strndup(buf + start, i - start);
			if (!line)
				return (ERR_OOM);
			if (ft_strlen(line) > 0 && parse_line_full(d, line) == ERR_OOM)
				return (free(line), ERR_OOM);
			free(line);
			start = i + 1;
		}
		i++;
	}
	return (OK);
}

int	dict_load(t_dict *d, const char *path)
{
	char	*buf;
	size_t	n;
	int		st;

	d->size = 0;
	buf = read_all_file(path, &n);
	if (!buf)
		return (ERR_DICT);
	st = load_lines(d, buf, n);
	free(buf);
	if (st != OK)
		return (ERR_DICT);
	return (OK);
}
