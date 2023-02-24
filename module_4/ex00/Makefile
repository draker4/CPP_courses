# **********************  MINISHELL MAKEFILE  ********************** #

.PHONY			:	all clean fclean re debug run runs rund runv

# **************************  VARIABLES  *************************** #

# ---  Final Executable  --- #

NAME			=	polymorphism
DEBUG			=	polymorphism_debug

# ----------  Directories  ----------- #

DIR_HEAD		=	./
DIR_SRCS		=	./
DIR_OBJS		=	.build/
DIR_OBJS_D		=	.build_debug/

# -------------  Files  -------------- #

HEAD			=	

SRCS			=	main.cpp		Animal.cpp		\
					Cat.cpp			Dog.cpp			\
					WrongAnimal.cpp	WrongCat.cpp	\

OBJS			=	${SRCS:%.cpp=${DIR_OBJS}%.o}
OBJS_D			=	${SRCS:%.cpp=${DIR_OBJS_D}%.o}

DEPS			=	${OBJS:.o=.d}
DEPS_D			=	${OBJS_D:.o=.d}

# --------------  Path  -------------- #

PATH_HEAD		=	${addprefix ${DIR_HEAD}, ${HEAD}}

# ----------  Compilation  ----------- #

CC				=	c++
CFLAGS			= 	-Wall -Wextra -Werror -std=c++98
AR				= 	ar rcs
FSANITIZE		=	-fsanitize=address
OPTI			=	-O3
MMD				=	-MMD

# ------------  Commands  ------------ #

RM				=	rm -rf
MKDIR			=	mkdir -p
LLDB			=	lldb
VALGRIND		=	valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes

# ****************************  RULES  ***************************** #

all					:	
						$(MAKE) -j ${NAME}

# ---------  Compiled Rules  --------- #

${NAME}				:	${OBJS}
						${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${DIR_OBJS}%.o		:	${DIR_SRCS}%.cpp Makefile | ${DIR_OBJS}
						${CC} ${CFLAGS} ${MMD} -I ${DIR_HEAD} -c $< -o $@

${DIR_OBJS}			:
						${MKDIR} ${DIR_OBJS}

-include ${DEPS}

# ------  Compiled Rules Debug  ------ #

${DEBUG}			:	${OBJS_D}
						${CC} ${CFLAGS} ${OBJS_D} -g3 ${FSANITIZE} -o ${DEBUG}

${DIR_OBJS_D}%.o	:	${DIR_SRCS}%.cpp Makefile | ${DIR_OBJS_D}
						${CC} ${CFLAGS} -I ${DIR_HEAD} ${MMD} -g3 ${FSANITIZE} -c $< -o $@

${DIR_OBJS_D}		:
						${MKDIR} ${DIR_OBJS_D}

-include ${DEPS_D}

# ---------  Usual Commands  --------  #

clean				:	
						${RM} ${DIR_OBJS}
						${RM} ${DIR_OBJS_D}

fclean				:	clean
						${RM} ${NAME}
						${RM} ${DEBUG}

re					:
						$(MAKE) fclean
						$(MAKE) all

# ---------  Other Commands  --------- #

debug				:	
						$(MAKE) -j ${DEBUG}

# -----------  Run Commands  --------- #

run					:	all
						./${NAME}

runs				:	debug
						./${DEBUG}

rund				:	debug
						${LLDB} ./${DEBUG}

runv				:	all
						${VALGRIND} ./${NAME}
