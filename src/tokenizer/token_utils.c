/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:01:11 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:28:48 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "tokenizer.h"

void	compute_flg_mask(char input, char *flg)
{
	if (!(*flg & SQUOTE) && !(*flg & DQUOTE) && input == '"')
		*flg |= DQUOTE;
	else if (!(*flg & DQUOTE) && !(*flg & SQUOTE) && input == '\'')
		*flg |= SQUOTE;
	else if ((*flg & SQUOTE) && input == '\'')
		*flg &= ~SQUOTE;
	else if ((*flg & DQUOTE) && input == '"')
		*flg &= ~DQUOTE;
}

void	is_meta(char c, char *flg)
{
	if (ft_strchr(" \t\n|<>", c) && (*flg & 3) == 0)
		*flg |= FT_META;
	else
		*flg &= ~FT_META;
}

void	read_token(char **end, char *flg)
{
	char	state;

	*flg = 0;
	compute_flg_mask(**end, flg);
	is_meta(**end, flg);
	state = *flg & FT_META;
	while (state == (*flg & FT_META) && *(++(*end)))
	{
		compute_flg_mask(**end, flg);
		is_meta(**end, flg);
	}
}
