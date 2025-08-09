/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi.shkoza <andi.shkoza@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:08:30 by andi.shkoza       #+#    #+#             */
/*   Updated: 2025/08/09 16:08:31 by andi.shkoza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	only_digits_or_spaces(const char *s)
{
	size_t	i;
	int		has;

	i = 0;
	has = 0;
	while (s[i])
	{
		if (s[i] == '.')
			return (0);
		if (!ft_isdigit(s[i]) && !ft_isspace(s[i]))
			return (0);
		if (ft_isdigit(s[i]))
			has = 1;
		i++;
	}
	return (has);
}

static int	normalize_core(const char *s, char **out)
{
	size_t	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	if (!ft_isdigit(s[i]))
		*out = ft_strdup("0");
	else
		*out = ft_strndup(s + i, 256);
	return (*out == NULL);
}

int	parse_input(const char *s, char **out)
{
	size_t	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
		return (ERR_INPUT);
	if (s[i] == '+')
		i++;
	if (!only_digits_or_spaces(s + i))
		return (ERR_INPUT);
	if (normalize_core(s, out))
		return (ERR_OOM);
	return (OK);
}
