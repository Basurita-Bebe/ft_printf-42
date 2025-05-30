# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruno <bruno@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 10:17:28 by bruno             #+#    #+#              #
#    Updated: 2025/05/30 15:11:56 by bruno            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# === Path to libft ===
LIBFT_DIR = ../../Rank-00/Libft
LIBFT = $(LIBFT_DIR)/libft.a

# === Mandatory Files ===
MANDATORY_SRC = \
	ft_printf.c \
	format_render.c \
	buffer.c \
	renders/render_char.c \
	renders/render_str.c \
	renders/render_numbers.c \
	utils/format_parser.c \
	utils/get_number_prefix.c \
	utils/get_value.c \
	utils/init_format.c \
	utils/is_in.c

# === Bonus Files ===
BONUS_SRCS = \
	utils/parse_flags_bonus.c \
	utils/format_parser_bonus.c

# === Object Files ===
MANDATORY_OBJS = $(MANDATORY_SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# === Build Selection ===
ifeq ($(MAKECMDGOALS), bonus)
	OBJS = $(filter-out utils/format_parser.o, $(MANDATORY_OBJS)) $(BONUS_OBJS)
	CFLAGS += -DBONUS
else
	OBJS = $(MANDATORY_OBJS)
endif

# ===== Rules =====
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

bonus: fclean $(NAME)

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

.PHONY: all bonus clean fclean re

