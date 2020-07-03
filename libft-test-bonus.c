/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft-test-bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:27:03 by sadawi            #+#    #+#             */
/*   Updated: 2020/07/03 23:29:53 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "bonus.h"

void	del(void *content, size_t content_size)
{
	memcpy(content, "test", 5);
	(void)(content_size);
}

void    fill(char *s, char c)
{
    int i;

    i = 0;
    while (s[i])
    {
        s[i] = c;
        i++;
    }
}

void	changelist(t_list *elem)
{
	elem->content = strdup("123456789");
	elem->content_size = 9;
}

t_list *listmap(t_list *elem)
{
	t_list *tmp;
	tmp = ft_lstnew(elem->content, elem->content_size);
	fill(tmp->content, 'b');
	return (tmp);
}

int	main(void)
{
	t_list *link;
	t_list *link2;
	t_list *link3;

		printf("          PART 3 FUNCTIONS\n");
// lstnew
		link = ft_lstnew("Hello World!", 13);
		printf("ft_lstnew: %d ", strcmp(link->content, "Hello World!")); //1
		printf("%d ", !(link->content_size == 13)); //2
		printf("%d\n", !(link->next == NULL)); //3
// lstadd
		link2 = ft_lstnew("test123", 8);
		ft_lstadd(&link, link2);
		printf("ft_lstadd: %d ", strcmp(link->content, "test123")); //1
		printf("%d ", !(link->content_size == 8)); //2
		link = link->next;
		printf("%d ", strcmp(link->content, "Hello World!")); //3
		printf("%d ", !(link->content_size == 13)); //4
		printf("%d\n", !(link->next == NULL)); //5
// lstiter
		ft_lstadd(&link, link2);
		ft_lstiter(link, changelist);
		printf("ft_lstiter: %d ", strcmp(link->content, "123456789")); //1
		printf("%d ", !(link->content_size == 9)); //2
		link = link->next;
		printf("%d ", strcmp(link->content, "123456789")); //3
		printf("%d\n", !(link->content_size == 9)); //4
// lstmap
		ft_lstadd(&link, link2);
		link3 = ft_lstmap(link, listmap);
		printf("ft_lstmap: %d ", strcmp(link3->content, "bbbbbbbbb")); //1
		printf("%d ", !(link3->content_size == 9)); //2
		link3 = link3->next;
		printf("%d ", strcmp(link3->content, "bbbbbbbbb")); //3
		printf("%d ", !(link3->content_size == 9)); //4
		printf("%d ", strcmp(link->content, "123456789")); //5
		printf("%d ", !(link->content_size == 9)); //6
		link = link->next;
		printf("%d ", strcmp(link->content, "123456789")); //7
		printf("%d\n", !(link->content_size == 9)); //8
// lstdelone
		ft_lstadd(&link, link2);
		ft_lstadd(&link, link3);
		link3 = link->next;
		ft_lstdelone(&link, del);
		printf("ft_lstdelone: %d ", !(link == NULL)); //1
		printf("%d\n", strcmp(link3->content, "123456789")); //2
// lstdel
		link = link3->next;
		ft_lstdel(&link3, del);
		printf("ft_lstdel: %d ", !(link3 == NULL)); //1
		printf("%d\n", !(ft_strequ(link->content, "test"))); //2

		return (0);
}
