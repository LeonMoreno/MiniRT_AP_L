#Variables
NAME	= miniRT
SRC_DIR	= src/
OBJ_DIR	= obj/
CFLAGS	=  -g -o3 -Werror -Wall -Wextra -I include/
MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit
CC		= gcc
RM		= rm -f

#Libft
LIBFT_A		= libft.a
LIBFT_DIR	= libft/
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_A))

#Sources Files
SRC_FILES =	miniRT init_mlx start_render vector_01 vector_02 start_scene\
			ft_utils_01 start_scene_01 start_parsing 00_utils_parsing\
			hit_objects2 utils_minmax the_matrix translate\
			the_matrix2 vector_03\
			ray_trace hit_objects pixel_put colours\
			01_utils_parsing ft_pri_ele ft_pri_ele_2 02_utils_parsing\
			03_utils_parsing ft_hooks 00_events ft_utils_02 01_events\
	
#SRC
SRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF	=	.cache_exists

####

all	: $(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT_DIR)
			@$(CC) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
			@echo $(NAME) Compiled!

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
				@$(CC) $(CFLAGS) -c $< -o $@


$(OBJF)	:
			@mkdir -p $(OBJ_DIR)

clean	:
			$(RM) -r $(OBJ_DIR)
			make -C $(LIBFT_DIR) clean
			$(RM) $(OBJF)

fclean	:	clean
			$(RM) $(NAME)
			make -C $(LIBFT_DIR) fclean
val:
		valgrind   --leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=yes --trace-children=yes ./$(NAME)

re		: fclean all

