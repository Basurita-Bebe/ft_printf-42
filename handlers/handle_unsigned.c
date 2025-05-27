/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:38:28 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 15:41:24 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int handle_unsigned(unsigned int n, t_flags flags)
{
    char    *str;
    int     count;

    (void)flags;
    count = 0;
    str = ft_utoa(n);
    if (!str)
        return (0);
    while (str[count])
        write(1, &str[count++], 1);
    free(str);
    return (count);
}