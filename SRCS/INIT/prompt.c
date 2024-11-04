/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:42:29 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/04 02:47:24 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*generate_prompt(t_prompt *pr, t_data *d)
{
	pr->username = getenv("USER");
	if (pr->username == NULL)
		pr->username = "unknown";
	part_one(pr);
	custom_cwd(pr);
	pr->part3 = ft_strjoin(pr->part2, pr->custom_cwd);
	secure_malloc(pr->part3, true);
	free_and_set_null((void **)&pr->part2);
	free_and_set_null((void **)&pr->custom_cwd);
	d->prompt = ft_strjoin(pr->part3, "\001" R "\002" "\n$> ");
	secure_malloc(d->prompt, true);
	free_and_set_null((void **)&pr->part3);
	return (d->prompt);
}

void	update_prompt(t_data *d, t_prompt *pr)
{
	if (d->prompt != NULL)
		free_and_set_null((void **)&d->prompt);
	d->prompt = generate_prompt(pr, d);
	secure_malloc(d->prompt, true);
}

void	rl_reset_custom_prompt(void)
{
	t_prompt	pr;
	char		*nl_pos;
	size_t		line1_len;

	rl_on_new_line();
	rl_replace_line("", 0);
	update_prompt(data_struct(), &pr);
	nl_pos = ft_strchr(data_struct()->prompt, '\n');
	if (nl_pos != NULL)
	{
		line1_len = nl_pos - data_struct()->prompt + 1;
		write(STDOUT_FILENO, data_struct()->prompt, line1_len);
		rl_redisplay();
	}
}
