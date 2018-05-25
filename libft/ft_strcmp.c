/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:06:21 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/01 18:06:23 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *string1;
	unsigned char *string2;

	string1 = (unsigned char*)s1;
	string2 = (unsigned char*)s2;
	while (*string1 && *string2 && *string1 == *string2)
	{
		string1++;
		string2++;
	}
	return (*string1 - *string2);
}
