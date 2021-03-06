/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:55:54 by fmeira            #+#    #+#             */
/*   Updated: 2022/01/03 20:31:40 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_limits(char *str, int i)
{
	char	*tmp;

	tmp = str;
	while (tmp[++i])
	{
		if (!(ft_isalnum(tmp[i + 1])))
			return (i);
	}
	return (--i);
}

char	*find_var(char *str, int start, int end, t_data *data)
{
	int			len;
	int			i;
	char		*to_find;
	t_envars	*curr;

	len = end - start;
	to_find = ft_calloc(++len, sizeof(char));
	i = 0;
	curr = data->envars_list;
	while (--len)
		to_find[i++] = str[++start];
	while (curr)
	{
		if (!(ft_strcmp(curr->key, to_find)))
		{
			free(to_find);
			return (curr->value);
		}
		curr = curr->next;
	}
	free(to_find);
	return (NULL);
}

static char	*remove_dollar_install_communism(char *str, int start, int end)
{
	int		len;
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	len = (ft_strlen(str) - (end - start));
	new = ft_calloc(++len, sizeof(char));
	while (++i < start)
		new[i] = str[i];
	j = ++end;
	while (j < (int)ft_strlen(str))
		new[i++] = str[j++];
	new[i] = '\0';
	return (new);
}

char	*expand_dollar(t_data *data, char *str, int start, int end)
{
	char	*str_to_fit;
	char	*new;
	int		i;
	int		j;

	if (str[start + 1] == '?' && !ft_isalnum(str[start + 2]))
		return (expand_exit_status(str, start, end));
	str_to_fit = find_var(str, start, end, data);
	j = -1;
	if (str_to_fit)
	{
		i = ((ft_strlen(str) - (end - start)) + ft_strlen(str_to_fit));
		new = ft_calloc(++i, sizeof(char));
		i = -1;
		while (++i < start)
			new[i] = str[i];
		while (++j < (int)ft_strlen(str_to_fit))
			new[i++] = str_to_fit[j];
		j = ++end;
		while (j < (int)ft_strlen(str))
			new[i++] = str[j++];
		return (new);
	}
	return (remove_dollar_install_communism(str, start, end));
}

void	handle_dollar_sign(t_data *data)
{
	t_tokens	*curr;
	int			i;

	curr = data->t;
	while (curr)
	{
		i = -1;
		if (curr->token != e_single_quotes)
		{
			if (curr->token != e_quotes)
				curr->str = update_home(data->envars_list, curr->str);
			while (curr->str[++i])
			{
				if (curr->str[i] == '$')
				{
					if (curr->str[i + 1] == '?')
						add(curr, expand_dollar(data, curr->str, i, (i + 1)));
					else if (ft_isalnum(curr->str[i + 1]))
						add(curr, expand_dollar(data, curr->str, i,
								get_limits(curr->str, i)));
				}
			}
		}
		curr = curr->next;
	}
}
