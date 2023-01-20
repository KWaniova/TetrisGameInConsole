//
// Created by Krystyna Waniova on 10.01.2023.
//

#include "include/Tetris.h"
#include "include/Canvas.h"
#include "include/Figure.h"
#include "Figure_O.h"

Tetris::Tetris(){};



void Tetris::play() {

    // Providing a seed value
    srand((unsigned) time(NULL));

    // Get a random number
    int random = rand() % 3;

    Canvas canvas(10, 10);
    std::cout << "Tetris game started" << std::endl;
    std::cout << "Preparing figure..." << std::endl;
    for(int i = 0; i < 10; i++){
        Figure *figure = new Figure_O(canvas);
        bool fall_possible = true;
        figure->print_coordinates();
        figure->draw(canvas);
        fall_possible = figure->check_fall_possible();
        std::cout << "Fall possible: " << fall_possible << std::endl;
        DIRECTION direction = DOWN;
        while(fall_possible){
            int random = rand() % 3;

            if(random == 0){
                direction = DOWN;
            } else if(random == 1){
                direction = RIGHT_DOWN;
            } else {
                direction = LEFT_DOWN;
            }

            figure->fall(direction);
            figure->draw(canvas);

            fall_possible = figure->check_fall_possible();
            std::cout << "Fall possible: " << fall_possible << std::endl;
        }
        figure->draw_on_canvas();
        canvas.draw();
    }


    Figure *figure = new Figure_O(canvas);
    bool fall_possible = true;
    figure->print_coordinates();
    figure->draw(canvas);
    fall_possible = figure->check_fall_possible();
    std::cout << "Fall possible: " << fall_possible << std::endl;
    figure->fall(RIGHT_DOWN);
    figure->print_coordinates();
    figure->draw(canvas);
    figure->print_coordinates();
    fall_possible = figure->check_fall_possible();
    std::cout << "Fall possible: " << fall_possible << std::endl;
    figure->fall(RIGHT_DOWN);
    figure->draw(canvas);
    figure->print_coordinates();
    fall_possible = figure->check_fall_possible();
    std::cout << "Fall possible: " << fall_possible << std::endl;
    figure->fall(RIGHT_DOWN);
    figure->draw(canvas);
    figure->print_coordinates();
    fall_possible = figure->check_fall_possible();
    std::cout << "Fall possible: " << fall_possible << std::endl;
    figure->fall(RIGHT_DOWN);
    figure->draw(canvas);
    fall_possible = figure->check_fall_possible();
    std::cout << "Fall possible: " << fall_possible << std::endl;
    figure->fall(RIGHT_DOWN);
    figure->draw(canvas);
    fall_possible = figure->check_fall_possible();
    std::cout << "Fall possible: " << fall_possible << std::endl;
    figure->fall(RIGHT_DOWN);
    figure->draw(canvas);
    fall_possible = figure->check_fall_possible();
    std::cout << "Fall possible: " << fall_possible << std::endl;
    figure->fall(RIGHT_DOWN);
    figure->draw(canvas);
    fall_possible = figure->check_fall_possible();
    std::cout << "Fall possible: " << fall_possible << std::endl;
    figure->fall(RIGHT_DOWN);
    figure->draw(canvas);
    fall_possible = figure->check_fall_possible();
    std::cout << "Fall possible: " << fall_possible << std::endl;
    figure->fall(RIGHT_DOWN);
    figure->draw(canvas);

}





//    while (true) {
//
//        std::cout << "Drawing figure..." << std::endl;
//        figure->draw(canvas);
//        char x = ' ';
//        std::cout << "Pres key: L, R or Q to quit game." << std::endl;
//
//        while( x != 'L' && x != 'R' && x != 'Q'){
//            std::cin >> x;
//            std::cout << "You pressed: " << x << std::endl;
//            if( x != 'L' && x != 'R' && x != 'Q'){
//                std::cout << "Wrong key pressed. Try again" << std::endl;
//            }
//        }
//        if (x == 'L'){
//            std::cout << "Moving figure left" << std::endl;
//                figure->move_left(canvas);
//        }
//        else if (x == 'R'){
//            std::cout << "Moving figure right" << std::endl;
//                figure->move_right(canvas);
//        }
//        else if (x == 'Q'){
//            std::cout << "Quitting game" << std::endl;
//            break;
//        }
//        figure->print_coordinates();
//        figure->move_down(canvas);
//        figure->print_coordinates();
//
//        std::cout << std::endl;
//        std::cout << "Drawing canvas..." << std::endl;
//    }
//    // TODO: add figure to canvas on place where it fell
//    canvas.draw();

