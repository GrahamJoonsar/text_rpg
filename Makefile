CC = g++
INCLUDE = include/

text_rpg: src/main.cpp src/room.cpp
	@$(CC) -IINCLUDE -o build/text_rpg src/main.cpp src/room.cpp