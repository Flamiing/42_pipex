/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:19:39 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/10 22:07:52 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <libft.h>

size_t	ft_arrlen(char **arr)
{
	size_t	count;

	if (!arr)
		return (0);
	count = 0;
	while (arr[count])
		count++;
	return (count);
}
