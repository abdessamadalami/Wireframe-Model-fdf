/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:10:47 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/14 10:05:41 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*ptr;
	int		len;

	index = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	ptr = malloc (len * sizeof(char) + 1);
	if (ptr == NULL)
		return (0);
	while (s[index] != '\0')
	{
		ptr[index] = f(index, s[index]);
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
/*
char vi(unsigned int o, char v)
{
	return o+v;
}

int	main()
{  
	const char tab[] = "\0\0\0a\0";
    printf(" %s ", ft_strmapi(tab, vi));
}
 */
