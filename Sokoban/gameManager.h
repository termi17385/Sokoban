#pragma once
class gameManager
{
private:
	static int goalCount;
	static int boxesOnGoals;

	

public:
	static void setGoalAmount(int, bool);
	static bool gameRules();
	static void restartGame();
	static void gameStarted();
	static bool restart;
};

