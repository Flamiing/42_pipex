/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:41:40 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/17 16:22:59 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <libft.h>

void	ft_free_array(char **arr)
{
	int	index;

	index = 0;
	if (!arr)
		return ;
	while (arr[index])
	{
		free(arr[index]);
		index++;
	}
	free(arr[index]);
	free(arr);
}

void	ft_free_strings(char *str1, char *str2, char *str3)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	if (str3)
		free(str3);
}
