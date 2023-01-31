#include "room.hpp"
#include "room_io.hpp"

int main(void) {
    Room * current_room = read_adventure("examples/adventure_1.txt");
    while (1) {
        if (current_room->display_room()) break;
        current_room->make_choice(&current_room);
    }
}