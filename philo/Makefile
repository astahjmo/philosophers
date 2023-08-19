VPATH	= ./src/ ./src/errors ./src/parser ./src/states ./src/utils
SRCS	= main.c print.c atoi.c init_arguments.c handling.c logic_utils.c
BUILDIR	= ./build/
OBJS	= $(addprefix $(BUILDIR), $(SRCS:.c=.o))
INCLUDE	= ./include/
NAME	= philo
CFLAGS	= -g -Wall -Wextra -Werror


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
	rm -rf $(BUILDIR)

fclean: clean
	@rm $(NAME)

re: fclean all
