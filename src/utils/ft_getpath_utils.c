/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:04:46 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/17 16:18:17 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <libft.h>

int	ft_begin_with_space(char *str)
{
	if (!str)
		return (0);
	if (str[0] == 32)
		return (1);
	return (0);
}

char	*ft_get_with_space(char	*dest, char *cmd)
{
	if (!cmd)
		return (NULL);
	dest = (char *)malloc(ft_strlen(cmd) + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, cmd, ft_strlen(cmd) + 1);
	return (dest);
}
