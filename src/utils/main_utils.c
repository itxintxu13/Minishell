/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:46:17 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:49:45 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/commands.h"

void	verify_env_cwd(int status, char **env_save)
{
	char	*pwd;
	char	**env;

	env = ft_getallenv();
	if ((!env || len_all(env) < 2) && env_save)
		load_env(env_save);
	if (env)
		free_all(env);
	if (status)
		return ;
	pwd = ft_getcwd();
	if (!pwd)
		return ;
	if (chdir(pwd) == -1)
	{
		free(pwd);
		return ;
	}
	free(pwd);
}

int	search_pipe(char *str)
{
	char	flg;

	flg = 0;
	while (str && *str)
	{
		compute_flg_mask(*str, &flg);
		if (!flg && ft_strchr("|", *str))
			return (1);
		str++;
	}
	return (0);
}
