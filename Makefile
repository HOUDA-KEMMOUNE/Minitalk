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

SRC_S = server.c utils.c utils2.c
SRC_C = client.c ft_atoi.c utils.c utils2.c
SRC_S_B = server.c utils.c utils2.c
SRC_C_B = client.c ft_atoi.c utils.c utils2.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_S_B = $(SRC_S_B:.c=.o)
OBJ_C_B = $(SRC_C_B:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(SERVER)

$(CLIENT): $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_S_B)
	$(CC) $(CFLAGS) $(OBJ_S_B) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_C_B)
	$(CC) $(CFLAGS) $(OBJ_C_B) -o $(CLIENT_BONUS)

clean:
	rm -rf $(OBJ_C) $(OBJ_S) $(OBJ_C_B) $(OBJ_S_B)

fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all bonus
