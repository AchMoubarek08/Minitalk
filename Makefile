# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 21:32:27 by amoubare          #+#    #+#              #
#    Updated: 2022/04/14 21:32:29 by amoubare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror server.c -o server
	@gcc -Wall -Wextra -Werror client.c -o client
	@echo "✅🤖✅"
clean:
	@rm -f $(NAME)
	@echo "🚮🚮🚮"
fclean: clean
re: clean all