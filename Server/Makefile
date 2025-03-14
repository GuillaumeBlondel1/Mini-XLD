##
## EPITECH PROJECT, 2025
## B-PDG-300-TLS-3-1-PDGD06-guillaume1.blondel
## File description:
## Makefile
##

SRC	:=	src/Main.cpp										\
		src/extra/ExStrings.cpp								\
		src/usage/Usage.cpp									\
		src/file/ConfigFile.cpp								\
		src/file/Ip.cpp										\
		src/file/Port.cpp									\
		src/file/Path.cpp									\
		src/file/Users.cpp									\
		src/account/Account.cpp								\

OBJ_DIR	:=	build

OBJ	:=	$(addprefix $(OBJ_DIR)/, $(notdir ${SRC:.cpp=.o}))

BINARY	:=	XLD-Server

CFLAGS	:=	-std=c++20 -Wall -Wextra -Werror -g

all:	$(OBJ_DIR)	${BINARY}

${OBJ_DIR}:
	@(mkdir -p ${OBJ_DIR})

${OBJ_DIR}/%.o:	src/%.cpp
	@echo "$<..."
	@(g++ ${CFLAGS} -c $< -o $@)

${OBJ_DIR}/%.o:	src/extra/%.cpp
	@echo "$<..."
	@(g++ ${CFLAGS} -c $< -o $@)

${OBJ_DIR}/%.o:	src/usage/%.cpp
	@echo "$<..."
	@(g++ ${CFLAGS} -c $< -o $@)

${OBJ_DIR}/%.o:	src/file/%.cpp
	@echo "$<..."
	@(g++ ${CFLAGS} -c $< -o $@)

${OBJ_DIR}/%.o:	src/account/%.cpp
	@echo "$<..."
	@(g++ ${CFLAGS} -c $< -o $@)

${BINARY}:	${OBJ}
	@echo "Linking ${BINARY}"
	@(g++ ${OBJ} -o ${BINARY})
	@(echo Compilation Finished ✅​)

clean:
	@rm -f ${OBJ}
	@rm -rf ${OBJ_DIR}

fclean:	clean
	@rm -f ${BINARY}

re:	fclean
	@(${MAKE} --no-print-directory all)
