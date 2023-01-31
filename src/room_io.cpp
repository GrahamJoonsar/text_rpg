#include "room_io.hpp"

#include <algorithm>
#include <fstream>
#include <vector>
#include <map>

std::vector<std::string> tokenize(std::string str) {
    std::vector<std::string> tokens;
    std::string temp = "";

    bool quotes = false;

    for (auto c: str){
        if (isspace(c) && temp != "" && !quotes){
            tokens.push_back(temp);
            temp = "";
        } else if (c == '"') {
            quotes = !quotes;
        } else if (!isspace(c) || quotes){
            temp += c;
        }
    }
    if (temp != "") tokens.push_back(temp);

    return tokens;

}

Room * read_adventure(std::string path){
    std::string line;
    std::ifstream file(path);

    std::map<std::string, int> room_indexes;
    int current_index = 0;

    std::vector<Room*> rooms;
    std::vector<std::vector<std::string>> adjacents;

    // Looping through each line in the file
    while (getline(file, line)){
        std::vector<std::string> tokens = tokenize(line);

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i][0] == '$') { // Declaring new room
                room_indexes[tokens[i].substr(1)] = current_index;
                rooms.push_back(new Room());
                break;
            } else if (tokens[i] == "description:") {
                rooms[current_index]->set_description(tokens[i+1]);
                break;
            } else if (tokens[i] == "options:") {
                std::vector<std::string> options;
                for (int j = i+1; j < tokens.size(); j++) {
                    options.push_back(tokens[j]);
                }
                rooms[current_index]->set_options(options);
                break;
            } else if (tokens[i] == "adjacent:") {
                std::vector<std::string> adjacent_rooms;
                for (int j = i+1; j < tokens.size(); j++){
                    adjacent_rooms.push_back(tokens[j]);
                }
                adjacents.push_back(adjacent_rooms);
                current_index++;
                break;
            }
        }
    }

    for (int i = 0; i < rooms.size(); i++) {
        std::vector<Room*> spec_adjacents;
        for (auto adj: adjacents[i]){
            spec_adjacents.push_back(rooms[room_indexes.at(adj)]);
        }
        rooms[i]->set_adjacents(spec_adjacents);
    }

    file.close();

    return rooms[0];
}