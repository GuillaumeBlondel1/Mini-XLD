##
## EPITECH PROJECT, 2025
## B-PDG-300-TLS-3-1-PDGD06-guillaume1.blondel
## File description:
## Makefile
##

SRC	:=	src/Main.cpp										\
		src/Window.cpp										\
		src/WindowDisplay.cpp								\

OBJ_DIR	:=	build

OBJ	:=	$(addprefix $(OBJ_DIR)/, $(notdir ${SRC:.cpp=.o}))

BINARY	:=	XLD-Client

CFLAGS	:=	-std=c++20 -Wall -Werror -Wextra -g

all:	$(OBJ_DIR)	${BINARY}

${OBJ_DIR}:
	@(mkdir -p ${OBJ_DIR})

${OBJ_DIR}/%.o:	src/%.cpp
	@echo "$<..."
	@(g++ ${CFLAGS} -c $< -o $@)

${BINARY}:	${OBJ}
	@echo "Linking ${BINARY}"
	@(g++ ${OBJ} -o ${BINARY} -lraylib)
	@(echo Compilation Finished ✅​)

clean:
	@rm -f ${OBJ}
	@rm -rf ${OBJ_DIR}

fclean:	clean
	@rm -f ${BINARY}

re:	fclean
	@(${MAKE} --no-print-directory all)
