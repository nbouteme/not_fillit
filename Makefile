#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:08:14 by nbouteme          #+#    #+#              #
#    Updated: 2015/12/02 13:04:19 by nbouteme         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRCDIR = .

INCDIR = libft

LIBDIR = libft

LIBS = ft

SRC = block_man.c      \
	  block_utils.c	   \
	  board.c		   \
	  main.c		   \
	  render.c		   \
	  render_utils.c   \
	  str_utils.c	   \
	  sys_utils.c	   \
	  tetra.c		   \
	  utils.c		   \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBDIRS = $(addprefix -L, $(LIBDIR))
LLIBS = $(addprefix -l, $(LIBS))
INCDIRS = $(addprefix -I, $(INCDIR))

deps:
	@$(foreach lib, $(LIBDIR), @echo "\033[0;34m[-] Building dependency" $(LIBDIR); make -C $(LIBDIR))

cleandeps:
	@$(foreach lib, $(LIBDIR), @echo "\033[0;33m[-] Cleaning dependency" $(LIBDIR); make -C $(LIBDIR) clean)

fcleandeps:
	@$(foreach lib, $(LIBDIR), @echo "\033[0;33m[-] Full Cleaning dependency" $(LIBDIR); make -C $(LIBDIR) fclean)

all: $(NAME)

%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCDIRS) -c $^
	@echo "\033[0;32m[✓] Built C object" $@

$(NAME): $(OBJ) deps
	@echo "\033[0;34m--------------------------------"
	@$(CC) -o $(NAME) $(OBJ) $(LIBDIRS) $(LLIBS)
	@echo "\033[0;31m[✓] Linked C executable" $(NAME)

.PHONY: clean fclean re

clean:
	@/bin/rm -rf $(OBJ)
	@echo "\033[0;33m[✓] Removed object files" $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[0;33m[✓] Removed executable" $(NAME)

re: fclean fcleandeps
	@$(MAKE) all
