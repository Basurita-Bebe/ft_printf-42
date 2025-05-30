/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:13:14 by bruno             #+#    #+#             */
/*   Updated: 2025/05/30 09:47:00 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdint.h>

static void	calculate_padd(t_data *data, int num_len, int prefix_len, int *pad_zeros, int *pad_spaces)
{
	int	precision;
	int	width;
	int	total;

	*pad_zeros = 0;
	*pad_spaces = 0;
	precision = data->format.precision_v;
	width = data->format.width_v;
	if (precision > num_len)
		*pad_zeros = precision - num_len;
	total = prefix_len + num_len + *pad_zeros;
	if (precision == 0 && num_len == 1 && data->format.specifier != 'p')
		total = prefix_len;
	if (width > total)
		*pad_spaces = width - total;
}

static void	write_number(t_data *data, char *prefix, char *str, int pad_zeros, int pad_spaces)
{
	int	prefix_len;
	int	num_len;

	prefix_len = ft_strlen(prefix);
	num_len = ft_strlen(str);
	if (data->format.minus)
	{
		str_pad_inbuff(prefix, prefix_len, data);
		char_pad_inbuff('0', pad_zeros, data);
		str_pad_inbuff(str, num_len, data);
		char_pad_inbuff(' ', pad_spaces, data);
	}
	else if (data->format.zero && data->format.precision_v < 0)
	{
		str_pad_inbuff(prefix, prefix_len, data);
		char_pad_inbuff('0', pad_spaces, data);
		str_pad_inbuff(str, num_len, data);
	}
	else
	{
		char_pad_inbuff(' ', pad_spaces, data);
		str_pad_inbuff(prefix, prefix_len, data);
		char_pad_inbuff('0', pad_zeros, data);
		str_pad_inbuff(str, num_len, data);
	}
}

void	print_numbers(t_data *data, long long value)
{
	int		is_negative;
	char	*prefix;
	char	*str;
	int		pad_zeros;
	int		pad_spaces;

	is_negative = 0;
	if (is_in("di", data->format.specifier) && (long long)value < 0)
	{
		is_negative = 1;
		value = (long long)value;
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
	calculate_padd(data, ft_strlen(str), ft_strlen(prefix), &pad_zeros, &pad_spaces);
	write_number(data, prefix, str, pad_zeros, pad_spaces);
	free(str);
}
