/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:13:29 by bruno             #+#    #+#             */
/*   Updated: 2025/05/29 13:03:04 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void    print_char(t_data *data, int c)
{
    int width;

    width = data->format.width_v;
    if (width > 1)
    {
        if (data->format.minus)
        {
            char_pad_inbuff((char)c, 1, data);
            char_pad_inbuff(' ', width - 1, data);
        }
        else
        {
            char_pad_inbuff(' ', width - 1, data);
            char_pad_inbuff((char)c, 1, data);
        }
    }
    else
        char_pad_inbuff((char)c, 1, data);
}