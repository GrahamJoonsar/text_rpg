#include "room.hpp"

int main(void) {
    Room room1 = {
        "You are in first room.",
        {
            "Go to second room.",
            "Go to third room.",
        }
    };
    Room room2 = {
        "You are in second room.",
        {
            "Go to first room.",
            "Go to third room.",
        }
    };
    Room room3 = {
        "You are in third room.",
        {
            "Go to first room.",
            "Go to second room.",
        }
    };

    room1.set_adjacents({&room2, &room3});
    room2.set_adjacents({&room1, &room3});
    room3.set_adjacents({&room1, &room2});

    Room * current_room = &room1;
    while (1) {
        if (current_room->display_room()) break;
        current_room->make_choice(&current_room);
    }
}