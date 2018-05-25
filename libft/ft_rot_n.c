/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 20:06:18 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/18 20:06:19 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_rot_n(char *str, int n)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] - 65;
			str[i] = (str[i] + n) % 26;
			str[i] = str[i] + 65;
			write(1, &str[i], 1);
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 97;
			str[i] = (str[i] + n) % 26;
			str[i] = str[i] + 97;
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	return (*str);
}
