/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:41:09 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/01/09 15:44:41 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux != '\0')
	{
		if (*aux == c)
			return (aux);
		else
			aux++;
	}
	if (*aux == 0 && c == 0)
		return (aux);
	else if (c != *aux)
		return (0);
	return (0);
}

int		ft_strlen(const char *str)
{
	int cont;

	cont = 0;
	while (str[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(s3 = ((char *)malloc((len1 + len2 + 1) * sizeof(char)))))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		s3[len1 + i] = s2[i];
		i++;
	}
	s3[len1 + i] = '\0';
	return (s3);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		count;

	count = 0;
	while (s1[count])
		count++;
	if (!(s2 = malloc(count + 1)))
		return (NULL);
	while (count >= 0)
	{
		s2[count] = s1[count];
		count--;
	}
	return (s2);
}
