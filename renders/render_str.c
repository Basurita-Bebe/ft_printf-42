/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:24:15 by bruno             #+#    #+#             */
/*   Updated: 2025/05/29 15:52:11 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	set_str_padd(t_data *data, char *str)
{
	int	len;
	int	visible_len;
	
	len = ft_strlen(str);
	if (data->format.precision_v >= 0 && data->format.precision_v < len)
		visible_len = data->format.precision_v;
	else
		visible_len = len;
	data->format.padd_spaces = data->format.width_v - visible_len;
	if (data->format.padd_spaces < 0)
		data->format.padd_spaces = 0;
}

void	print_str(t_data *data, char *str)
{
	if (str == NULL)
		str = "(null)";
	set_str_padd(data, str);
	if (data->format.minus)
	{
		if (data->format.precision_v >= 0)
			str_pad_inbuff(str, data->format.precision_v, data);
		else
			str_pad_inbuff(str, ft_strlen(str), data);
		char_pad_inbuff(' ', data->format.padd_spaces, data);
	}
	else
	{
		char_pad_inbuff(' ', data->format.padd_spaces, data);
		if (data->format.precision_v >= 0)
			str_pad_inbuff(str, data->format.precision_v, data);
		else
			str_pad_inbuff(str, ft_strlen(str), data);
	}
}