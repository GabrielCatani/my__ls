CC = gcc
FLAGS = -Wall -Wextra -Werror -g3 -
SRCS := ${wildcard src/*.c}

all: ${SRCS}
	${CC} ${FLAGS}