/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:25:11 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 11:14:38 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags parse_flags(const char **format)
{
    t_flags flags;

    flags = init_flags();
    while (**format == '0' || **format == '-')
    {
        if (**format == '-')
            flags.minus = 1;
        if (**format == '0')
            flags.zero = 1;
        (*format)++;
    }
    if (**format >= '0' && **format <= '9')
        flags.width = parse_number(format);
    if (**format == '.')
    {
        (*format)++;
        flags.has_precision = 1;
        if (**format >= '0' && **format <= '9')
            flags.precision = parse_number(format);
        else
            flags.precision = 0;
    }
    return (flags);
}