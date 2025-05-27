/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:34:36 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 15:38:53 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int handle_int(int n, t_flags flags)
{
    char    *str;
    int     count;

    count = 0;
    str = ft_itoa(n);
    if (!str)
        return (0);
    while (str[count])
        write(1, &str[count++], 1);
    free(str);
    return (count);
}