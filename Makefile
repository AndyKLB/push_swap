#######################################################
## ARGUMENTS

NAME = push_swap
BONUS = push_swap_bonus

CC	= cc
RM = rm -rf
FLAG	= -Wall -Wextra -Werror -g3

#######################################################
## SOURCES

SRCS_FILES = push_swap.c ft_split.c handle_error.c \
			stack_init.c stack_utils.c  \
			command_push.c command_rev_rotate.c command_rotate.c \
			command_swap.c easy_sort.c set_nodes.c sort_stacks.c \
			

BONUS_SRCS_FILES = push_swap_bonus.c \

SRCS_DIR = ./srcs
BONUS_SRCS_DIR = ./srcs_bonus

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
BONUS_SRCS = $(addprefix $(BONUS_SRCS_DIRSRCS_DIR)/, $(BONUS_SRCS_FILES))

OBJECTS = $(SRCS:.c=.o)
BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)


#######################################################
## RULES

$(NAME): $(OBJECTS)
			$(CC) $(FLAG) $(OBJECTS) -o $@

all: $(NAME) $(BONUS)


bonus: $(BONUS)


.c.o:
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)


$(BONUS): $(BONUS_OBJECTS)
			$(CC) $(FLAG) $(BONUS_OBJECTS) -o $@

clean:
			$(RM) $(OBJECTS)

clean_bonus:
			$(RM) $(BONUS_OBJECTS)
fclean: clean clean_bonus
			$(RM) $(NAME) $(BONUS)

re:	fclean $(NAME)

re_bonus: fclean bonus

.PHONY: all bonus clean clean_bonus fclean re re_bonus