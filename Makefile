CC = g++
INCLUDE = include/

text_rpg: build/
	@$(CC) -IINCLUDE -o build/text_rpg src/main.cpp src/room.cpp src/room_io.cpp


build/:
	@mkdir build
