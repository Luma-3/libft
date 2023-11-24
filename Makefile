###############
## 	COMPILE	 ##
###############

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

##############
##  SOURCE	##
##############

SRC		=	ft_atoi.c 			\
			ft_bzero.c 			\
			ft_isalnum.c 		\
			ft_isalpha.c 		\
			ft_isascii.c		\
			ft_isdigit.c 		\
			ft_isprint.c		\
			ft_memchr.c 		\
			ft_memcmp.c 		\
			ft_memcpy.c 		\
			ft_memmove.c 		\
			ft_memset.c 		\
			ft_strchr.c 		\
			ft_strlcat.c 		\
			ft_strlcpy.c 		\
			ft_strlen.c			\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_calloc.c			\
			ft_strdup.c			\
			ft_substr.c			\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_split.c			\
			ft_itoa.c			\
			ft_strmapi.c		\
			ft_striteri.c		\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_lstnew.c 		\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\

################
##	OBJ/NAME  ##
################

NAME	=	libft.a

OBJ_DIR	=	obj/

OBJ		=	$(SRC:.c=.o)
OBJ_PREFIXED = $(addprefix $(OBJ_DIR), $(OBJ))


################
##	PROGRESS  ##
################

TOTAL_SRCS := $(words $(SRC))
COMPILED_SRCS := 0

##############
##	COLORS	##
##############

COLOR_RESET = \033[0m
COLOR_GREEN = \033[32m
COLOR_BLUE = \033[34m

#############
##	RULES  ##
#############

$(OBJ_DIR)%.o : %.c libft.h 
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

	@$(eval COMPILED_SRCS=$(shell echo $$(($(COMPILED_SRCS)+1))))
	@echo -n "$(COLOR_BLUE)Compiling Objects Libft: $(COLOR_RESET)[$(COLOR_GREEN)"
	@for i in $(shell seq 1 25); do \
		if [ $$i -le $$(($(COMPILED_SRCS)*25/$(TOTAL_SRCS))) ]; then \
			echo -n "♥"; \
		else \
			echo -n "."; \
		fi; \
	done
	@echo -n "$(COLOR_RESET)] $(COMPILED_SRCS)/$(TOTAL_SRCS)\r"

all: $(NAME)

$(NAME): $(OBJ_PREFIXED)
	@echo "$(COLOR_BLUE)\nCompiling libft library...$(COLOR_RESET)"
	@ar rc $(NAME) $(OBJ_PREFIXED)
	@echo "$(COLOR_GREEN)Compilation complete !$(COLOR_RESET)"

clean: 
	@rm -fr  $(OBJ_DIR)
	@echo "$(COLOR_GREEN)Remove Object complete !$(COLOR_RESET)"

fclean: clean cleanso
	@rm -f $(NAME)
	@echo "$(COLOR_GREEN)Remove libft complete !$(COLOR_RESET)"

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ_PREFIXED)

cleanso:
	@rm -f libft.so

.Phony: all clean fclean re