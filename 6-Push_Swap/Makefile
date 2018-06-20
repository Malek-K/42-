
.PHONY: all, clean, fclean, re

#-----------------------------------------------------------#
# NAME, PATHS, SOURCES, OBJECTSS AND INCLUDES FOR PUSH SWAP #
#-----------------------------------------------------------#
PS_NAME = push_swap

PS_SRCS_PATH = ps_sources
PS_SRCS_NAME = main.c \
			ft_check_errors.c ft_isnb.c\
			ft_putarg_inlst.c \
			ft_sa.c ft_sb.c ft_ss.c ft_pa.c ft_pb.c \
			ft_ra.c ft_rb.c ft_rr.c ft_rra.c ft_rrb.c ft_rrr.c \
			ft_sort_little.c ft_sort_medium.c ft_real_sort.c \
			ft_ins_sort.c ft_decide.c ft_quick_sort.c\
			ft_repush.c ft_sort_three_inb.c ft_sort_little_inb.c  \
			ft_mini_sortb.c  ft_deal_bigx.c ft_deal_three.c ft_print_lists.c

PS_SRCS = $(addprefix $(PS_SRCS_PATH)/,$(PS_SRCS_NAME))

PS_OBJS_PATH = ps_objects
PS_OBJS_NAME = $(PS_SRCS_NAME:.c=.o)
PS_OBJS = $(addprefix $(PS_OBJS_PATH)/,$(PS_OBJS_NAME))

PS_INC = includes/push_swap.h 

#---------------------------------------------------------#
# NAME, PATHS, SOURCES, OBJECTSS AND INCLUDES FOR CHECKER #
#---------------------------------------------------------#
CH_NAME = checker

CH_SRCS_PATH = ch_sources
CH_SRCS_NAME = main.c \
			ft_check_errors.c \
			ft_putarg_inlst.c \
			ft_sa.c ft_sb.c ft_ss.c ft_pa.c ft_pb.c \
			ft_ra.c ft_rb.c ft_rr.c ft_rra.c ft_rrb.c ft_rrr.c \
			ft_moves.c ft_print_lists.c

CH_SRCS = $(addprefix $(CH_SRCS_PATH)/,$(CH_SRCS_NAME))

CH_OBJS_PATH = ch_objects
CH_OBJS_NAME = $(CH_SRCS_NAME:%.c=%.o)
CH_OBJS = $(addprefix $(CH_OBJS_PATH)/,$(CH_OBJS_NAME))
CH_INC = includes/checker.h


#---------------------------------------------------------#
# 					LIBRAY AND FLAGS					  #
#---------------------------------------------------------#

CFLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a

all: libftcreate $(PS_NAME) $(CH_NAME)

libftcreate:
	@echo "\033[31;5;mCompiling libft...\033[0m"
	@make all -C libft/
	@echo "\033[31;3mCompiling Done !\033[0m"

$(PS_NAME):  $(PS_OBJS) $(LIB)
	@gcc $(CFLAGS) $(PS_OBJS) $(LIB) -o $(PS_NAME)
	@echo "\n\033[1;4mPush_Swap CREATED.\033[0m"

$(PS_OBJS): $(PS_SRCS)
	@mkdir $(PS_OBJS_PATH) 2> /dev/null || true
	@gcc $(CFLAGS) -c $(PS_SRCS) -I $(PS_INC)
	@mv $(PS_OBJS_NAME) $(PS_OBJS_PATH)

$(CH_NAME): $(CH_OBJS) $(LIB) 
	@gcc $(CFLAGS) $(CH_OBJS) $(LIB) -o $(CH_NAME)
	@echo "\n\033[1;4mChecker CREATED.\033[0m"

$(CH_OBJS): $(CH_SRCS)
	@mkdir $(CH_OBJS_PATH) 2> /dev/null || true
	@gcc $(CFLAGS) -c $(CH_SRCS) -I $(CH_INC)
	@mv $(CH_OBJS_NAME) $(CH_OBJS_PATH)

clean:
	@echo "\033[36;5mCleaning..."
	@make clean -C libft/
	@rm -f $(PS_OBJS)
	@rmdir $(PS_OBJS_PATH) 2> /dev/null || true
	@rm -f $(CH_OBJS)
	@rmdir $(CH_OBJS_PATH) 2> /dev/null || true
	@echo "\033[36;3m Cleaning Done !\033[0m"

fclean: clean
	@echo "\033[32;5mFcleaning..."
	@make fclean -C libft/
	@rm -f $(PS_NAME)
	@rm -f $(CH_NAME)
	@echo "\033[32;3m Fcleaning Done !\033[0m"

re: fclean all
