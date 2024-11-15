/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_strtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:56:40 by bbadda            #+#    #+#             */
/*   Updated: 2024/11/13 18:36:49 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	getcheck(char str, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (str == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	getstart(char *str, char *set)
{
	int	i;

	i = 0;
	while (getcheck(str[i], set) == 1)
		i++;
	return (i);
}

static int	getend(char *str, char *set)
{
	int	i;

	i = strlen(str) - 1;
	while (i >= 0 && getcheck(str[i], set) == 1)
		i--;
	return (i);
}

char	*parse_strtrim(char const *str, char const *set)
{
	int		len;
	char	*new_str;
	char	*dest;
	int		start;
	int		end;

	if (!str || !set)
		return (NULL);
	if ((str[0] == '\0' && set[0] == '\0') || str[0] == '\0')
	{
		dest = malloc(1);
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	end = getend((char *)str, (char *)set);
	start = getstart((char *)str, (char *)set);
	if (end < start)
		return (NULL);
	len = end - start;
	new_str = parse_substr(str, start, len + 1);
	return (new_str);
}
