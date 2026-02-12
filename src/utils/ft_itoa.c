/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:16:06 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:45:59 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

static int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	num_in_str(long nLong, char *str, int num_digit)
{
	int		module;

	if (nLong == 0)
	{
		str[0] = '0';
	}
	if (nLong < 0)
	{
		nLong *= -1;
		str[0] = '-';
	}
	num_digit--;
	while (nLong)
	{
		module = nLong % 10;
		nLong = nLong / 10;
		str[num_digit] = module + '0';
		num_digit--;
	}
}

char	*ft_itoa(int n)
{
	int		num_digit;
	char	*str;

	num_digit = count_digit(n);
	str = (char *) malloc((sizeof(char) * num_digit) + 1);
	if (!str)
		return (NULL);
	num_in_str(n, str, num_digit);
	str[num_digit] = '\0';
	return (str);
}
