/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:16:38 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/18 18:43:42 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include <string.h>
#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	const char	*s;
	char		*ds;

	s = src;
	ds = dest;
	if ((s == 0) && (ds == 0))
		return (0);
	if (ds != s)
	{
		while ((len > 0))
		{
			len--;
			*ds++ = *s++;
		}
	}
	return (dest);
}
/*
int main()
{
    char tab[] = "oussama";

 	int array [] = { 54, 85, 20, 63, 21 };
     // with int array any bloque of memmory tab 4 bates
	 // so 5 here is one int + one byte memecpy copye two bloc of int memory  
    printf("%s ",ft_memcpy(array + 2, array, 1));

	int a=0;
	while(a < 6)
	{
	printf(" %d ", array[a]);
     a++;
	}
 // ,memcpy(a+1,t,12));
{
	printf("%s", ft_memcpy("whatever", "whatever", 10));

}
*/
