/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:49:01 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/29 14:49:09 by itlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "../../include/utils.h"
#include <stddef.h>
#include <errno.h>

char	*merge_wspaces_core(char *input)
{
	char	flg;
	char	buff[100];
	char	*clean_input;
	int		i;
	size_t	j;

	j = 0;
	flg = 0;
	clean_input = 0;
	while (input && input[j])
	{
		i = -1;
		while (++i < 99 && input[j])
		{
			compute_flg_mask(input[j], &flg);
			if (!flg && ft_strchr(" \n\t", input[j]))
				shrink_wspace(input, buff, &i, &j);
			else
				buff[i] = input[j++];
		}
		buff[i] = '\0';
		clean_input = flush_buff(buff, clean_input, input);
	}
	return (clean_input);
}
