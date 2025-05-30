/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:35:29 by bruno             #+#    #+#             */
/*   Updated: 2025/05/30 10:28:44 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	parse_format(t_data *data)
{
	ft_memset(&data->format, 0, sizeof(t_format));
	data->format.precision_v = -1;
#ifdef BONUS
	parse_flags(data);
#endif
	get_value(data, &data->format.width_v);
	if (*data->fmt_str == '.' && (++data->fmt_str))
		get_value(data, &data->format.precision_v);
	if (!is_in(SPECIFIERS, *data->fmt_str))
		return (PARSE_ERROR);
	data->format.specifier = *data->fmt_str;
	if (is_in("diu", data->format.specifier))
		data->format.base = BASE_10;
	else if (is_in("xXp", data->format.specifier))
	{
		data->format.base = BASE_16;
		if (data->format.specifier == 'X')
			data->format.upper_case = 1;
	}
	return (OK);
}
