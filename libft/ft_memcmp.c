/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:25:36 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/16 09:36:30 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	while (len > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		len--;
		ptr1++;
		ptr2++;
	}
	return (0);
}
/*
int main()
{
	printf("%d",ft_memcmp("aébcd","aêbcd",4));
	char c = "ê";
	int a = -1;
	printf(" %d %d ",(unsigned char)c,(unsigned char)a);
}
*/
