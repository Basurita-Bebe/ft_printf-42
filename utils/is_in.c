/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:52:55 by bruno             #+#    #+#             */
/*   Updated: 2025/05/30 11:38:29 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	is_in(const char *fmt_str, char c)
{
	if (fmt_str == NULL)
		return (-1);
	while (*fmt_str)
	{
		if (*fmt_str == c)
			return (0);
		++fmt_str;
	}
	return (-1);
}
