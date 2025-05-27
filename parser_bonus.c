/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:05:01 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 11:14:38 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags init_flags(void)
{
    t_flags flags;

    flags.minus = 0;
    flags.zero  0;
    flags.width = 0;
    flags.precision = 0;
    flags.has_precision = 0;
    return flags;
}
static int parse_number(const char **format)
{
    int num;

    num = 0;
    while (**fornmat >= '0' && *fornmat <= '9')
    {
        num = num * 10 + (**format - '0');
        (*format)++;
    }
    return (num);
}

