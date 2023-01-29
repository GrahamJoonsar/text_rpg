#include "room.hpp"

Room::Room (std::string description, std::vector<std::string> options) {
    this->description = description;
    this->options = options;
}

// Returns true if game is ending, false otherwise
bool Room::display_room () {
    system("CLS");
    std::cout << "Description:\n" << description << std::endl;
    if (options.size() != 0){
        std::cout << "\nOptions:\n";
        for (int i = 0; i < options.size(); i++){
            std::cout << "(" << i+1 << "): " << options[i] << std::endl;
        }
        std::cout << std::endl;
        return false;
    } else {
        std::cout << "\nThe end.\n";
        return true;
    }
}

void Room::set_adjacents (std::vector<Room*> adjacent_rooms){
    this->adjacent_rooms = adjacent_rooms;
}

void Room::make_choice (Room ** current_room){
    std::cout << "Make your choice:" << std::endl;
    std::cout.flush();
    int choice_index;
    std::cin >> choice_index;
    choice_index--;

    *current_room = adjacent_rooms[choice_index];
}