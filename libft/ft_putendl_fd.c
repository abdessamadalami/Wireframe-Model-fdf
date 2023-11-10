/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:31:40 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/14 17:51:17 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (!s || !fd)
		return ;
	while (s[index] != '\0')
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
	write(fd, "\n", 1);
}
