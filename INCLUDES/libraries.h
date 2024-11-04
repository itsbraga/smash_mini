/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libraries.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:58:47 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/04 03:10:32 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARIES_H
# define LIBRARIES_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

# include "../LIBFT_GNL_PRINTF/INCLUDES/libft.h"
# include "../LIBFT_GNL_PRINTF/INCLUDES/ft_printf.h"
# include "../LIBFT_GNL_PRINTF/INCLUDES/get_next_line_bonus.h"

# include "colors.h"
# include "tools.h"
# include "defines.h"
# include "structs.h"
# include "minishell.h"
# include "parser_lexer.h"
# include "exec.h"

#endif
