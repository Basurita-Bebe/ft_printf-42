/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:13:14 by bruno             #+#    #+#             */
/*   Updated: 2025/05/30 15:13:57 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdint.h>

static t_pad	calculate_padd(t_data *data, int num_len, int prefix_len)
{
	t_pad	pad;
	int		total;

	pad.zeros = 0;
	pad.spaces = 0;
	if (data->format.precision_v > num_len)
		pad.zeros = data->format.precision_v - num_len;
	total = prefix_len + num_len + pad.zeros;
	if (data->format.precision_v == 0 && num_len == 1
		&& data->format.specifier != 'p')
		total = prefix_len;
	if (data->format.width_v > total)
		pad.spaces = data->format.width_v - total;
	return (pad);
}

static void	write_number(t_data *data, char *prefix, char *str, t_pad pad)
{
	int	prefix_len;
	int	num_len;

	prefix_len = ft_strlen(prefix);
	num_len = ft_strlen(str);
	if (data->format.minus)
	{
		str_pad_inbuff(prefix, prefix_len, data);
		char_pad_inbuff('0', pad.zeros, data);
		str_pad_inbuff(str, num_len, data);
		char_pad_inbuff(' ', pad.spaces, data);
	}
	else if (data->format.zero && data->format.precision_v < 0)
	{
		str_pad_inbuff(prefix, prefix_len, data);
		char_pad_inbuff('0', pad.spaces, data);
		str_pad_inbuff(str, num_len, data);
	}
	else
	{
		char_pad_inbuff(' ', pad.spaces, data);
		str_pad_inbuff(prefix, prefix_len, data);
		char_pad_inbuff('0', pad.zeros, data);
		str_pad_inbuff(str, num_len, data);
	}
}

void	print_numbers(t_data *data, long long value)
{
	int		is_negative;
	char	*prefix;
	char	*str;
	t_pad	pad;

	is_negative = 0;
	if (is_in("di", data->format.specifier) && value < 0)
	{
		is_negative = 1;
		value = -value;
	}
	if (data->format.upper_case)
		str = ft_utoa_base(value, "0123456789ABCDEF");
	else
		str = ft_utoa_base(value, "0123456789abcdef");
	if (!str)
		return ;
	if (data->format.precision_v == 0 && value == 0)
		str[0] = '\0';
	prefix = get_number_prefix(data, is_negative, value);
	pad = calculate_padd(data, ft_strlen(str), ft_strlen(prefix));
	write_number(data, prefix, str, pad);
	free(str);
}
