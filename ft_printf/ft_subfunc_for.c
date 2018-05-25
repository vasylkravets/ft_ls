/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subfunc_for.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:53:42 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 13:53:46 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_subfunc_for_11(char print[5], unsigned int i)
{
	unsigned int	mask[3];
	unsigned char	vidn[4];

	mask[0] = 49280;
	mask[1] = 14712960;
	mask[2] = 4034953344;
	vidn[1] = (i << 26) >> 26;
	vidn[0] = ((i >> 6) << 27) >> 27;
	print[0] = (mask[0] >> 8) | vidn[0];
	print[1] = ((mask[0] << 24) >> 24) | vidn[1];
	print[2] = '\0';
}

void	ft_subfunc_for_16(char print[5], unsigned int i)
{
	unsigned int	mask[3];
	unsigned char	vidn[4];

	mask[0] = 49280;
	mask[1] = 14712960;
	mask[2] = 4034953344;
	vidn[2] = (i << 26) >> 26;
	vidn[1] = ((i >> 6) << 26) >> 26;
	vidn[0] = ((i >> 12) << 28) >> 28;
	print[0] = (mask[1] >> 16) | vidn[0];
	print[1] = ((mask[1] << 16) >> 24) | vidn[1];
	print[2] = ((mask[1] << 24) >> 24) | vidn[2];
	print[3] = '\0';
}

void	ft_subfunc_for_else(char print[5], unsigned int i)
{
	unsigned int	mask[3];
	unsigned char	vidn[4];

	mask[0] = 49280;
	mask[1] = 14712960;
	mask[2] = 4034953344;
	vidn[3] = (i << 26) >> 26;
	vidn[2] = ((i >> 6) << 26) >> 26;
	vidn[1] = ((i >> 12) << 26) >> 26;
	vidn[0] = ((i >> 18) << 29) >> 29;
	print[0] = (mask[2] >> 24) | vidn[0];
	print[1] = ((mask[2] << 8) >> 24) | vidn[1];
	print[2] = ((mask[2] << 16) >> 24) | vidn[2];
	print[3] = ((mask[2] << 24) >> 24) | vidn[3];
	print[4] = '\0';
}
