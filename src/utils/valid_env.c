/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:15:45 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:53:46 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/commands.h"

void	valid_env(void)
{
	char	*tmp;

	tmp = ft_getenv("PWD");
	if (!tmp)
	{
		tmp = malloc(PATH_MAX * sizeof(char));
		if (!tmp)
			return ;
		if (!getcwd(tmp, PATH_MAX))
		{
			free(tmp);
			return ;
		}
		ft_export("PWD", tmp);
	}
	free(tmp);
	tmp = ft_getenv("PATH");
	if (!tmp)
	{
		tmp = ft_strdup("/usr/local/sbin:/usr/local/bin:/usr/sbin:\
/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
		ft_export("PATH", tmp);
	}
	free(tmp);
	ft_export("?", "0");
}
