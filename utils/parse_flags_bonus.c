/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:46:28 by bruno             #+#    #+#             */
/*   Updated: 2025/05/30 11:39:38 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	parse_flags(t_data *data)
{
	char	flag;

	while (is_in(FLAGS, *data->fmt_str))
	{
		flag = *data->fmt_str;
		if (flag == '-')
			data->format.minus = 1;
		else if (flag == '+')
			data->format.plus = 1;
		else if (flag == ' ')
			data->format.space = 1;
		else if (flag == '0')
			data->format.zero = 1;
		else if (flag == '#')
			data->format.hash = 1;
		++data->fmt_str;
	}
}
