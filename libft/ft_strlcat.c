/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:16:13 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/18 19:22:37 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	old_len;
	size_t	j;
	size_t	len_dest;

	j = 0;
	if (!dest && size == 0)
		return (ft_strlen (src));
	len_dest = ft_strlen(dest);
	old_len = len_dest;
	if (size > len_dest)
	{
		while (*(src + j) != '\0' && (len_dest < size - 1))
		{
			*(dest + len_dest) = *(src + j);
			len_dest++;
			j++;
		}
		*(dest + len_dest) = '\0';
		return (ft_strlen(src) + old_len);
	}
	else
		return (size + ft_strlen(src));
}
/*
int main()
{
     printf("%zu ",ft_strlcat(0, "ddd", 5));
     //printf("%zu ",strlcat(0, "ddd", 5));
}*/
