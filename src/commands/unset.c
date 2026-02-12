/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:13:01 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:03:30 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/commands.h"

int	ft_unset(char *name)
{
	char	**envs;
	char	*value;
	int		aux;

	if (!name)
		error_handle_f(0, 0);
	if (!include(name, "="))
		value = ft_strjoin(name, "=");
	else
		value = ft_strdup(name);
	envs = ft_getallenv();
	aux = 0;
	while (envs && envs[aux])
	{
		if (equaln(envs[aux], value, ft_strlen(value)))
			break ;
		aux++;
	}
	if (envs && equaln(envs[aux], value, ft_strlen(value)))
		envs = delete_vec_matriz(envs, aux);
	load_env(envs);
	free_all(envs);
	free(value);
	return (0);
}
