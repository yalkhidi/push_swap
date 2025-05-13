CC:= cc
CCFLAGS:= -Wall -Werror -Wextra
FILES:= \
		algorithm/cost_calculation.c \
		algorithm/execute_rotations.c \
		algorithm/mechanical_turk.c \
		algorithm/push_back.c \
		algorithm/push_to_b.c \
		algorithm/range.c \
		algorithm/sort_three.c \
		operations/push.c \
		operations/reverse_rotate.c \
		operations/rotate.c \
		operations/swap.c \
		operations/stack_ops.c \
		utils/ft_split.c \
		utils/utils.c \
		arg_validation.c \
		input_handler.c \
		main.c
BONUS:= algorithm/cost_calculation.c \
		algorithm/execute_rotations.c \
		algorithm/mechanical_turk.c \
		algorithm/push_back.c \
		algorithm/push_to_b.c \
		algorithm/range.c \
		algorithm/sort_three.c \
		operations/push.c \
		operations/reverse_rotate.c \
		operations/rotate.c \
		operations/swap.c \
		operations/stack_ops.c \
		utils/ft_split.c \
		utils/utils.c \
		arg_validation.c \
		input_handler.c \
		bonus/bonus_utils.c \
		bonus/op_cmp.c \
		bonus/bonus.c

HEADER:= push_swap.h
NAME:= push_swap
GNL:= get_next_line/gnl.a

OFILES:= $(FILES:.c=.o)
BOFILES:= $(BONUS:.c=.o)
all:$(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(CCFLAGS) $(OFILES) -o $(NAME)

$(GNL):
	make -C get_next_line

bonus: $(BOFILES) $(GNL)
	$(CC) $(CCFLAGS) $(BOFILES) $(GNL) -o checker

clean:
	make clean -C get_next_line
	rm -f $(OFILES) $(BOFILES)

fclean: clean
	make fclean -C get_next_line
	rm -f $(NAME) checker

re: fclean all

.PHONY: all clean fclean re