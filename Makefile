# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 23:25:14 by hkemmoun          #+#    #+#              #
#    Updated: 2025/03/02 23:25:16 by hkemmoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = server.c client.c
OBJ = server.o client.o

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) -c $(CFLAGS) -o $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME) 
