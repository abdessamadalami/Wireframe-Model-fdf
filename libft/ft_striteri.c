/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:55:35 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/16 07:36:04 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	index;

	index = 0;
	if (!s)
		return ;
	while (s[index] != '\0')
	{
		f(index, &s[index]);
		index++;
	}
}
