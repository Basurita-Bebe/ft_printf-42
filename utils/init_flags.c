/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:08:49 by bruno             #+#    #+#             */
/*   Updated: 2025/05/27 15:10:39 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags init_flags(void)
{
    t_flags flags;
    
    flags.minus = 0;
    flags.zero = 0;
    flags.width = 0;
    flags.precision = 0;
    flags.has_precision = 0;
    return (flags);
}