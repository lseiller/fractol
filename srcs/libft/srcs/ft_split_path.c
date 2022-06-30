/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:48:05 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/02 16:22:32 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_next_set(char const *s, char c, int index)
{
	int	not_set;

	not_set = 0;
	while (s[index] && not_set == 0)
	{
		if (s[index] == c && s[index + 1] && s[index + 1] == c)
			index++;
		else if (s[index] == c)
			not_set = 1;
		index++;
	}
	return (index);
}

static int	nb_of_word(char const *s, char const c)
{
	int	i;
	int	nb_word;

	i = 0;
	nb_word = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] == c)
			i++;
		else if (s[i] == c)
			nb_word++;
		i++;
	}
	return (nb_word);
}

char	**ft_split_path(char const *s)
{
	const char	c = ':';
	char		**dest;
	int			i;
	int			j;
	int			fns;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	dest = ft_calloc(nb_of_word(s, c) + 1, sizeof(char *));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		fns = find_next_set(s, c, i);
		dest[j] = ft_substr(s, i, fns - i);
		if (dest[j] == NULL)
			return (ft_free_tab(dest, j));
		i = fns;
		j++;
	}
	return (dest);
}
