#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include "PhysicalAttributeGenerator.h"
#include "LargeMon.h"

void PhysicalAttributeGenerator::generate() {
}

string PhysicalAttributeGenerator::genType(int type) {
	// sets type based on user input from generation screen
	// then pulls a random name from the corresponding name vector
	if (type == 1) {
			int randomfire = rand() % fireNames.size();
			return fireNames[randomfire];
		}
		else if (type == 2) {
			int randomwater = rand() % waterNames.size();
			return waterNames[randomwater];
		}
		else if (type == 3) {
			int randomwood = rand() % woodNames.size();
			return woodNames[randomwood];
		}
	}

string PhysicalAttributeGenerator::genAIName(int randomTypeNumber) {
	// sets type based on random number generator
	// then pulls a random name from the corresponding name vector
	if (randomTypeNumber == 1) {
		int randomfire = rand() % fireNames.size();
		return fireNames[randomfire];
	}
	else if (randomTypeNumber == 2) {
		int randomwater = rand() % waterNames.size();
		return waterNames[randomwater];
	}
	else if (randomTypeNumber == 3) {
		int randomwood = rand() % woodNames.size();
		return woodNames[randomwood];
	}
}

string PhysicalAttributeGenerator::genWeakness(int type) {
	//sets weakness to be the opposing element type to the type of the
	//generated largeMon eg fire weakness  = water

	vector <string> Weakness;
		Weakness.push_back("");
		Weakness.push_back("Water");
		Weakness.push_back("Wood");
		Weakness.push_back("Fire");
	return Weakness[type];
}
float PhysicalAttributeGenerator ::gen_random_size() {
	// generates largeMon size within the specified range of 100-300
	srand(time(NULL));
		float Temp = (rand() % 200) + 100;
		float size = Temp / 100;
		return size;
	};
int PhysicalAttributeGenerator ::gen_randomHP() {
	//based on size, generates a random number within HP bound
	//this number will then be multiplied by a fixed multiplier for each size bound
	srand(time(NULL));
	float size = gen_random_size();	
	if (size <= 1.99) {
		int lowHPBound = rand() % (75 - 50) + 50;
		return lowHPBound;
	}
	else if (size > 1.99 & size <= 2.49) {
		int midHPBound = rand() % (86 - 75) + 75;
		return midHPBound;
	}
	else if (size > 2.49 & size <= 3.00) {
		int highHPBound = rand() % (101 - 86) + 86;
		return highHPBound;
	}
};
int PhysicalAttributeGenerator ::gen_baseHP() {
	//calculates the actual HP of a largeMon
	//pulls random HP bound calculated above and the multiplies by a fixed value
	int lowHPBound = gen_randomHP();
	int midHPBound = gen_randomHP();
	int highHPBound = gen_randomHP();

	if (lowHPBound) {
		float tempbaseHP = lowHPBound * 1.5;
		int baseHP = int(tempbaseHP);
		return baseHP;
	}
	else if (midHPBound) {
		float tempbaseHP = midHPBound * 1.25;
		int baseHP = int(tempbaseHP);
		return baseHP;
	}
	else if (highHPBound) {
		float tempbaseHP = highHPBound * 1.15;
		int baseHP = int(tempbaseHP);
		return baseHP;
	}
};
int PhysicalAttributeGenerator::gen_BaseAttack() {
	// base attack generated in the same way as the HP however
	// attack is based purely on size
	float size = gen_random_size();
	if (size <= 1.99) {
		float tempbaseAttack = size * 15;
		int baseAttack = int(tempbaseAttack);
		return baseAttack;
	}
	else if (size > 1.99 & size <= 2.49) {
		float tempbaseAttack = size * 20;
		int baseAttack = int(tempbaseAttack);
		return baseAttack;
	}
	else if (size > 2.49 & size <= 3) {
		float tempbaseAttack = size * 25;
		int baseAttack = int(tempbaseAttack);
		return baseAttack;
	}
};
int PhysicalAttributeGenerator::gen_SpecAttack() {
	//special attack value for an attack on a largeMon with the weaker type
	//simply the attack of the largeMon multiplied by 1.5 in this case
	float baseAttack = gen_BaseAttack();
	int specialAttack = baseAttack * 1.5;

	return specialAttack;
};
int PhysicalAttributeGenerator::assign_MissChance() {
	// generated number for how likely largeMon will be hit
	// this is based on largeMon size whereby if largeMon is small
	// miss chance = 100 ie garaunteed not to be hit.
	float size = gen_random_size();
	if (size > 2.49 & size <= 3) {
		int missChance = 10;
		return missChance;
	}
	else if (size > 1.99 & size <= 2.49) {
		int missChance = 50;
		return missChance;
	}
	else if (size <= 1.99) {
		int missChance = 100;
		return missChance;
	}
};

