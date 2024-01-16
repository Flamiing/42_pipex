/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:54:21 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/17 16:16:05 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <libft.h>

char	**ft_parse_cmd(char **cmd, char **args, char **env)
{
	char	*cmd1_path;
	char	*cmd2_path;

	cmd = (char **)ft_calloc(3, sizeof(char *));
	if (!cmd)
		ft_exit_program(EXIT_FAILURE, 0, 0, NORMAL);
	cmd1_path = ft_getpath(env, args[2]);
	if (!cmd1_path)
		ft_exit_program(EXIT_FAILURE, 0, 0, NORMAL);
	cmd2_path = ft_getpath(env, args[3]);
	if (!cmd2_path)
		ft_exit_program(EXIT_FAILURE, cmd1_path, 0, NORMAL);
	cmd[0] = cmd1_path;
	cmd[1] = cmd2_path;
	cmd[2] = 0;
	return (cmd);
}
