#include <iostream>
#include "include/Tetris.h"

using namespace std;

int main()
{
    Canvas canvas(10, 10, ' ');
    Tetris tetris(canvas);
    tetris.play();

    return 0;
}
