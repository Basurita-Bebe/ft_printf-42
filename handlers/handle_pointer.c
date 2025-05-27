/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:49:53 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 15:54:21 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int handle_pointer(void *ptr; t_flags flags)
{
    (void)free;
    char            *str;
    int             count;
    unsigned long   address;
    
    address = (unsigned long)ptr;
    str = ft_utoa_base(address, "0123456789abcdef");
    if (!str)
        return (0);
    count += write(1, "0x", 2);
    count = 0;
    while (*str)
        count += write(1, &str, 1);
    free(str);
    return (count);
}