#pragma once
#include "stdafx.h"
#include <string>

LargeMon generateAIlargemon(int randomTypeNumber);
//bool performBattle(LargeMon* generatedLargeMon, LargeMon* AIgeneratedLargeMon, int battleCount);
void performBattle(LargeMon generatedLargeMon, LargeMon AIgeneratedLargeMon);
class Battle {
public :
	
	int LargeMonAttack();
	int AIAttack();
	int AIChooseMove();
	int AIspecAttack();
	int heal();
	int AIheal();
	int specAttack();

	void returnBattleResult();
	void updateBattleCount();
	
	int getAIhp();
	int getAICurrentHP();
	int getLimiter();
	int setLimiter(int);
	int updateLimiter();

private :
	int battleCount;
	int battleResult;
	int specAttackLimiter;
};