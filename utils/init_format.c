/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:11:33 by bruno             #+#    #+#             */
/*   Updated: 2025/05/30 11:37:50 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_format	init_format(void)
{
	t_format	format;

	format.minus = 0;
	format.plus = 0;
	format.space = 0;
	format.zero = 0;
	format.hash = 0;
	format.width_v = 0;
	format.precision_v = -1;
	format.upper_case = 0;
	format.specifier = '\0';
	return (format);
}
