/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi.shkoza <andi.shkoza@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:08:19 by andi.shkoza       #+#    #+#             */
/*   Updated: 2025/08/09 16:08:20 by andi.shkoza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static char	*append_buf(char *dst, size_t used, const char *src, size_t n)
{
	char	*nb;
	size_t	i;

	nb = (char *)malloc(used + n + 1);
	if (!nb)
		return (NULL);
	i = 0;
	while (i < used)
	{
		nb[i] = dst[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		nb[used + i] = src[i];
		i++;
	}
	if (dst)
		free(dst);
	nb[used + n] = '\0';
	return (nb);
}

static int	read_loop(int fd, char **out, size_t *used)
{
	char	buf[4096];
	ssize_t	r;

	r = read(fd, buf, sizeof(buf));
	while (r > 0)
	{
		*out = append_buf(*out, *used, buf, (size_t)r);
		if (!*out)
			return (0);
		*used += (size_t)r;
		r = read(fd, buf, sizeof(buf));
	}
	return (1);
}

char	*read_all_file(const char *path, size_t *n)
{
	int		fd;
	char	*out;
	size_t	used;
	int		ok;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	out = NULL;
	used = 0;
	ok = read_loop(fd, &out, &used);
	close(fd);
	if (!ok)
	{
		if (out)
			free(out);
		return (NULL);
	}
	if (n)
		*n = used;
	return (out);
}

char	*normalize_key_digits(const char *s)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
		return (NULL);
	while (s[i] == '0')
		i++;
	start = i;
	while (ft_isdigit(s[i]))
		i++;
	if (i == start)
		return (ft_strdup("0"));
	len = i - start;
	return (ft_strndup(s + start, len));
}
