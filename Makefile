CC =		cc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude -g -O0

LIB = lib/libft.a
LFLAGS = -Llib -lft -ldl -lglfw -pthread

FILES = main \
SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix obj/, $(addsuffix .o, $(FILES)))

define generate_random_color
python3 -c "import random; \
print(''.join(['\033[38;5;' + str(random.randint(16, 255)) + 'm' + c + '\033[0m' for c in '$(1)']))"
endef

NAME = so_long

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIB) $(OBJS)
		@$(call generate_random_color, $(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS) $(LIB))
		@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS) $(LIB)

$(LIB):
	make -C lib/Libft
	cp lib/Libft/libft.a lib/

obj/%.o: src/%.c
	@$(call generate_random_color, $(CC) $(CFLAGS) -c $< -o $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

clean:
		rm -f $(OBJS) $(BONUSOBJS)

fclean:	clean
		rm -f $(NAME)
		rm -f lib/libft.a
		make fclean -C lib/Libft

re:	fclean all

.PHONY: all clean fclean re
