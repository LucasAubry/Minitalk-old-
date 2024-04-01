#-----------------------Flags_and_Name---------------------

CC =		cc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude -g -O0

LFLAGS = -Llib -lft -ldl -lglfw

CLIENT = client
SERVER = server
#------------------------Source-----------------------------

# Files

LIB = lib/libft.a

# Sources and objects
FILES_S = server 

SRCS_S = $(addprefix src/, $(addsuffix .c, $(FILES_S)))
OBJS_S = $(addprefix obj/, $(addsuffix .o, $(FILES_S)))

FILES_C = client

SRCS_C = $(addprefix src/, $(addsuffix .c, $(FILES_C)))
OBJS_C = $(addprefix obj/, $(addsuffix .o, $(FILES_C)))

OBJS = $(OBJS_C) $(OBJS_S)
#------------------------Colors-----------------------------

define generate_random_color
python3 -c "import random; \
print(''.join(['\033[38;5;' + str(random.randint(16, 255)) + 'm' + c + '\033[0m' for c in '$(1)']))"
endef

#------------------------Rules------------------------------


all:	$(CLIENT) $(SERVER)

$(CLIENT): $(LIB) $(OBJS_C)
		@$(call generate_random_color, $(CC) $(CFLAGS) -o $@ $(OBJS_C) $(LFLAGS) $(LIB))
		@$(CC) $(CFLAGS) -o $@ $(OBJS_C) $(LFLAGS) $(LIB)

$(SERVER): $(LIB) $(OBJS_S)
		@$(call generate_random_color, $(CC) $(CFLAGS) -o $@ $(OBJS_S) $(LFLAGS) $(LIB))
		@$(CC) $(CFLAGS) -o $@ $(OBJS_S) $(LFLAGS) $(LIB)

$(LIB):
	make -C lib/Libft
	cp lib/Libft/libft.a lib/

obj/%.o: src/%.c
	@$(call generate_random_color, $(CC) $(CFLAGS) -c $< -o $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS) $(BONUSOBJS)

fclean:	clean
		rm -f $(CLIENT) $(SERVER)
		rm -f lib/libft.a
		make fclean -C lib/Libft

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


re:	fclean all

.PHONY: all clean fclean re
