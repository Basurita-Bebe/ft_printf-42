/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:49:53 by bruno             #+#    #+#             */
/*   Updated: 2025/05/28 08:34:08 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../../../Rank-00/Libft/libft.h"

int handle_pointer(void *ptr, t_flags flags)
{
    (void)flags;
    char            *str;
    int             count;
    unsigned long   address;
    int             i;

    if (ptr == NULL)
        return (write(1, "(nil)", 5));
    address = (unsigned long)ptr;
    count = 0;
    i = 0;
    str = ft_utoa_base(address, "0123456789abcdef");
    if (!str)
        return (0);
    count += write(1, "0x", 2);
    while (str[i])
        count += write(1, &str[i++], 1);
    free(str);
    return (count);
}