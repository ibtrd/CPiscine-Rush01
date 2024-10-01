# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 22:47:55 by ibertran          #+#    #+#              #
#    Updated: 2024/10/01 22:46:18 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = rush-01

# *** FILES ****************************************************************** #

MAKE_DIR := .make/
BUILD_DIR := $(MAKE_DIR)$(shell git branch --show-current 2>/dev/null)/

SRCS_DIR = srcs/
SRCS = $(addsuffix .c, $(SRC))

OBJS = $(patsubst %.c,$(BUILD_DIR)%.o,$(SRCS))

DEPS = $(patsubst %.o,%.d,$(OBJS))

SRC = \
	main \

# *** LIBRARIES && INCLUDES  ************************************************* #

INCS_DIR = incs/
INCS = \
	$(INCS_DIR) \

# *** CONFIG ***************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

DEFINES		=

CPPFLAGS 	=	$(addprefix -I, $(INCS)) \
				$(addprefix -D, $(DEFINES)) \
				-MMD -MP \

MAKEFLAGS	=	--no-print-directory

# *** MODES ****************************************************************** #

MODE_TRACE = $(MAKE_DIR).trace 
LAST_MODE = $(shell cat $(MODE_TRACE) 2>/dev/null)

ifneq ($(MODE),)
BUILD_DIR := $(BUILD_DIR)$(MODE)/
endif

ifeq ($(MODE),debug)
CFLAGS := $(CFLAGS) -g3
else ifeq ($(MODE),fsanitize)
CFLAGS := $(CFLAGS) -g3 -fsanitize=address
else ifneq  ($(MODE),)
ERROR = MODE
endif

ifneq ($(LAST_MODE),$(MODE))
$(NAME) : FORCE
endif

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(MODE)" > $(MODE_TRACE)

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY : debug
debug :
	$(MAKE) MODE=debug

.PHONY : fsanitize
fsanitize :
	$(MAKE) MODE=fsanitize

.PHONY : clean
clean :
	rm -rf $(BUILD_DIR)

.PHONY : fclean
fclean :
	rm -rf $(MAKE_DIR) $(NAME)

.PHONY : re
re : fclean
	$(MAKE)

.PHONY : print-%
print-% :
	@echo $(patsubst print-%,%,$@)=
	@echo $($(patsubst print-%,%,$@))

.PHONY : FORCE
FORCE :
ifeq ($(ERROR),MODE)
	$(error Invalid mode: $(MODE))
endif

# *** SPECIAL TARGETS ******************************************************** #

-include $(DEPS)

.DEFAULT_GOAL := all
