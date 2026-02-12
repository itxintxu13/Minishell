/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:11:17 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:23:01 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

static int	is_space(char x)
{
	return ((x >= 9 && x <= 13) || (x == 32));
}

static int	is_num(char x)
{
	return (x >= '0' && x <= '9');
}

int	ft_atoi(const char *string)
{
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	if (!string)
		return (0);
	while (is_space(*string))
		string++;
	if (*string == '-')
	{
		sign = -1;
		string++;
	}
	else if (*string == '+')
		string++;
	while (is_num(*string))
	{
		num = (num * 10) + (*string - '0');
		string++;
	}
	return (num * sign);
}
