//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

template <typename GamePolicy>
class Game {
public:
    Game();
    ~Game();
    void start();
    void stop();
    void pause();
};


#endif //UNTITLED_GAME_H
