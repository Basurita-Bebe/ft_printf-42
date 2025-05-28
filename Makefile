# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruno <bruno@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 10:17:28 by bruno             #+#    #+#              #
#    Updated: 2025/05/28 10:26:09 by bruno            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# === Path to libft ===
LIBFT_DIR = ../../Rank-00/Libft
LIBFT = $(LIBFT_DIR)/libft.a

# === Mandatory Files ===
MANDATORY_SRC = ft_printf.c \
	utils/dispatch_handler.c \
	handlers/handle_char.c \
	handlers/handle_string.c \
	handlers/handle_percent.c \
	handlers/handle_int.c \
	handlers/handle_unsigned.c \
	handlers/handle_hex.c \
	handlers/handle_pointer.c 

# === Bonus Files ===
BONUS_SRCS = \
	parser_bonus.c \
	utils/init_flags.c \
	utils/parse_flags.c

# === Object Files ===
MANDATORY_OBJS = $(MANDATORY_SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# === Det. Wich Objects To Build ===
ifeq ($(MAKECMDGOALS), bonus)
	OBJS = $(MANDATORY_OBJS) $(BONUS_OBJS)
	CFLAGS += -DBONUS
else
	OBJS = $(MANDATORY_OBJS)
endif

# ===== Rules =====
all: $(LIBFT) $(NAME)

bonus: $(LIBFT)
	@make OBJS="$(MANDATORY_OBJS) $(BONUS_OBJS)" CFLAGS="$(CFLAGS) -DBONUS" $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re

