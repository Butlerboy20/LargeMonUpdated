#pragma once
#include "stdafx.h"
#include "LargeMon.h"
#include <string>


//bool performBattle(LargeMon* generatedLargeMon, LargeMon* AIgeneratedLargeMon, int battleCount);

class Battle {
public :

	LargeMon generateAIlargemon(int randomTypeNumber);
	void performBattle(LargeMon * generatedLargeMon, LargeMon * AIgeneratedLargeMon);

	int AIMove();
	void LargeMonAttack();
	void AIAttack();
	void AIChosenMove(int randomAImove);
	void AIspecAttack();
	void heal();
	void AIheal();
	void specAttack();
	LargeMon returnAI();
	LargeMon returnPlayer();


private :
	int battleCount;
	int battleResult;
	int specAttackLimiter;
};