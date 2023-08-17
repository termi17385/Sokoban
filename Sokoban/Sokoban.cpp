#include <iostream>
#include <iomanip>
#include "board.h"
#include "player.h"
#include "vector2.h"

using namespace std;

int LEVEL_ONE[ROWS][COLS] =
{
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1, 0, 0, 0, 0, 2, 0, 0, 0,-1},
    {-1, 0, 0, 0, 0, 0, 0, 3, 0,-1},
    {-1, 0, 0, 1, 0, 2, 0, 0, 0,-1},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1, 0, 0, 1, 0, 0, 0, 0, 0,-1},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};

int main()
{
    board b;
    player p;
    
    b.loadLevel(LEVEL_ONE);
    while (true)
    {
        p.move(b.displayBoard(), b);
        //b.displayBoard();
    }
    return 0;
}