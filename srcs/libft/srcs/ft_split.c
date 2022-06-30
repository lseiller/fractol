/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:48:05 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/06 14:24:04 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_next_set(char const *s, char c, int i)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_trim_clean(char const *s, int start, int end)
{
	int		i;
	char	*dest;

	i = 0;
	dest = ft_calloc((end - start + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (start < end)
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_nb_of_word(char const *s, char c)
{
	int	i;
	int	isword;
	int	nbword;

	i = -1;
	nbword = 0;
	isword = 0;
	while (s[++i])
	{
		if (s[i] == c)
			isword = 0;
		else if (s[i] != c && isword == 0)
		{
			nbword++;
			isword = 1;
		}
	}
	return (nbword);
}

char	**ft_free_tab(char **dest, int j)
{
	while (j >= 0)
	{
		free(dest[j]);
		j--;
	}
	free(dest);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		isword;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	isword = 0;
	dest = ft_calloc((ft_nb_of_word(s, c) + 1), sizeof(char *));
	while (dest && s[++i])
	{
		if (s[i] == c)
			isword = 0;
		else if ((s[i] != c && isword == 0) || i == 0)
		{
			dest[j++] = ft_trim_clean(s, i, ft_find_next_set(s, c, i));
			if (dest[j - 1] == NULL)
				dest = ft_free_tab(dest, j - 1);
			i = ft_find_next_set(s, c, i) - 1;
			isword = 1;
		}
	}
	return (dest);
}
