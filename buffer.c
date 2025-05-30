/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:10:51 by bruno             #+#    #+#             */
/*   Updated: 2025/05/30 11:16:06 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_pad_inbuff(char c, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision--)
		add_to_buffer(data, c);
}

void	str_pad_inbuff(char *str, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision && *str)
		add_to_buffer(data, *str++);
}

void	flush_buffer(t_data *data)
{
	data->w_chars += write(STDOUT_FILENO, data->buffer, data->buff_index);
	ft_memset(data->buffer, 0, BUFF_SIZE);
	data->buff_index = 0;
}

void	add_to_buffer(t_data *data, char c)
{
	if (data->buff_index == BUFF_SIZE)
	{
		flush_buffer(data);
	}
	data->buffer[data->buff_index++] = c;
}
