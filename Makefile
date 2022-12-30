# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:40:51 by mfinette          #+#    #+#              #
#    Updated: 2022/12/14 09:13:46 by mfinette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= @rm -f
HEADER	= fractol.h
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m

FILES =	main				\
		pixel_parsing		\
		check_parameters 	\
		ft_atoi				\
		iterations			\
		hook_actions					

all: $(NAME)

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o:%.c $(HEADER)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) -Wall -Wextra -I/minilibx-linux/mlx.h -Imlx-linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	@make -C ./minilibx-linux
	$(CC) *.c minilibx-linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)😳😎fractol compiled!😎😳$(DEF_COLOR)"
clean:
	@$(RM) $(OBJS)
	@echo "$(CYAN)pushswap object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)3$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(CYAN)2$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(CYAN)1$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(GREEN)pushswap executable files cleaned!$(DEF_COLOR)"


re: fclean all

.PHONY: all clean fclean re
