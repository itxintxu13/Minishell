/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:05:52 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:32:36 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H
# include <stddef.h>

//	token_utils.c

# define FT_META 4

void	is_meta(char c, char *flg);
void	parse_redirect(char **bgn, char *oprt, int *i, char c);
void	read_token(char **end, char *flg);
char	**resize_tokens(char **list, char *new_token);
char	**compute_saves(char **tokens, char flg, char **bgn, char *end);

//	process_input.c

char	*clear_input(char *input);
void	shrink_wspace(char *input, char *buff, int *i, size_t *j);
char	*flush_buff(char *buff, char *dst, char *input);
char	*merge_wspaces_core(char *input);
char	**tokenize_core(char *end);

//	save_utils.c

char	*save_word(char **bgn, char *end, char **tokens);
int		save_operator(char **bgn, char *end, char *oprt);

#endif // !TOKEN_UTILS_H
