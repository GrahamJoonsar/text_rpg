#pragma once

#include <iostream>
#include <vector>

/*

The Room class:

This class represents a room in an rpg. It does not neccesarily have to be a room, but
more like a situation, with a description of the room, options for what to do next, and 
adjacent rooms that will be travelled to based on those options.

*/

class Room {
    private:
        std::string description;
        std::vector<std::string> options;
        std::vector<Room*> adjacent_rooms;
    
    public:
        Room (std::string description, std::vector<std::string> options);
        Room ();
        bool display_room ();
        void make_choice (Room ** current_room);

        void set_description (std::string description);
        void set_options (std::vector<std::string> options);
        void set_adjacents (std::vector<Room*> adjacent_rooms);

        std::string get_description();
        std::vector<std::string> get_options();
        std::vector<Room*> get_adjacents();
};