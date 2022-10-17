/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 01:05:57 by coder             #+#    #+#             */
/*   Updated: 2022/09/24 23:10:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
int main (void)
{
	unsigned char str[] = {"Bomdia"};
	unsigned char str2[] = {"amoramor"};
	ft_memmove(str, str2, 8);
	memmove(str, str2, 8);
   	printf("memmove str = %s str2 = %s\n", str, str2);
	printf("ft_memmove str = %s str2 = %s\n", str, str2);

	return (0);
}*/
