#include <iostream>
#include <iomanip>
#include "board.h"
#include "player.h"
#include "vector2.h"
#include "gameManager.h"

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

// -1 = wall, 1 = goal, 2 = box, 3 = player, 0 = empty

int LEVEL_TWO[ROWS][COLS] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0,-1,-1,-1,-1,-1,-1, 0, 0, 0},
    {0,-1, 3, 0, 0, 0,-1, 0, 0, 0},
    {0,-1, 0,-1,-1, 0,-1, 0, 0, 0},
    {0,-1, 0,-1,-1, 2,-1,-1, 0, 0},
    {0,-1, 0, 2, 0, 0, 1,-1, 0, 0},
    {0,-1,-1,-1,-1, 0,-1,-1, 0, 0},
    {0, 0, 0, 0,-1, 0,-1, 0, 0, 0},
    {0, 0, 0, 0,-1, 1,-1, 0, 0, 0},
    {0, 0, 0, 0,-1,-1,-1, 0, 0, 0}
};

int chosenLevel[ROWS][COLS];

const int LEVEL_AMOUNT = 2;
int level = 1;

void levelToLoad(int _newLevel[ROWS][COLS])
{
    for (int x = 0; x < ROWS; x++)
        for (int y = 0; y < COLS; y++)
            chosenLevel[x][y] = _newLevel[x][y];
}

bool moveToNextLevel()
{
    if (level >= LEVEL_AMOUNT) return false;
    level++;

    cout << "\n\nLevel " << level << "!\n\n";

    levelToLoad(LEVEL_TWO);
    return true;
}


void gamePlay()
{
    vector2::Vector2 cPos;
    board b;
    player p;
    bool gamePlaying;
    bool newLevel;
    char ans;

    b.loadLevel(chosenLevel);
    gamePlaying = true;

    while (gamePlaying)
    {
        cPos = b.displayBoard(false);
        if (!gameManager::gameRules()) p.move(cPos, b);
        else if(gameManager::gameRules())
        {
            cout << "\nLevel Completed\n";
            newLevel = moveToNextLevel();

            if (!newLevel)
            {
                cout << "\n\nThank you for playing!\n"
                     << "Would you like to restart? (Y/N): ";
                
                cin >> ans;

                if (ans == 'y' || ans == 'Y')
                {
                    gameManager::restartGame();
                    gamePlaying = false;
                }
                else if (ans == 'n' || ans == 'N') gamePlaying = false;
            }
            else
            {
                cout << "\n\nLoading the next level!\n";

                system("pause");

                // handle new level logic
                gamePlay();
                gamePlaying = false;
            }
        }

        if (gameManager::restart) gamePlaying = false;
        b.displayBoard(true);
    }

    if (gameManager::restart)
    {
        level = 1;
        gameManager::gameStarted();
        levelToLoad(LEVEL_ONE);
        gamePlay();
    }
}

int main()
{
    levelToLoad(LEVEL_ONE);

    char ans{};
    cout << setw(2) << "SOKOBAN\n\n";

    cout << "Game Rules: \n"
        << "wasd or WASD to move\n"
        << "r or R to restart \n\n";

    cout << "Would you like to play? (Y/N): ";
    cin >> ans;

    cout << "\n";

    switch (ans)
    {
    case 'N':
    case 'n':
        break;

    case 'Y':
    case 'y':
        gamePlay();
        break;
    }
    return 0;
}