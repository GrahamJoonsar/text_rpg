# text_rpg
A game engine for creating text-based rpgs.

This repo is basically done, it will read an adventure from the user and play out the whole thing, until the user either quits or the adventure ends.

## Format of adventure files

An adventure file is basically just a sequence of rooms, with room names, descriptions, options, and rooms that go along with those options. The first room in a file will be the room that the player starts off in the adventure, and the order of the rest of the rooms dont matter. To make a room an endpoint, just leave the options and adjacent fields blank.

### Actual format of room

```
$(Room Name) {
    description: (Description of room enclosed in double quotes)
    options: (List of options enclosed in double quotes)
    adjacent: (List of room names corresponding to options)
}
```

### Example

```
$room_1 {
    description: "Room 1"
    options: "Go to room 2" "Go to room 3"
    adjacent: room_2 room_3
}

$room_2 {
    description: "Room 2" 
    options: "Go to room 1" "Go to room 3"
    adjacent: room_1 room_3
}

$room_3 {
    description: "Room 3" 
    options: "Go to room 1" "Go to room 2"
    adjacent: room_1 room_2
}
```