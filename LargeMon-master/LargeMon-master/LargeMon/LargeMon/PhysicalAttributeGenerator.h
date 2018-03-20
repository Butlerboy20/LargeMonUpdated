#pragma once
#include <iostream>
#include "stdafx.h"
#include <vector>
using namespace std;

class PhysicalAttributeGenerator {
public:
	void generate();
	string genType(int);
	string genAIName(int);
	string genWeakness(int);
	float gen_random_size();
	int gen_randomHP();
	int gen_baseHP();
	int gen_BaseAttack();
	int gen_SpecAttack();
	int assign_MissChance();

private:
	vector<string> fireNames = { "FlameMon", "FlareMon", "CombustaMon", "TarnMon", "CharMon", "FyreMon" , "PhlogisMon", "PyroMon"};
	vector<string> waterNames = { "SplashMon", "SquirtMon", "DuckMon", "WetMon", "DampMon", "MoistMon" };
	vector<string> woodNames = { "BarkMon", "TrunkMon", "BranchMon", "EdwardWoodWoodMon", "WoodMon", "LumberMon" };
};