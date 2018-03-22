#include "stdafx.h"
#include "LargeMon.h"
#include <time.h>


string LargeMon::setType(string typeGiven){
	return type = typeGiven;
}

string LargeMon::getType() {
	return type;
}

string LargeMon::setWeakness(string largeWeak){
	return weakness = largeWeak;
}

string LargeMon::getWeakness() {
	return weakness;
}

string LargeMon::setName(string largeMonName){
	return name = largeMonName;
}

void LargeMon::setSize(float gensize) {
	size = gensize;
}
void LargeMon::setHP(int genHP) {
	baseHP = genHP;
	if (baseHP > maxHP) {
		baseHP = maxHP;
	}
	if (baseHP < 0) {
		baseHP = 0;
	}
}

void LargeMon::setMaxHP(int genMaxHP) {
	maxHP = genMaxHP;
}

int LargeMon::getHP() {
	return baseHP;
}

int LargeMon::getMaxHP() {
	return maxHP;
}

void LargeMon::setAttack(int genAttack) {
	baseAttack = genAttack;
}

int LargeMon::getAttack() {
	return baseAttack;
}

void LargeMon::setSpecAttack(int specialAttack) {
	specAttack = specialAttack;
}

int LargeMon::getSpecAttack() {
	return specAttack;
}

void LargeMon::setMissChance(int mChance) {
	//sets miss Chance and its max and min values
	missChance = mChance;
	if (missChance < 0) {
		missChance = 0;
	}
	if (missChance > 100) {
		missChance = 100;
	}
}

int LargeMon::getMissChance() {
	return missChance;
}

void LargeMon::generate()
{
}

void LargeMon::printLargeMonStats() {
	cout << "Your LargeMon is called :" << name << endl;
	cout << "Type : " << type << endl;
	cout << "Weakness : " << weakness << endl;
	cout << "Size :  " << size << endl;
	cout << "Health :  " << baseHP << endl;
	cout << "AttackPoints :  " << baseAttack << endl;
	cout << "SpecialAttack :  " << specAttack << endl;
	cout << "MissChance :  " << missChance << endl;
	cout << "\n";
}

void LargeMon::printAILargeMonStats() {
	cout << "Your Opposing LargeMon is :" << name << endl;
	cout << "Type : " << type << endl;
	cout << "Weakness : " << weakness << endl;
	cout << "Size :  " << size << endl;
	cout << "Health :  " << baseHP << endl;
	cout << "AttackPoints :  " << baseAttack << endl;
	cout << "SpecialAttack :  " << specAttack << endl;
	cout << "MissChance :  " << missChance << endl;
	cout << "\n";
}

