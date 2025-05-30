/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:31:59 by bruno             #+#    #+#             */
/*   Updated: 2025/05/29 15:42:20 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_atoi(t_data *data)
{
	int	value;
	
	value = 0;
	while (is_in(NUMBERS, *data->fmt_str))
		value = (value * 10) + (*data->fmt_str++ - '0');
	return (value);
}

void	get_value(t_data *data, int *value)
{
	if (data->fmt_str == '*')
	{
		*value = va_arg(data->ap, int);
		++data->fmt_str;
		return ;
	}
	*value = ft_atoi(data)
}