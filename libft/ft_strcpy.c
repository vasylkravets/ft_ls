/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:19:21 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/29 19:19:24 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(const char *dst, const char *src)
{
	char	*src1;
	char	*dst1;
	int		i;

	dst1 = (char *)dst;
	src1 = (char *)src;
	i = 0;
	while (src1[i] != '\0')
	{
		dst1[i] = src1[i];
		i++;
	}
	dst1[i] = '\0';
	return (dst1);
}
