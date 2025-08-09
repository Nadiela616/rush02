/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi.shkoza <andi.shkoza@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:08:55 by andi.shkoza       #+#    #+#             */
/*   Updated: 2025/08/09 16:08:56 by andi.shkoza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define OK 0
# define ERR_INPUT 1
# define ERR_DICT 2
# define ERR_OOM 3

# define DICT_MAX 2048

typedef struct s_entry
{
	char	*key;
	char	*val;
}	t_entry;

typedef struct s_dict
{
	t_entry	arr[DICT_MAX];
	int		size;
}	t_dict;

/* io */
void		ft_putchar(char c);
void		ft_putstr(const char *s);

/* str utils */
size_t		ft_strlen(const char *s);
int			ft_isspace(char c);
int			ft_isdigit(char c);
int			ft_isprint(char c);
int			ft_strcmp(const char *a, const char *b);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strtrim_print(const char *s);

/* dict */
char		*read_all_file(const char *path, size_t *n);
char		*normalize_key_digits(const char *s);
int			dict_load(t_dict *d, const char *path);
const char	*dict_get(const t_dict *d, const char *key);
void		dict_free(t_dict *d);

/* convert */
int			push_word(const t_dict *d, const char *k, int *first);
int			convert_trip(const t_dict *d, const char *g3, int *first);
int			emit_group(const t_dict *d, const char *num, int gi, int *first);
int			convert_number(const t_dict *d, const char *num);

/* input */
int			parse_input(const char *s, char **out);

/* args handling + status */
int			handle_two_args(char **argv, t_dict *d, char **num);
int			handle_three_args(char **argv, t_dict *d, char **num);
int			load_dict_and_parse(int argc, char **argv, t_dict *d, char **num);
void		print_status(int st);

#endif
