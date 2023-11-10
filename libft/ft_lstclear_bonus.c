/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:07:59 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/17 08:24:48 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include "libft.h"
#include<stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	while (*lst)
	{
		node = (*lst);
		*lst = (*lst)-> next;
		ft_lstdelone(node, del);
	}
}
/*
void del(void *ptr)
{
//	*(int*)ptr = 5;
	 free(ptr);
}

void printList(t_list *a) {

   t_list *ptr = a;
   printf("\n[ ");

   //start from the beginning
   while(ptr)
   {
      printf("( %d ) ",*(int *)ptr -> content);
      ptr = ptr->next;
   }
   printf(" ]");
}
int *f(int a)
{
    int *ptr;
	ptr = (int *)malloc(sizeof(int));
	*ptr = a;
	return ptr;

}
int main()
{
	t_list *a;
	t_list *node;
    t_list *n;
	int *ptr;
    int tab1[4] = {1, 2, 3, 4};
          int tab = 1337;
        a = ft_lstnew(f(tab));
    int i = 0;
    while (i<4)
	{
        node = ft_lstnew(f(tab1[i]));
      //  printf("the content of node is = %d \n", *(int *)a -> content);
        ft_lstadd_back(&a,node);
        i++;
    }
	printList(a);
    ft_lstclear(&a,del);
	printList (a);
}
*/
