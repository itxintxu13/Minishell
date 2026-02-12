/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:15:18 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:28:54 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "ft_limits.h"

# define SIZE_BUF 300
# define SQUOTE 1
# define DQUOTE 2

//	char_utils.c
int		ft_isalnum(int c);

//	lens.c
int		len(char *str);
int		len_all(char **str);
int		equal(char *str, char *str1);
int		equaln(char *str, char *str1, int size);

// utils_vec.c
char	*copy_vec(char *str);
char	*z_maloc(int size);
char	*append(char *vec, int size_new, char *buff);
int		count_caracter(char *mp, char c);
int		include(char *str_long, char *str_small);

// utils_matriz.c
char	**z_maloc_matriz(int size);
char	**append_matriz(char **matrz, char *new_line);
int		count_caracter_matriz(char **mp, char c);
char	**read_file(int fd, char c);
char	**delete_vec_matriz(char **matriz, int index_delete);

// ft_itoa.c
char	*ft_itoa(int n);

// ft_memmove.c
void	*ft_memmove(void *dest, const void *src, size_t n);

// ft_split.c
void	free_all(char **map);
char	**ft_split(char *str, char C);
char	**ft_split_custom(char *str, char C);
int		cont_letter(char *str, char C);
int		cont_words(char *str, char C);
void	print_matriz_vec(char **matriz, char *vec);

// ft_strings_1.c
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);

// ft_strings_2.c
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);

// ft_strings_3.c
char	*ft_strdup(const char *s);
char	*ft_replace(char *str, char init, char end);
size_t	calc_longer_str(char const *s1, char const *s2);
void	ft_putstr(char *s);

// error.c
void	error_handle(int err, char *str);
void	error_handle_f(int err, char *str);

// ft_iota
char	*ft_itoa(int n);

// ft_atoi
int		ft_atoi(const char *string);

// valid_env
void	valid_env(void);

// token_utils.c
void	compute_flg_mask(char input, char *flg);

// env.c
char	*name_env(void);

#endif
