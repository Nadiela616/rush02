/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi.shkoza <andi.shkoza@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:08:42 by andi.shkoza       #+#    #+#             */
/*   Updated: 2025/08/09 16:08:43 by andi.shkoza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	t_dict	dict;
	char	*num;
	int		st;

	num = NULL;
	if (argc != 2 && argc != 3)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (load_dict_and_parse(argc, argv, &dict, &num) != OK)
		return (0);
	st = convert_number(&dict, num);
	print_status(st);
	dict_free(&dict);
	free(num);
	return (0);
}
