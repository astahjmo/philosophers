VPATH	= ./src/ ./src/utils ./src/dinner
SRCS	= main.c
BUILDIR	= ./build/
OBJS	= $(addprefix $(BUILDIR), $(SRCS:.c=.o))
INCLUDE	= ./include/
NAME	= philo
CC		= gcc
CFLAGD	= -g #-Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME) program!"
	@$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJS) -o $(NAME)
	@echo "BUild complete!"

$(BUILDIR)%.o: %.c
	@echo "Compiling the $<"
	@test -d $(BUILDIR) || mkdir $(BUILDIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(BUILDIR)

fclean: clean
	@rm $(NAME)
