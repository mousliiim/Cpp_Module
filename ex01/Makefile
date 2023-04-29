# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 17:59:57 by mmourdal          #+#    #+#              #
#    Updated: 2023/04/29 22:59:42 by mmourdal         ###   ########.fr        #
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

SRC_FILES	=	$(addprefix classes/Contact/, contact.cpp) \
				$(addprefix classes/PhoneBook/, phonebook.cpp) \
				main.cpp

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

NAME = PhoneBook
all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
$(OBJS_DIR) :
	@$(PRINT_NAME)
	@printf "$(RED_TWO)%20s Création des dossiers content les $(END)$(WHITE).o : \n"
	@sleep 0.2
	@printf "$(RED_TWO)%24s Création du dossier $(END)$(WHITE)$(OBJS_DIR)...\n"
	@mkdir $(OBJS_DIR)
	@sleep 0.2
	@printf "$(RED_TWO)%24s Création du dossier $(END)$(WHITE)$(OBJS_DIR)/classes...\n"
	@mkdir $(OBJS_DIR)/classes
	@sleep 0.2
	@printf "$(RED_TWO)%24s Création du dossier $(END)$(WHITE)$(OBJS_DIR)/classes/Contact...\n"
	@mkdir $(OBJS_DIR)/classes/Contact
	@sleep 0.2
	@printf "$(RED_TWO)%24s Création du dossier $(END)$(WHITE)$(OBJS_DIR)/classes/PhoneBook...\n"
	@mkdir $(OBJS_DIR)/classes/PhoneBook
	@sleep 0.2
	@printf "$(RED_TWO)%20s Création des $(END)$(WHITE).o$(RED_TWO) dans $(END)$(WHITE)$(OBJS_DIR)$(END)$(WHITE)...\n"
	@sleep 0.2
	@printf "$(RED_TWO)%20s Compilation des $(END)$(WHITE).cpp$(RED_TWO) en $(END)$(WHITE).o$(RED_TWO)...\n"
	@sleep 0.2
	@printf "$(RED_TWO)%20s Création de l'executable $(END)$(WHITE)$(NAME)$(END)$(WHITE)...\n"
	@sleep 0.2

$(OBJS) : $(OBJS_DIR)/%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	
re : fclean all

.PHONY: all clean fclean re