/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:17:24 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 15:15:34 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
    int minus;
    int zero;
    int width;
    int precision;
    int has_precision;
}   t_flags;

int     ft_printf(const char *format, ...);

// mandatory handlers
int handle_char(int c, t_flags flags);
int handle_str(char *str, t_flags flags);
int handle_pointer(void *ptr, t_flags flags);
int handle_int(int n, t_flags flags);
int handle_unsigned(unsigned int n, t_flags flags);
int handle_hex(unsigned int n, t_flags flags, int uppercase);
int handle_percent(t_flags flags);

// utils
int     dispatch_handler(const char **format, va_list args)
t_flags parse_flags(const char **format);
t_flags init_flags(void);


#endif