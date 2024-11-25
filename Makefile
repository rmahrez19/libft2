# Variables
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = libft.a

SRC     = ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c ft_isalnum.c ft_isalpha.c \
          ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c ft_memmove.c ft_memset.c \
          ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
          ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
          ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
          ft_substr.c ft_tolower.c ft_toupper.c ft_memchr.c ft_memcmp.c

OBJ     = $(SRC:.c=.o)

SRC_B   = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
          ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c  

OBJ_B   = $(SRC_B:.c=.o)

HEADER  = libft.h

# Couleurs
RED     = \033[0;31m
YELLOW  = \033[0;33m
GREEN   = \033[0;32m
NC      = \033[0m

# Règles de compilation
all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo -e "$(GREEN)Static library created: $(NAME)$(NC)"

%.o: %.c $(HEADER)
	@printf "$(YELLOW)Generating libft object... %-38.38s \r$(NC)" $@
	$(CC) $(CFLAGS) -c $< -o $@

so: $(OBJ)
	@echo "Creating dynamic library libft.so..."
	$(CC) -nostartfiles -shared -o libft.so $(OBJ)

libft.so: so

bonus: $(OBJ) $(OBJ_B)
	@ar rc $(NAME) $(OBJ) $(OBJ_B)
	@ranlib $(NAME)
	@echo "$(GREEN)Bonus added!$(NC)"

clean:
	@echo "$(RED)Removing object files...$(NC)"
	@rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	@echo "$(RED)Removing all generated files...$(NC)"
	@rm -f $(NAME) libft.so

re: fclean all


.PHONY: all clean fclean re bonus so

# Testeurs
runtesters: installtesters tests

installtesters:
	@echo "$(GREEN)Installing Tripouille$(NC)"
	@git clone https://github.com/Tripouille/libftTester.git Tripouille

	@echo "$(YELLOW)Installing WarMachine$(NC)"
	@git clone https://github.com/0x050f/libft-war-machine.git WarMachine
	@bash WarMachine/grademe.sh
	@sed -i "s|PATH_LIBFT=.*|PATH_LIBFT=$(shell pwd)|" WarMachine/my_config.sh

	@echo "$(RED)Installing UnitTest$(NC)"
	@git clone https://github.com/alelievr/libft-unit-test.git UnitTest
	@sed -i "s|LIBFTDIR = .*|LIBFTDIR = $(shell pwd)|" UnitTest/Makefile
	@echo "$(NC)"

tests: test1 test2 test3

test1: fclean
	@echo "$(GREEN)Executing Tripouille$(NC)"
	@make -C ./Tripouille a
	@make fclean

test2: fclean
	@echo "$(YELLOW)Executing WarMachine$(NC)"
	@bash WarMachine/grademe.sh
	@make fclean

test3: fclean
	@echo "$(RED)Executing UnitTest$(NC)"
	@make -C ./UnitTest f
	@make fclean

rmtesters:
	@rm -rf Tripouille WarMachine UnitTest

