/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:00:24 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 11:14:38 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int dispatch_handler(const char **format, va_list args)
{
    t_flags flags;
    char    spec;

    flags = parse_flags(format);
    spec = **format;
    (*format)++;
    if (spec == 'd' || spec == 'i')
        return handle_int(va_arg(args, int), flags);
    if (spec == 'u')
        return handle_unsigned(va_arg(args, unsigned int), flags);
    if (spec == 'x')
        return handle_hex(va_arg(args, unsigned int), flags, 0);
    if (spec == 'X')
        return handle_hex(va_arg(args, unsigned int), flags, 1);
    if (spec == 'p')
        return handle_pointer(va_arg(args, void *), flags);
    if (spec == 's')
        return handle_str(va_arg(args, char *), flags);
    if (spec == 'c')
        return handle_char(va_arg(args, int), flags);
    if (spec == '%')
        return handle_percent(flags);

    return 0;
}
