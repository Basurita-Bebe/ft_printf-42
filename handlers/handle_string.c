/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:10:41 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 15:25:38 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int handle_str(char *str, t_flags flags)
{
    (void)flags;
    int count;

    if (!str)
        str = "(null)";
    count = 0;
    while (*str)
    {
        write(1, &str, 1);
        str++;
        count++;
    }
    return (count);
}