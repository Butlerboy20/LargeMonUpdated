#pragma once
#include <iostream>
#include <string>


using namespace std;
using std::string;

class LargeMon {
	public:
		string setName(string largeName);
		string setType(string typeNo);
		string getType();
		string setWeakness(string largeWeak);
		string getWeakness();
		void setSize(float size);
		void setHP(int baseHP);
		int getHP();
		void setAttack(int baseAttack);
		int getAttack();
		void setSpecAttack(int specAttack);
		int getSpecAttack();
		void setMissChance(int missChance);
		int getMissChance();
		void generate();
		void printLargeMonStats();
	
	private:
		string name;
		string type;
		string weakness;
		float size;
		int baseHP;
		int baseAttack;
		int specAttack;
		int missChance;
		
};
