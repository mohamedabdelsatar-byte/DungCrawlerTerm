#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

enum ItemIndex{
    KEY=0,
    SNAKE_TOOL=4,
};

struct Player{
    std::string name;
    char gender;
    bool hasKey = false;
    int Health = 5;
    bool inv[7] = {false, false, false, false, false, false, false};
};

struct GameState{
    bool visited[5] = {false, false, false, false, false};
    bool completed[4] = {false, false, false, false};
    bool Escaped = false;
    bool keepPlaying = true;
};

#endif