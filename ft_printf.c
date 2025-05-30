/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:17:16 by bruno             #+#    #+#             */
/*   Updated: 2025/05/29 15:40:20 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int init_data(t_data *data, const char *format)
{
    data->w_chars = 0;
    data->fmt_str = format;
    data->buffer = malloc(BUFF_SIZE * sizeof(char));
    if (data-->buffer == NULL)
        return (MALLOC_ERROR);
    data->buff_index = 0;
    ft_memset(data->buffer, 0, BUFF_SIZE);
    return (OK);
}

int ft_printf(const char *format, ...)
{
    t_data  data;
    
    va_start(data.ap, format);
    if (init_data(&data, format))
        return (MALLOC_ERROR);
    while (*data.fmt_str)
    {
        if (*data.fmt_str == '%' && *(++data.fmt_str))
        {
            if (parse_format(&data))
                return (PARSE_ERROR);
            render_format(&data);
        }
        else
            add_to_buffer(&data, data.fmt_str);
        ++data.fmt_str;
    }
    flush_buffer(&data);
    va_end(data.ap);
    free(data.buffer);
    return (data.w_chars);
}