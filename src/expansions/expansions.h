/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:57:34 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:16:45 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H

# include <stddef.h>

// expansion_utils.c
char	*save_prefix(char *token, size_t k);
char	*swap_expansion(char *prefix, char *token, size_t *i);

// hdoc_utils.c
void	save_buffer(char *buff, int	*j);
char	*read_input(char *delimiter);

// quotes_utils.c
char	**remove_quotes(char **tokens);

#endif
