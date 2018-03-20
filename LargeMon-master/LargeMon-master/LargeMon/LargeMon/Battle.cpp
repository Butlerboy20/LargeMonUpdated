#include "stdafx.h"
#include "PhysicalAttributeGenerator.h"
#include "Main.h"
#include "LargeMon.h"
#include "Battle.h"
#include "UserInterfaces.h"
#include <cstdlib>
#include <ctime>
#include <time.h>

PhysicalAttributeGenerator generator;
LargeMon myLargeMon, AIlargemon;
UserInterfaces battleInt;
Battle battle;

LargeMon generateAIlargemon(int randomTypeNumber) {

		vector <string> fTypes;
		fTypes.push_back("");
		fTypes.push_back("Fire");
		fTypes.push_back("Water");
		fTypes.push_back("Wood");

		AIlargemon.setName(generator.genAIName(randomTypeNumber));
		AIlargemon.setType(fTypes[randomTypeNumber]);
		AIlargemon.setWeakness(generator.genWeakness(randomTypeNumber));
		AIlargemon.setSize(generator.gen_random_size());
		AIlargemon.setHP(generator.gen_baseHP());
		AIlargemon.setAttack(generator.gen_BaseAttack());
		AIlargemon.setSpecAttack(generator.gen_SpecAttack());
		AIlargemon.setMissChance(generator.assign_MissChance());

		//prints out AI stats to screen
		AIlargemon.printLargeMonStats();
		cout << "\n\n\n";

		//AIlargemon = generateAIlargemon(randomTypeNumber);

		return AIlargemon;
}

void performBattle(LargeMon mylargeMon, LargeMon generatedLargeMon) {

	myLargeMon = mylargeMon;
	AIlargemon = generatedLargeMon;

}

//to go into main class
/**do {
		performBattle();

	switch (battleInt.battleOption);
	{
		case 1:
		LargeMonAttack();
		cout << AICurrentHP << endl;

		AILargeMonAttack();
		cout << LargeMonCurrentHP << endl;

		case 2:
			
	}
} 
while (LargeMon.getHP() >= 0 && AILargemon.getHP () >= 0);*/


int LargeMonAttack() {
	if (AIlargemon.getMissChance() < 50) {
		int AICurrentHP = AIlargemon.getHP() - myLargeMon.getAttack();
		AICurrentHP = AIlargemon.getHP();
		int AImissChance = AIlargemon.getMissChance() + 10;
		return AICurrentHP;
		return AImissChance;
	}
	else {
		int AImissChance = AIlargemon.getMissChance() - 10;
		int AICurrentHP = AIlargemon.getHP();
		return AICurrentHP;
		return AImissChance;
	}
}


int AIAttack() {
	if (myLargeMon.getMissChance() >= 50) {
		int LargeMonCurrentHP = myLargeMon.getHP() - AIlargemon.getAttack();
		int LargeMonmissChance = myLargeMon.getMissChance() + 10;
		return LargeMonCurrentHP;
		return LargeMonmissChance;
	}
	else {
		int LargeMonmissChance = myLargeMon.getMissChance() - 10;
		int LargeMonCurrentHP = myLargeMon.getHP();
		return LargeMonCurrentHP;
		return LargeMonmissChance;
		}
	}

int AIChooseMove() {
	srand(time(NULL));
	int randomAImove = (rand() % 3) + 1;
	return randomAImove;
}

int specAttack() {
	if (AIlargemon.getWeakness() == myLargeMon.getType())
	{
		int AIcurrentHP = AIlargemon.getHP() - myLargeMon.getSpecAttack();
		AIcurrentHP = AIlargemon.getHP();
		return AIcurrentHP;
	}
	else {
		int AIcurrentHP = AIlargemon.getHP() - myLargeMon.getAttack();
		AIcurrentHP = AIlargemon.getHP();
		return AIcurrentHP;
		cout << "Your Attack was not very effective" << endl;
	}
}

int AIspecAttack() {
	if (myLargeMon.getWeakness() == AIlargemon.getType()) {

		int myLargeMonHP = myLargeMon.getHP() - AIlargemon.getSpecAttack();
		myLargeMonHP = myLargeMon.getHP();
		return myLargeMonHP;
	}
	else {
		int myLargeMonHP = myLargeMon.getHP() - AIlargemon.getAttack();
		myLargeMonHP = myLargeMon.getHP();
		return myLargeMonHP;
	}
}

int heal() {
	int missChance = myLargeMon.getMissChance();
	
	int newHP = myLargeMon.getHP() * 1.6;
	int newMissChance = missChance - 60;

	newMissChance = missChance;
	return newHP;
	return newMissChance;
}

int AIheal() {
	int AImissChance = AIlargemon.getMissChance();

	int newAIHP = AIlargemon.getHP() * 1.6;
	int newAIMissChance = AImissChance - 60;

	newAIMissChance = AImissChance;
	return newAIHP;
	return newAIMissChance;
}


//TODO
//here implement a do ..while loop so that you can keep taking turns as you select the attack options

//within the loop 
//TODO
//implement the battle logic/maths based on the selection above andcompare the generated/selected LargeMon with the auto generated one above

//TODO 
//record the HP and attack selection to a file (apppend a new line)

//exit the loop when eith HP = 0

//TODO
//display the outcome/winner