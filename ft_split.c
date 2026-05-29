/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:09:18 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/29 21:56:29 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_free_mtrx(char **mtrx, size_t id)
{
	while (id > 0)
	{
		id--;
		free(mtrx[id]);
	}
	free(mtrx);
	return (NULL);
}

static	size_t	ft_count_words(char const *s, char c)
{
	size_t	n_words;
	size_t	i;

	n_words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			n_words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n_words);
}

static	char	**fill_mtrx(char **mtrx, size_t n_words, char const *s, char c)
{
	size_t	start;
	size_t	i;
	size_t	row;

	i = 0;
	row = 0;
	while (row < n_words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		mtrx[row] = ft_substr(s, start, i - start);
		if (!mtrx[row])
			return (ft_free_mtrx (mtrx, row));
		row++;
	}
	mtrx[row] = NULL;
	return (mtrx);
}

char	**ft_split(char const *s, char c)
{
	char	**mtrx;
	size_t	n_words;

	if (!s)
		return (NULL);
	n_words = ft_count_words(s, c);
	mtrx = ft_calloc ((n_words + 1), sizeof (char *));
	if (!mtrx)
		return (NULL);
	return (fill_mtrx(mtrx, n_words, s, c));
}
