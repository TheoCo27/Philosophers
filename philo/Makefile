# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theog <theog@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 18:10:16 by tcohen            #+#    #+#              #
#    Updated: 2024/11/12 15:02:02 by theog            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#fsanitize=thread

# Nom du compilateur
CC = cc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -pthread -I includes

# Dossiers
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = includes

# Fichiers source et objets (ajouter chaque nom de fichier source sans le chemin)
SRC_NAMES = philo.c time.c check.c nbr.c str.c error.c set.c print.c secure.c \
			free.c safe.c prediction.c watcher.c
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC_NAMES))
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Nom de l'exécutable
NAME = philo

# Règle principale
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier obj s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

# Reconstruire tout
re: fclean all

.PHONY: all clean fclean re
