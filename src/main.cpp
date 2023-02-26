#include "room.hpp"
#include "room_io.hpp"

int main(void) {
    // Get the adventure from the user
    std::cout << "Welcome to the Text RPG game engine, please type the path of the rpg you want to play:\n";
    std::string path;
    std::cin >> path;
    Room * current_room = read_adventure(path);

    // Main game loop, do not change
    while (1) {
        if (current_room->display_room()) break;
        current_room->make_choice(&current_room);
    }
}