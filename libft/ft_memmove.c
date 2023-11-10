/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:12:27 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/16 15:10:41 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdio.h>
#include<string.h>

void	*ft_memmove(void *dst, const void *src, size_t length)
{
	char		*dest;
	char const	*source;
	int			i;

	dest = dst;
	source = src;
	if ((dest == source || length == 0))
		return (dest);
	if (dest > source && dest - source < (int)length)
	{
		i = length -1;
		while (i >= 0)
		{
			dest[i] = source[i];
			i--;
		}
		return (dest);
	}
	ft_memcpy(dest, source, length);
	return (dest);
}
/*
int main()
{
     int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };
     char tab[] = "abcde";
	 char *s1 = &tab[2];
	 char *s2 = &tab[0];
	// printf("dest  %s src %s \n ",s1,s2);
     char t[] = "abcde";
	 char *s3 = &t[2];
	 char *s4 = &t[0];
	 char ta[6]="ouskma";
	  ft_memmove(ta + 2 , 0, 3);
	 // memmove(t+3, t, 4);
	 for( int i=0; i < 10; i++ ) {
     //   printf( " %c", ta[i] );
    }
	 // printf(" w %s   ",ta);
}
*/
