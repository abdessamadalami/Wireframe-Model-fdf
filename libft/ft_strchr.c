/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:28:59 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/14 10:15:22 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char	*s;

	s = str;
	while (*s != (unsigned char)c && *s != '\0')
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	else
		return (0);
}
