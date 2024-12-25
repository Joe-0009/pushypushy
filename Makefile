NAME = push_swap
BNAME = checker
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory/cost.c \
		mandatory/ft_split.c \
		mandatory/operations.c \
		mandatory/operations2.c \
		mandatory/operations3.c \
		mandatory/parsing.c \
		mandatory/positions.c \
		mandatory/push_swap.c \
		mandatory/sort.c \
		mandatory/stack.c \
		mandatory/string.c \
		mandatory/utils.c \
		mandatory/utils2.c \
		bonus/get_next_line_utils.c \

BONUS = bonus/checker.c \
		mandatory/operations.c \
		mandatory/operations2.c \
		mandatory/operations3.c \
		mandatory/parsing.c \
		mandatory/utils.c \
		mandatory/utils2.c \
		bonus/get_next_line_utils.c \
		bonus/get_next_line.c \
		mandatory/stack.c \
		mandatory/string.c \
		mandatory/ft_split.c \

OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@make clean
	
bonus : $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)
	@make clean

clean : 
	@rm -rf $(OBJS) $(BOBJS)

fclean : clean
	@rm -f $(NAME) $(BNAME)

re : fclean all

.SECONDARY : $(OBJS)