/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:17:21 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 11:14:38 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int total;

    total = 0;
    va_start(args, format)
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            // total = dispatch_handler(&format, args); //TODO
        }
        else
        {
            write(1, format, 1);
            total++;
        }
        format++;
    }
    va_end(args);
    return (total);
}