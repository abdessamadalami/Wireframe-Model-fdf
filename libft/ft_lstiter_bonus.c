/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:18:09 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/14 09:13:47 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst-> content);
		lst = lst -> next;
	}
}
