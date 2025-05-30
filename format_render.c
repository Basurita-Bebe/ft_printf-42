/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:28:45 by bruno             #+#    #+#             */
/*   Updated: 2025/05/30 10:58:13 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static void	render_char(t_data *data)
{
	if (data->format.specifier == '%')
		print_char(data, '%');
	else
		print_char(data, va_arg(data->ap, int));
}

static void	render_str(t_data *data)
{
	print_str(data, va_arg(data->ap, char *));
}

static void	render_number_types(t_data *data)
{
	unsigned long long	value;

	if (is_in("di", data->format.specifier))
		value = (long long)va_arg(data->ap, int);
	else if (data->format.specifier == 'u'
		|| data->format.specifier == 'x'
		|| data->format.specifier == 'X')
		value = (unsigned int)va_arg(data->ap, unsigned int);
	else if (data->format.specifier == 'p')
		value = (unsigned long long)(uintptr_t)va_arg(data->ap, void *);
	print_numbers(data, value);
}

void	render_format(t_data *data)
{
	char	specifier;

	specifier = data->format.specifier;
	if (specifier == '%' || specifier == 'c')
		render_char(data);
	else if (specifier == 's')
		render_str(data);
	else
		render_number_types(data);
}
