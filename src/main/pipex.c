/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:32:50 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/17 16:44:47 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <libft.h>

int	main(int argc, char **argv, char **env)
{
	char	**cmd;

	if (argc != 5)
		how_to_use();
	cmd = NULL;
	cmd = ft_parse_cmd(cmd, argv, env);
	ft_processes(cmd, argv, env);
	exit(0);
}
