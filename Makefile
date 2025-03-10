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

CC = cc
SERVER = server
CLIENT = client
CFLAGS = -Wall -Wextra -Werror
SRC_S = server.c utils.c utils2.c
SRC_C = client.c ft_atoi.c utils.c utils2.c
OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(SERVER)

$(CLIENT): $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(CLIENT)

clean:
	rm $(OBJ_C) server.o

fclean: clean
	rm $(SERVER) $(CLIENT)

re: fclean all
