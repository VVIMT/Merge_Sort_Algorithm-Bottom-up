NAME=BottomUpMergeSort

CC=gcc -g -std=c99 -lpthread

CFLAGS=-Wall -Wextra -Werror

SRCS=main.c Merge_Sort_Bottom_up.c ft_latoi.c get_next_line.c

OBJ=$(SRCS:.c=.o)

$(NAME): Merge_Sort_Bottom_up.h
	@make -C libft/
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME) $(HDDIRS)

all: $(NAME)

clean:
	@make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME) a.out BottomUpMergeSort.dSYM results

re: fclean all

.PHONY: clean
