/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:44:34 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 15:17:26 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int dispatch_handler(const char **format, va_list args)
{
    int count = 0;
    char spec = **format;
    t_flags flags;

    flags = init_flags();
    if (spec == 'c')
        count = handle_char(va_arg(args, int), flags);
    else if (spec == 's')
        count = handle_str(va_arg(args, char *), flags);
    else if (spec == 'p')
        count = handle_pointer(va_arg(args, void *), flags);
    else if (spec == 'd' || spec == 'i')
        count = handle_int(va_arg(args, int), flags);
    else if (spec == 'u')
        count = handle_unsigned(va_arg(args, unsigned int), flags);
    else if (spec == 'x')
        count = handle_hex(va_arg(args, unsigned int), flags, 0);
    else if (spec == 'X')
        count = handle_hex(va_arg(args, unsigned int), flags, 1);
    else if (spec == '%')
        count = handle_percent(flags);

    (*format)++;
    return count;
}
