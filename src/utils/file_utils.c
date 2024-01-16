/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:33:33 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/17 14:23:28 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <libft.h>

void	ft_check_access(char *filename)
{
	int	fd;

	fd = access(filename, R_OK);
	if (fd == -1)
	{
		perror ("Error");
		exit(errno);
	}
}

void	ft_file_not_found(char *filename, int id)
{
	write(2, "pipex: ", 7);
	perror(filename);
	if (id == OUTFILE)
		exit(errno);
}
