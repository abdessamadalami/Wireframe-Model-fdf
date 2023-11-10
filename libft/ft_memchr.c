/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:17:13 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/18 19:28:02 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<string.h>
#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cr;

	cr = (unsigned char *)s;
	while (n--)
	{
		if (*cr != (unsigned char)c)
			cr++;
		else
			return (cr);
	}
	return (0);
}
/*
int main()
{
    char s[] = "Aticleworèld";

    //called own created memchr function
   // char *ptr = memchr(0,11,45);
//	printf("current function %s \n",memchr(s,'r',sizeof(s)));
    	//int tab[7] = {-1, 4900, 1, -1, 66, 72, 22};
        //ft_memchr(0, 4900, 5);
	//	printf(" tab %d ", t[0]);
		
	//	printf("%s", (char *)ft_memchr(tab, -1, 7));

	printf ("%s\n", memchr(s, 'A' + 1024, 10));
}*/
