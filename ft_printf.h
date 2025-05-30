/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:17:24 by bruno             #+#    #+#             */
/*   Updated: 2025/05/30 15:13:15 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../../Rank-00/Libft/libft.h"

# define BUFF_SIZE 4096
# define FLAGS "+ 0-#"
# define NUMBERS "0123456789"
# define SPECIFIERS "csidupxX%"

// Symbolic errors for better readability
typedef enum e_error
{
	OK = 0,
	MALLOC_ERROR = -13,
	PARSE_ERROR = -42,
}	t_error;

// Different bases
typedef enum e_base
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16
}	t_base;

// Padding struct
typedef struct s_pad
{
	int	zeros;
	int	spaces;
}	t_pad;

typedef struct s_format
{
	char	specifier;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		width_v;
	int		precision_v;
	int		padd_spaces;
	int		upper_case;
	t_base	base;
}	t_format;

typedef struct s_data
{
	const char	*fmt_str;
	va_list		ap;
	int			w_chars;
	char		*buffer;
	int			buff_index;
	t_format	format;
}	t_data;

int			ft_printf(const char *format, ...);

// buffer
void		flush_buffer(t_data *data);
void		add_to_buffer(t_data *data, char c);
void		char_pad_inbuff(char c, int precision, t_data *data);
void		str_pad_inbuff(char *str, int precision, t_data *data);

// renders
void		render_format(t_data *data);
void		print_char(t_data *data, int c);
void		print_str(t_data *data, char *str);
void		print_numbers(t_data *data, long long value);

// utils
t_format	init_format(void);
int			parse_format(t_data *data);
int			is_in(const char *fmt_str, char c);
void		get_value(t_data *data, int *value);
void		parse_flags(t_data *data);
void		add_padding(char c, int precision, t_data *data);
char		*get_number_prefix(t_data *data, int is_negative,
				unsigned long long value);

#endif
