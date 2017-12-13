#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:47:20 by abrichar          #+#    #+#              #
#    Updated: 2017/12/13 16:25:18 by abrichar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = abrichar.filler

CPPFLAGS = -Iincludes/
CFLAGS = -Wall -Werror -Wextra

SRC_NAME = main.c resol.c strat.c parsing.c
SRC_PATH = src
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft/libft.a

all: $(NAME)

$(NAME): begin $(OBJ)
	@cd libft; $(MAKE) -f Makefile
	gcc -o $(NAME) $(SRC) $(LIB) $(CPPFLAGS)
	cp abrichar.filler players/.

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@cd libft; $(MAKE) -f Makefile clean
	/bin/rm -rf $(OBJ_PATH)

fclean: clean end
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIB)

re: fclean all

norme:
	norminette $(SRC)
	norminette ./includes/
	@cd libft; $(MAKE) -f Makefile norme

begin:
	cp -R ../resources/* .

end:
	rm -rf players
	rm -rf maps
	rm filler_vm
	rm filler.trace