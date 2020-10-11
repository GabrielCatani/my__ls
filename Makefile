CC=gcc
FLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
SRCS:=${wildcard src/*.c}
HEADER=header/my_ls.h
TARGET=my_ls

$(TARGET): $(SRCS})
	@echo "Creating my_ls binary.."
	@$(CC) $(FLAGS) $(SRCS) $(HEADER) -o $(TARGET)

clean:
	@echo "Removing my_ls binary.."
	@/bin/rm -rf $(TARGET)

.PHONY: clean 