#include "gameManager.h"

int gameManager::goalCount = 0;
int gameManager::boxesOnGoals = 0;
bool gameManager::restart = false;

void gameManager::setGoalAmount(int _goals, bool _boxesOnGoals)
{
	if (!_boxesOnGoals) goalCount = _goals;
	else boxesOnGoals = _goals;
}

bool gameManager::gameRules()
{
	return boxesOnGoals >= goalCount;
}

void gameManager::gameStarted()
{
	restart = false;
}

void gameManager::restartGame()
{
	restart = true;
}
