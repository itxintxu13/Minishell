/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:19:34 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:37:08 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/commands.h"

char	*ft_pwd(void)
{
	return (ft_getenv("PWD"));
}

char	*ft_getcwd(void)
{
	return (ft_getenv("PWD"));
}
