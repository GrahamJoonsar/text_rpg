#pragma once

#include "room.hpp"

Room * read_adventure(std::string path);
void write_adventure(std::string path, Room * starting_room);