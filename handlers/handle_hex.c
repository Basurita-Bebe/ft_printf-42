/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:44:54 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 15:48:54 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int handle_hex(unsigned int n, t_flags flags, int uppercase)
{
    char    *str;
    int     count;
    char    *base;

    count = 0;
    (void)flags;
    if (uppercase)
        base = "0123456789ABCDEF";
    else
        base = "0123456789abcdef";
    str = ft_utoa_base(n, base);
    if (!str)
        return (0);
    while (str[count])
        write(1, &str[count++], 1);
    free(str);
    return (count);
}