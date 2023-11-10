/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:11:36 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/17 12:28:51 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include"libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(src);
	if (size != 0)
	{
		while (src[j] != '\0' && j < (size - 1))
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (i);
}
/*
#include <string.h>
int main()
{
	char s[12];
    char s2[12];
	ft_memset(s, 100, 11);
	ft_memset(s2, 100, 12);
    //printf("%zu\n", ft_strlcpy("", s, 1));
    printf("%zu\n", strlcpy("", s, 1));
}
*/
