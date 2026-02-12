/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:48:52 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/29 14:48:54 by itlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tokenizer.h"
#include "../../include/utils.h"

char	**tokenize_core(char *end)
{
	char	**tokens;
	char	*bgn;
	char	flg;

	bgn = end;
	tokens = 0;
	while (end && *end)
	{
		read_token(&end, &flg);
		compute_flg_mask(*end, &flg);
		is_meta(*bgn, &flg);
		tokens = compute_saves(tokens, flg, &bgn, end);
		if (!tokens)
			return (NULL);
	}
	return (tokens);
}
