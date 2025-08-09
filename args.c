/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi.shkoza <andi.shkoza@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:07:56 by andi.shkoza       #+#    #+#             */
/*   Updated: 2025/08/09 16:07:57 by andi.shkoza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	handle_two_args(char **argv, t_dict *d, char **num)
{
	int	st;

	st = parse_input(argv[1], num);
	if (st != OK)
	{
		ft_putstr("Error\n");
		return (ERR_INPUT);
	}
	if (dict_load(d, "numbers.dict") != OK)
	{
		ft_putstr("Dict Error\n");
		free(*num);
		return (ERR_DICT);
	}
	return (OK);
}

int	handle_three_args(char **argv, t_dict *d, char **num)
{
	int	st;

	st = parse_input(argv[2], num);
	if (st != OK)
	{
		ft_putstr("Error\n");
		return (ERR_INPUT);
	}
	if (dict_load(d, argv[1]) != OK)
	{
		ft_putstr("Dict Error\n");
		free(*num);
		return (ERR_DICT);
	}
	return (OK);
}

int	load_dict_and_parse(int argc, char **argv, t_dict *d, char **num)
{
	if (argc == 2)
		return (handle_two_args(argv, d, num));
	return (handle_three_args(argv, d, num));
}

void	print_status(int st)
{
	if (st == OK)
		ft_putchar('\n');
	else if (st == ERR_DICT)
		ft_putstr("Dict Error\n");
	else
		ft_putstr("Error\n");
}
