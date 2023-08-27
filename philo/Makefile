VPATH	= ./src/ ./src/errors ./src/parser ./src/states ./src/utils ./src/states
SRCS	= main.c print.c atoi.c init_arguments.c handling.c \
		  logic_utils.c initial.c get_time.c getter_table.c \
		  itoa.c eating.c sleeping.c thinking.c \
		  print_action.c forks.c god.c update_time.c
BUILDIR	= ./build/
OBJS	= $(addprefix $(BUILDIR), $(SRCS:.c=.o))
INCLUDE	= ./include/
NAME	= philo
CFLAGS	= -g -Wall -Wextra -Werror -pthread


all: $(NAME)

$(NAME): $(OBJS)
	@printf "\nBuilding $(NAME) program!"
	@$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJS) -o $(NAME)
	@echo "\nBuild complete!"

$(BUILDIR)%.o: %.c
	@printf "\rCompiling the $<"
	@test -d $(BUILDIR) || mkdir $(BUILDIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@test -d $(BUILDIR) && rm -rf $(BUILDIR)

fclean: clean
	@test -f $(NAME) && rm -rf $(NAME)

re: fclean all
