#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:08:14 by nbouteme          #+#    #+#              #
#    Updated: 2015/12/03 12:14:22 by nbouteme         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRCDIR = .

INCDIR = libft

LIBDIR = libft

LIBS = libft.a
LINK = ft

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

CFLAGS = -Wall -Wextra -Werror -O3

LIBDIRS = $(addprefix -L, $(LIBDIR))
LLIBS = $(addprefix -l, $(LINK))
INCDIRS = $(addprefix -I, $(INCDIR))

all: $(NAME)

$(LIBDIR)/%.a:
	@$(foreach lib, $(LIBDIR), @echo "\033[0;34m[-] Building dependency" $@; make -C $(LIBDIR))

%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCDIRS) -c $^
	@echo "\033[0;32m[✓] Built C object" $@

$(NAME): $(OBJ) $(LIBDIR)/libft.a
	@echo "\033[0;34m--------------------------------"
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBDIRS) $(LLIBS)
	@echo "\033[0;31m[✓] Linked C executable" $(NAME)


.PHONY: clean fclean re cleandeps fcleandeps

cleandeps:
	@$(foreach lib, $(LIBDIR), @echo "\033[0;33m[-] Cleaning dependency" $(LIBDIR); make -C $(LIBDIR) clean)

fcleandeps:
	@$(foreach lib, $(LIBDIR), @echo "\033[0;33m[-] Full Cleaning dependency" $(LIBDIR); make -C $(LIBDIR) fclean)

clean: cleandeps
	@/bin/rm -rf $(OBJ)
	@echo "\033[0;33m[✓] Removed object files" $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[0;33m[✓] Removed executable" $(NAME)

re: fclean fcleandeps
	@$(MAKE) all
