/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft-test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:27:03 by sadawi            #+#    #+#             */
/*   Updated: 2020/07/03 23:17:58 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clear(char *s1, char *s2)
{
	ft_strcpy(s1, "Hello World!");
	ft_strcpy(s2, "Hello World!");
}

void change(char *c)
{
	*c = 'a';
}

void changei(unsigned int i, char *c)
{
	if (!(i % 2))
		*c = 'a';
}

char changemap(char c)
{
	if (c == 'o')
		return ('c');
	return ('a');
}

char changemapi(unsigned int i, char c)
{
	if (c == 'o')
		return ('c');
	if (i % 2)
		return ('a');
	return ('b');
}

int	main(int argc, char **argv)
{
	char s1[20] = "Hello World!";
	char s2[20] = "Hello World!";
	char *p1;
	char *p2;
	char **p3;

	if (argc == 1 || !strcmp(argv[1], "1"))
	{
		printf("          PART 1 FUNCTIONS\n");
// memset
		memset(s1, 'a', 12);
		ft_memset(s2, 'a', 12);
		printf("ft_memset: %d ", (memcmp(s1, s2, 13))); //1
		clear(s1, s2);
		memset(s1, 'a', 3);
		ft_memset(s2, 'a', 3);
		printf("%d ", (memcmp(s1, s2, 13))); //2
		clear(s1, s2);
		memset(s1, '\0', 1);
		ft_memset(s2, '\0', 1);
		printf("%d\n", (memcmp(s1, s2, 13))); //3
		clear(s1, s2);
		bzero(s1, 1);
		ft_bzero(s2, 1);
// bzero
		printf("ft_bzero: %d ", (memcmp(s1, s2, 13))); //1
		clear(s1, s2);
		ft_bzero(s2, 0);
		printf("%d\n", (memcmp(s1, s2, 13))); //2
		clear(s1, s2);
		memcpy(s1, "test123", 6);
		ft_memcpy(s2, "test123", 6);
// memcpy
		printf("ft_memcpy: %d ", (memcmp(s1, s2, 13))); //1
		clear(s1, s2);
		memcpy(s1, "te", 6);
		ft_memcpy(s2, "te", 6);
		printf("%d\n", (memcmp(s1, s2, 13))); //2
		clear(s1, s2);
		memccpy(s1, "test1\023", 0, 6);
		ft_memccpy(s2, "test1\023", 0, 6);
// memccpy
		printf("ft_memccpy: %d ", (memcmp(s1, s2, 13))); //1
		clear(s1, s2);
		memccpy(s1, "test123", 't', 6);
		ft_memccpy(s2, "test123", 't', 6);
		printf("%d\n", (memcmp(s1, s2, 13))); //2
		clear(s1, s2);
		memmove(s1, s1, 6);
		ft_memmove(s2, s2, 6);
// memmove
		printf("ft_memmove: %d ", (memcmp(s1, s2, 13))); //1
		clear(s1, s2);
		memmove(s1, "\0\0\0", 6);
		ft_memmove(s2, "\0\0\0", 6);
		printf("%d\n", (memcmp(s1, s2, 13))); //2
		clear(s1, s2);
// memchr
		printf("ft_memchr: %d ", ( (memchr(s1, 'o', 13) == ft_memchr(s2, 'o', 13)))); //1
		printf("%d ", !(memchr(s1, 'a', 13) == ft_memchr(s2, 'a', 13))); //2
		printf("%d\n", !(memchr(s1, 200, 15) == ft_memchr(s2, 200, 15))); //3
		clear(s1, s2);
// memcmp
		printf("ft_memcmp: %d ", !(memcmp(s1, s2, 13) == ft_memcmp(s1, s2, 13))); //1
		printf("%d ", !(memcmp("", "", 13) == ft_memcmp("", "", 13))); //2
		memccpy(s1, "test123", 't', 6);
		printf("%d\n", !(memcmp(s1, s2, 13) == ft_memcmp(s1, s2, 13))); //3
// strlen
		clear(s1, s2);
		printf("ft_strlen: %d ", !(strlen(s1) == ft_strlen(s1))); //1
		printf("%d ", !(strlen("") == ft_strlen(""))); //2
		printf("%d\n", !(strlen("\0a") == ft_strlen("\0a"))); //3
// strdup
		printf("ft_strdup: %d ", memcmp(strdup(s1), strdup(s1), 13)); //1
		printf("%d ", memcmp(strdup("abc\0"), strdup("abc\0"), 5)); //2
		printf("%d\n", memcmp(strdup(""), strdup(""), 13)); //3
// strcpy
		strcpy(s1, "\0");
		ft_strcpy(s2, "\0");
		printf("ft_strcpy: %d ", (memcmp(s1, s2, 13))); //1
		clear(s1, s2);
		strcpy(s1, "123456789");
		ft_strcpy(s2, "123456789");
		printf("%d ", (memcmp(s1, s2, 13))); //2
		clear(s1, s2);
		strcpy(s1, "12345\06789");
		ft_strcpy(s2, "12345\06789");
		printf("%d\n", (memcmp(s1, s2, 13))); //3
// strncpy
		strncpy(s1, "\0", 3);
		ft_strncpy(s2, "\0", 3);
		printf("ft_strncpy: %d ", (memcmp(s1, s2, 13))); //1
		clear(s1, s2);
		strncpy(s1, "123456789", 5);
		ft_strncpy(s2, "123456789", 5);
		printf("%d ", (memcmp(s1, s2, 13))); //2
		clear(s1, s2);
		strncpy(s1, "12345\06789", 6);
		ft_strncpy(s2, "12345\06789", 6);
		printf("%d\n", (memcmp(s1, s2, 13))); //3
// strcat
		clear(s1, s2);
		strcat(s1, "12345");
		ft_strcat(s2, "12345");
		printf("ft_strcat: %d ", (memcmp(s1, s2, 13))); //1
		clear(s1, s2);
		strcat(s1, "\0");
		ft_strcat(s2, "\0");
		printf("%d ", (memcmp(s1, s2, 13))); //2
		clear(s1, s2);
		strcat(s1, "");
		ft_strcat(s2, "");
		printf("%d\n", (memcmp(s1, s2, 13))); //3
// strncat
		clear(s1, s2);
		strncat(s1, "12345", 4);
		ft_strncat(s2, "12345", 4);
		printf("ft_strncat: %d ", (memcmp(s1, s2, 13))); //1
		clear(s1, s2);
		strncat(s1, "12345", 9);
		ft_strncat(s2, "12345", 9);
		printf("%d ", (memcmp(s1, s2, 13))); //2
		clear(s1, s2);
		strncat(s1, "12345", 0);
		ft_strncat(s2, "12345", 0);
		printf("%d\n", (memcmp(s1, s2, 13))); //3
// strchr
		clear(s1, s2);
		printf("ft_strchr: %d ", !(strchr(s1, 't') == ft_strchr(s2, 't'))); //1
		printf("%d ", !(strchr(s1, '\0') == ft_strchr(s1, '\0'))); //2
		printf("%d\n", !(strchr(s1, 'o') == ft_strchr(s1, 'o'))); //3
// strrchr
		printf("ft_strrchr: %d ", !(strrchr(s1, 't') == ft_strrchr(s2, 't'))); //1
		printf("%d ", !(strrchr(s1, '\0') == ft_strrchr(s1, '\0'))); //2
		printf("%d\n", !(strrchr(s1, 'o') == ft_strrchr(s1, 'o'))); //3
// strstr
		printf("ft_strstr: %d ", !(strstr(s1, "Wo") == ft_strstr(s1, "Wo"))); //1
		printf("%d ", !(strstr(s1, "\0") == ft_strstr(s1, "\0"))); //2
		printf("%d ", !(strstr(s1, " ") == ft_strstr(s1, " "))); //3
		printf("%d\n", !(strstr(s1, "") == ft_strstr(s1, ""))); //4
// strcmp
		printf("ft_strcmp: %d ", !(strcmp(s1, s2) == ft_strcmp(s1, s2))); //1
		printf("%d ", !(strcmp("", "") == ft_strcmp("", ""))); //2
		printf("%d\n", !(strcmp("\0a", "\0") == ft_strcmp("\0a", "\0"))); //3
// strncmp
		printf("ft_strncmp: %d ", !(strncmp(s1, s2, 0) == ft_strncmp(s1, s2, 0))); //1
		printf("%d ", !(strncmp("", "", 3) == ft_strncmp("", "", 3))); //2
		printf("%d ", !(77 == ft_strncmp("M", "", 44121553213513))); //2
		printf("%d\n", !(strncmp("\0a", "\0", 2) == ft_strncmp("\0a", "\0", 2))); //3
// atoi
		printf("ft_atoi: %d ", !(atoi("12345") == ft_atoi("12345"))); //1
		printf("%d ", !(atoi("2147483647") == ft_atoi("2147483647"))); //2
		printf("%d ", !(atoi("2147483648") == ft_atoi("2147483648"))); //3
		printf("%d ", !(atoi("+-45") == ft_atoi("+-45"))); //4
		printf("%d ", !(atoi("-2147483648") == ft_atoi("-2147483648"))); //5
		printf("%d ", !(atoi("--3") == ft_atoi("--3"))); //6
		printf("%d ", !(atoi("   45") == ft_atoi("   45"))); //7
		printf("%d ", !(atoi("- 2") == ft_atoi("- 2"))); //8
		printf("%d\n", !(atoi("0") == ft_atoi("0"))); //9
// isalpha
		printf("ft_isalpha: %d ", ft_isalpha('-')); //1
		printf("%d ", ft_isalpha('8')); //2
		printf("%d ", ft_isalpha('\0')); //3
		printf("%d ", !ft_isalpha('a')); //4
		printf("%d\n", !ft_isalpha('Z')); //5
// isalpha
		printf("ft_isdigit: %d ", ft_isdigit('-')); //1
		printf("%d ", !ft_isdigit('8')); //2
		printf("%d ", ft_isdigit('\0')); //3
		printf("%d ", ft_isdigit('a')); //4
		printf("%d\n", ft_isdigit('Z')); //5
// isalnum
		printf("ft_isalnum: %d ", ft_isalnum('-')); //1
		printf("%d ", !ft_isalnum('0')); //2
		printf("%d ", !ft_isalnum('9')); //3
		printf("%d ", !ft_isalnum('a')); //4
		printf("%d ", !ft_isalnum('Z')); //5
		printf("%d\n", !ft_isalnum('z')); //6
// isascii
		printf("ft_isascii: %d ", !ft_isascii('-')); //1
		printf("%d ", !ft_isascii('a')); //2
		printf("%d ", !ft_isascii((char)127)); //3
		printf("%d ", !ft_isascii((char)17)); //4
		printf("%d ", ft_isascii((char)128)); //5
		printf("%d\n", !ft_isascii((char)0)); //6
// isprint
		printf("ft_print: %d ", !ft_isprint('-')); //1
		printf("%d ", !ft_isprint('a')); //2
		printf("%d ", ft_isprint((char)127)); //3
		printf("%d ", ft_isprint((char)17)); //4
		printf("%d ", ft_isprint((char)128)); //5
		printf("%d\n", ft_isprint((char)0)); //6
// toupper
		printf("ft_toupper: %d ", !(ft_toupper('a') == 'A')); //1
		printf("%d ", !(ft_toupper('x') == 'X')); //2
		printf("%d\n", !(ft_toupper('A') == 'A')); //3
// tolower
		printf("ft_tolower: %d ", !(ft_tolower('A') == 'a')); //1
		printf("%d ", !(ft_tolower('Z') == 'z')); //2
		printf("%d\n", !(ft_tolower('b') == 'b')); //3
	}
	if (argc == 1 || !strcmp(argv[1], "2"))
	{
		printf("          PART 2 FUNCTIONS\n");
// memalloc
		p1 = ft_memalloc(10);
		p2 = ft_memalloc(10);
		memcpy(p2, "1\0\0\0\0\0\0\0\0\0", 10);
		printf("ft_memalloc: %d\n", (memcmp(p1, p2, 10) + 49)); //1
// memdel
		printf("ft_memdel: %d ", (p1 == NULL)); //1
		ft_memdel((void**)&p1);
		printf("%d\n", !(p1 == NULL)); //2
// strnew
		p1 = ft_strnew(10);
		printf("ft_strnew: %d\n", (memcmp(p1, p2, 10) + 49)); //1
// strdel
		printf("ft_strdel: %d ", (p1 == NULL)); //1
		ft_strdel(&p1);
		printf("%d\n", !(p1 == NULL)); //2
// strclr
		clear(s1, s2);
		printf("ft_strclr: %d ", (*s1 == '\0')); //1
		ft_strclr(s1);
		printf("%d\n", !(*s1 == '\0')); //2
// striter
		clear(s1, s2);
		p1 = strdup("aaaaaaaaaaaa");
		ft_striter(s1, change);
		printf("ft_striter: %d\n", memcmp(s1, p1, 13)); //1
// striteri
		clear(s1, s2);
		p1 = strdup("aeala aoala!");
		ft_striteri(s1, changei);
		printf("ft_striteri: %d\n", memcmp(s1, p1, 13)); //1
// strmap
		clear(s1, s2);
		p1 = strdup("aaaacaacaaaa");
		ft_strclr(p2);
		p2 = ft_strmap(s1, changemap);
		printf("ft_strmap: %d\n", memcmp(p2, p1, 13)); //1
// strmapi
		p1 = strdup("babacabcbaba");
		ft_strclr(p2);
		p2 = ft_strmapi(s1, changemapi);
		printf("ft_strmapi: %d\n", memcmp(p2, p1, 13)); //1
// strequ
		printf("ft_strequ: %d ", !(1 == ft_strequ(s1, s2))); //1
		printf("%d ", !(1 == ft_strequ("", ""))); //2
		printf("%d\n", !(1 == ft_strequ("\0a", "\0"))); //3
// strnequ
		printf("ft_strnequ: %d ", !(1 == ft_strnequ(s1, s2, 6))); //1
		printf("%d ", !(1 == ft_strnequ("", "", 3))); //2
		printf("%d\n", !(1 == ft_strnequ("\0a", "\0", 2))); //3
// strsub
		clear(s1, s2);
		p1 = strdup("lo Wo");
		printf("ft_strsub: %d ", memcmp(ft_strsub(s1, 3, 5), p1, 6)); //1
		printf("%d\n", memcmp(ft_strsub(s1, 0, 12), s2, 13)); //2
// strjoin
		p1 = ft_strjoin(s1, s2);
		p2 = ft_strdup("Hello World!Hello World!");
		printf("ft_strjoin: %d ", memcmp(p1, p2, 25)); //1
		p2 = ft_strjoin("Hel\0lo", " World!");
		printf("%d\n", strcmp(p2, "Hel World!")); //2
// strtrim
		p1 = ft_strtrim("    \n\n\ttest  \n\n\t 123 \t\n ");
		printf("ft_strtrim: %d ", strcmp(p1, "test  \n\n\t 123")); //1
		p1 = ft_strtrim("    \n\n\t \t\n ");
		printf("%d\n", strcmp(p1, "")); //2
// strsplit
		p3 = ft_strsplit(" hello fellow     students  ", ' ');
		printf("ft_strsplit: %d ", strcmp(p3[0], "hello")); //1
		printf("%d ", strcmp(p3[1], "fellow")); //2
		printf("%d ", strcmp(p3[2], "students")); //3
		printf("%d\n", !(p3[3] == 0)); //4
// itoa
		p1 = ft_itoa(12345);
		printf("ft_itoa: %d ", strcmp(p1, "12345")); //1
		p1 = ft_itoa(-12345);
		printf("%d ", strcmp(p1, "-12345")); //2
		p1 = ft_itoa(2147483647);
		printf("%d ", strcmp(p1, "2147483647")); //3
		p1 = ft_itoa(-2147483648);
		printf("%d\n", strcmp(p1, "-2147483648")); //4
	}
	return (0);
}
