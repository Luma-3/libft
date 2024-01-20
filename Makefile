###############
## 	COMPILE	 ##
###############

CC		=	gcc
CFLAGS	=	-g3 -Wall -Werror -Wextra -I

##############
##  SOURCE	##
##############

SRC_DIR	=	sources/

SRC_CHAIN_LIST_DIR		=	chain_list/
SRC_CHAIN_LIST_LIST		=	ft_lstadd_back.c	\
							ft_lstadd_front.c	\
							ft_lstclear.c		\
							ft_lstdelone.c		\
							ft_lstiter.c		\
							ft_lstlast.c		\
							ft_lstmap.c			\
							ft_lstnew.c 		\
							ft_lstsize.c
SRC_CHAIN_LIST			=	$(addprefix $(SRC_CHAIN_LIST_DIR), $(SRC_CHAIN_LIST_LIST))

SRC_CHAR_DIR			=	char/
SRC_CHAR_LIST			=	ft_tolower.c		\
							ft_toupper.c
SRC_CHAR				=	$(addprefix $(SRC_CHAR_DIR), $(SRC_CHAR_LIST))

SRC_COMPARE_DIR			=	compare/
SRC_COMPARE_LIST		=	ft_isalnum.c 		\
							ft_isalpha.c 		\
							ft_isascii.c		\
							ft_isdigit.c 		\
							ft_isprint.c
SRC_COMPARE				=	$(addprefix $(SRC_COMPARE_DIR), $(SRC_COMPARE_LIST))

SRC_GNL_DIR				=	gnl/
SRC_GNL_LIST			=	get_next_line.c		\
							get_next_line_utils.c
SRC_GNL					=	$(addprefix $(SRC_GNL_DIR), $(SRC_GNL_LIST))

SRC_INTEGER_DIR			=	integer/
SRC_INTEGER_LIST		=	ft_atoi.c 			\
							ft_itoa.c			\
							ft_strtod.c
SRC_INTEGER				=	$(addprefix $(SRC_INTEGER_DIR), $(SRC_INTEGER_LIST))	

SRC_MEM_DIR				=	memory/
SRC_MEM_LIST			=	ft_bzero.c 			\
							ft_calloc.c 		\
							ft_memchr.c 		\
							ft_memcmp.c 		\
							ft_memcpy.c 		\
							ft_memmove.c 		\
							ft_memset.c
SRC_MEM					=	$(addprefix $(SRC_MEM_DIR), $(SRC_MEM_LIST))

SRC_PRINTF_DIR			=	printf/
SRC_PRINTF_LIST			=	flags_utils.c		\
							ft_printf.c			\
							utils.c				\
							format_function.c	\
							format_ptr.c		\
							format_hex.c		\
							format_unsigned.c	\
							specifier_utils.c
SRC_PRINTF				=	$(addprefix $(SRC_PRINTF_DIR), $(SRC_PRINTF_LIST))

SRC_STACK_DIR			=	stack/
SRC_STACK_LIST			=	ft_create_stack.c	\
							ft_free_stack.c		\
							ft_pop.c			\
							ft_push.c			\
							ft_roll_down.c		\
							ft_roll_up.c		\
							ft_stack_iter.c		\
							ft_swap.c			\
							ft_valueof.c
SRC_STACK				= $(addprefix $(SRC_STACK_DIR), $(SRC_STACK_LIST))

SRC_STRING_DIR			=	string/
SRC_STRING_LIST			=	ft_split.c			\
							ft_strchr.c 		\
							ft_strdup.c			\
							ft_striteri.c		\
							ft_strjoin.c		\
							ft_strlcat.c 		\
							ft_strlcpy.c 		\
							ft_strlen.c			\
							ft_strmapi.c		\
							ft_strncmp.c		\
							ft_strnstr.c		\
							ft_strrchr.c		\
							ft_strtrim.c		\
							ft_substr.c
SRC_STRING				=	$(addprefix $(SRC_STRING_DIR), $(SRC_STRING_LIST))

SRC_WRITE_DIR			=	write/
SRC_WRITE_LIST			=	ft_putchar_fd.c		\
							ft_putendl_fd.c		\
							ft_putnbr_fd.c		\
							ft_putstr_fd.c
SRC_WRITE				=	$(addprefix $(SRC_WRITE_DIR), $(SRC_WRITE_LIST))

SRC_LIST				=	$(SRC_CHAIN_LIST)	\
							$(SRC_CHAR)			\
							$(SRC_COMPARE)		\
							$(SRC_GNL)			\
							$(SRC_INTEGER)		\
							$(SRC_MEM)			\
							$(SRC_PRINTF)		\
							$(SRC_STACK)		\
							$(SRC_STRING)		\
							$(SRC_WRITE)
SRC						=	$(addprefix $(SRC_DIR), $(SRC_LIST))

################
##	INCLUDES  ##
################

INCLUDES	=	includes/

################
##	OBJ/NAME  ##
################

NAME		=	libft.a

OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

################
##	PROGRESS  ##
################

TOTAL_SRCS		=	$(words $(SRC))
COMPILED_SRCS	=	0

define print_progress
	@echo -n "$(COLOR_BLUE)Compiling: [$(COLOR_GREEN)"
	@for i in $(shell seq 1 25); do \
		[ $$i -le $$(($(1)*25/$(2))) ] && echo -n "#" || echo -n "."; \
	done
	@echo -n "$(COLOR_BLUE)] $(1)/$(2)$(COLOR_RESET)\r"
endef

##############
##	COLORS	##
##############

COLOR_RESET	=	\033[0m
COLOR_GREEN	=	\033[32m
COLOR_BLUE	=	\033[34m
COLOR_RED	=	\033[31m

#############
##	RULES  ##
#############

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_CHAIN_LIST_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_CHAR_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_COMPARE_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_GNL_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_INTEGER_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_MEM_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_PRINTF_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_STACK_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_STRING_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_WRITE_DIR)


$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

	@$(eval COMPILED_SRCS=$(shell echo $$(($(COMPILED_SRCS)+1))))
	@$(call print_progress,$(COMPILED_SRCS),$(TOTAL_SRCS))

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\n$(COLOR_GREEN)Compilation complete !$(COLOR_RESET)"

clean: 
	@rm -fr  $(OBJ_DIR)
	@rm -f norme_log
	@echo "$(COLOR_GREEN)Remove Object complete !$(COLOR_RESET)"

fclean: clean cleanso 
	@rm -f $(NAME)
	@echo "$(COLOR_GREEN)Remove libft complete !$(COLOR_RESET)"

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

norme:
	@echo "$(COLOR_BLUE)Norminette...$(COLOR_RESET)"
	@norminette $(SRC) $(INCLUDES) > norme_log ; \
	if grep -q "Error" norme_log; then \
		echo "$(COLOR_RED)Norme : KO!$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)Norme : OK!$(COLOR_RESET)"; \
	fi; \
	
cleanso:
	@rm -f libft.so

.PHONY: all clean fclean re