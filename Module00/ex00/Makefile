# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 17:59:57 by mmourdal          #+#    #+#              #
#    Updated: 2023/04/29 22:32:48 by mmourdal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                  ASCII ART                                   #
################################################################################

RED_TWO = \033[1;32m
RED		= \033[5;32m
WHITE	= \033[1;37m
BLINK	= \033[5m
END		= \033[0m

ART_NAME_1 =  ██████ ██████  ██████      ███    ███  ██████  ██████  ██    ██ ██      ███████      ██████   ██████  \n
ART_NAME_2 = ██      ██   ██ ██   ██     ████  ████ ██    ██ ██   ██ ██    ██ ██      ██          ██  ████ ██  ████ \n
ART_NAME_3 = ██      ██████  ██████      ██ ████ ██ ██    ██ ██   ██ ██    ██ ██      █████       ██ ██ ██ ██ ██ ██ \n
ART_NAME_4 = ██      ██      ██          ██  ██  ██ ██    ██ ██   ██ ██    ██ ██      ██          ████  ██ ████  ██ \n
ART_NAME_5 =  ██████ ██      ██          ██      ██  ██████  ██████   ██████  ███████ ███████      ██████   ██████  \n

PRINT_NAME = @printf "\n$(RED)%2s$(ART_NAME_1)%1s$(ART_NAME_2)%1s$(ART_NAME_3)%1s$(ART_NAME_4)%2s$(ART_NAME_5)$(END)\n"

################################################################################
#                                  SOURCES                                     #
################################################################################

SRC_FILES	=	megaphone.cpp

################################################################################
#                                  OBJETS                                      #
################################################################################

OBJS_DIR	= .objets
OBJS		= $(SRC_FILES:%.cpp=$(OBJS_DIR)/%.o)

################################################################################
#                                COMPILATION                                   #
################################################################################

CC			= c++
CFLAGS		= -g3 -std=c++98 -Wall -Wextra -Werror

################################################################################
#                                  MAKEFILE                                    #
################################################################################

NAME = megaphone
all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
$(OBJS_DIR) :
	@$(PRINT_NAME)
	@printf "$(RED_TWO)%20s Création des dossiers content les $(END)$(WHITE).o : \n"
	@sleep 0.2
	@printf "$(RED_TWO)%24s Création du dossier $(END)$(WHITE)$(OBJS_DIR)...\n"
	@mkdir $(OBJS_DIR)

$(OBJS) : $(OBJS_DIR)/%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	
re : fclean all

.PHONY: all clean fclean re