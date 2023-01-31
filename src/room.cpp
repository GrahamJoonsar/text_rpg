#include "room.hpp"

Room::Room (){}
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

void Room::set_description (std::string description){
    this->description = description;
}

void Room::set_options (std::vector<std::string> options){
    this->options = options;
}

void Room::set_adjacents (std::vector<Room*> adjacent_rooms){
    this->adjacent_rooms = adjacent_rooms;
}

// Checks if the input is a number and in the correct range
bool is_valid_input (const std::string& input, int num_options) {
    bool is_valid = true;
    for (auto c: input) {
        if (!isdigit(c)) {
            is_valid = false;
            break;
        }
    }

    if (!is_valid) return false;

    int integer_input;
    sscanf(input.c_str(), "%d", &integer_input);

    return 1 <= integer_input && integer_input <= num_options;
}

void Room::make_choice (Room ** current_room){
    int choice_index = 0;
    while (1) {
        std::cout << "Make your choice:" << std::endl;
        
        std::string input;
        std::cin >> input;

        if (is_valid_input(input, (*current_room)->options.size())) {
            sscanf(input.c_str(), "%d", &choice_index);
            choice_index--;
            break;
        } else {
            std::cout << "Invalid input: please type an integer between 1 and " << (*current_room)->options.size() << ".\n";
            continue;
        }
        
    }

    *current_room = adjacent_rooms[choice_index];
}