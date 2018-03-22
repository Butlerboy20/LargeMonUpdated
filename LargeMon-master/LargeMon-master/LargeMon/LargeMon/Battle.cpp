#include "stdafx.h"
#include "PhysicalAttributeGenerator.h"
#include "Main.h"
#include "Battle.h"
#include "UserInterfaces.h"
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <time.h>

PhysicalAttributeGenerator generator;
LargeMon myLargeMon, AIlargemon;
UserInterfaces battleInt;
Battle battle;
int specLimit = 0;

LargeMon Battle::generateAIlargemon(int randomTypeNumber) {

	vector <string> fTypes;
	fTypes.push_back("");
	fTypes.push_back("Fire");
	fTypes.push_back("Water");
	fTypes.push_back("Wood");

	AIlargemon.setName(generator.genAIName(randomTypeNumber));
	AIlargemon.setType(fTypes[randomTypeNumber]);
	AIlargemon.setWeakness(generator.genWeakness(randomTypeNumber));
	AIlargemon.setSize(generator.gen_random_size());
	AIlargemon.setMaxHP(generator.gen_baseHP());
	AIlargemon.setHP(AIlargemon.getMaxHP());
	AIlargemon.setAttack(generator.gen_BaseAttack());
	AIlargemon.setSpecAttack(generator.gen_SpecAttack());
	AIlargemon.setMissChance(generator.assign_MissChance());

	//prints out AI stats to screen
	AIlargemon.printAILargeMonStats();
	cout << "\n\n\n";

	//AIlargemon = generateAIlargemon(randomTypeNumber);

	return AIlargemon;
}

void Battle::performBattle(LargeMon * generatedLargeMon, LargeMon * AIgeneratedLargeMon) {
	myLargeMon = *generatedLargeMon;
}

int Battle:: AIMove() {
	srand(time(NULL));
	int randomAImove = (rand() % 3) + 1;
	return randomAImove;
}

void Battle::AIChosenMove(int random) {
	int randomAImove = (rand() % 3) + 1;
	if (randomAImove == 1)
	{
		cout << "Opponent LargeMon Chooses to attack" << endl;
		AIAttack();
	}
	else if (randomAImove == 2)
	{
		cout << "Opponent LargeMon Chooses to use its Special attack" << endl;
		AIspecAttack();
	}
	else if (randomAImove == 3)
	{
		cout << "Opponent LargeMon Chooses to Heal" << endl;
		AIheal();
	}
}

void Battle:: LargeMonAttack() {
	if (AIlargemon.getMissChance() < 50) {
		cout << "Your Attack Hit\n" << endl;
		int AICurrentHP = AIlargemon.getHP() - myLargeMon.getAttack();
		AIlargemon.setHP(AICurrentHP);
		int AImissChance = AIlargemon.getMissChance() + 10;
		AIlargemon.setMissChance(AImissChance);
	}
	else {
		cout << "Your Attack missed\n" << endl;
		int AImissChance = AIlargemon.getMissChance() - 10;
		int AICurrentHP = AIlargemon.getHP();
		AIlargemon.setHP(AICurrentHP);
		AIlargemon.setMissChance(AImissChance);
	}
}


void Battle:: AIAttack() {
	if (myLargeMon.getMissChance() < 50) {
		cout << "The AI Attack Hit\n" << endl;
		int LargeMonCurrentHP = myLargeMon.getHP() - AIlargemon.getAttack();
		int LargeMonmissChance = myLargeMon.getMissChance() + 10;
		myLargeMon.setHP(LargeMonCurrentHP);
		myLargeMon.setMissChance(LargeMonmissChance);
	}
	else {
		cout << "The AIs Attack miss\n" << endl;
		int LargeMonmissChance = myLargeMon.getMissChance() - 10;
		int LargeMonCurrentHP = myLargeMon.getHP();
		myLargeMon.setHP(LargeMonCurrentHP);
		myLargeMon.setMissChance(LargeMonmissChance);
		}
	}


	

void Battle:: specAttack() {
	if (AIlargemon.getWeakness() == myLargeMon.getType())
	{
		if (specLimit < 2) {
			specLimit++;
			int AIcurrentHP = AIlargemon.getHP() - myLargeMon.getSpecAttack();
			AIlargemon.setHP(AIcurrentHP);
			cout << "Its Super Effective\n\n";
			//if special attack lands, increase opponents miss Chance
			int AImissChance = AIlargemon.getMissChance() + 30;
			AIlargemon.setMissChance(AImissChance);
		}
		else {
			cout << "Your Have used Special too many times\n\n";
			int AIcurrentHP = AIlargemon.getHP() - myLargeMon.getAttack();
			AIlargemon.setHP(AIcurrentHP);
			
		}
	}
	else if (AIlargemon.getWeakness() != myLargeMon.getType()) {
		int AIcurrentHP = AIlargemon.getHP() - myLargeMon.getAttack();
		AIlargemon.setHP(AIcurrentHP);
		cout << "Your Attack was not very effective\n\n";
	}
}

void Battle:: AIspecAttack() {
	if (myLargeMon.getWeakness() == AIlargemon.getType()) {

		int myLargeMonHP = myLargeMon.getHP() - AIlargemon.getSpecAttack();
		myLargeMon.setHP(myLargeMonHP);
		int LargeMonmissChance = myLargeMon.getMissChance() + 30;
		myLargeMon.setMissChance(LargeMonmissChance);
		cout << "Its Super Effective\n\n";
	}
	else {
		int myLargeMonHP = myLargeMon.getHP() - AIlargemon.getAttack();
		myLargeMon.setHP(myLargeMonHP);
		cout << "Its Attack was not very effective\n\n";
	}
}

void Battle:: heal() {
	int missChance = myLargeMon.getMissChance();
	
	int newHP = myLargeMon.getHP() * 1.6;
	int newMissChance = missChance - 60;

	myLargeMon.setHP(newHP);
	myLargeMon.setMissChance(newMissChance);
	
}

void Battle:: AIheal() {
	int AImissChance = AIlargemon.getMissChance();

	int newAIHP = AIlargemon.getHP() * 1.6;
	int newAIMissChance = AImissChance - 60;

	AIlargemon.setHP(newAIHP);
	AIlargemon.setMissChance(newAIMissChance);
	
}

LargeMon Battle::returnAI() {
	return AIlargemon;
}

LargeMon Battle::returnPlayer() {
	return myLargeMon;
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


