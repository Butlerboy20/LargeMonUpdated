#include "stdafx.h"
#include "PhysicalAttributeGenerator.h"
#include "Main.h"
#include "LargeMon.h"
#include "Battle.h"
#include "UserInterfaces.h"
#include <cstdlib>
#include <ctime>

using namespace std;
// controller class for game, based on inputs within the user interfaces.

int main() {
	
	PhysicalAttributeGenerator generator;
	LargeMon largemon, AIlargemon;
	UserInterfaces interface;
	Battle battle;
	
	string type;

	vector <string> pTypes;
	pTypes.push_back("");
	pTypes.push_back("Fire");
	pTypes.push_back("Water");
	pTypes.push_back("Wood");

	//vector to store generated largeMon
	/**vector <LargeMon> generatedLargeMon;

	for (int i = 0; i < 10; i++) {
		
		LargeMon*g1 = new LargeMon;

		g1->setName(type);
		g1->setType(pTypes[interface.typeOption]);
		g1->setWeakness(generator.genWeakness(interface.typeOption));
		g1->setSize(generator.gen_random_size());
		g1->setHP(generator.gen_baseHP());
		g1->setAttack(generator.gen_BaseAttack());
		g1->setSpecAttack(generator.gen_SpecAttack());
		g1->setMissChance(generator.assign_MissChance());
		generatedLargeMon.push_back(*g1);
	}

	//loop for printing from vector
	vector<LargeMon>::iterator it;
	for ( it = generatedLargeMon.begin(); it != generatedLargeMon.end(); it++ ) {
	 //For each LargeMon, print out their info
	it->printLargeMonStats();
	}*/
	

	//used to pull the correct largemon from the vector.
	int selectedLargeMon;

	//random number to generate random type for AI largeMon
	srand(time(NULL));
	int randomTypeNumber = (rand() % 3) + 1; 

	int menuOption = 0;
	do
	{
		// use case statements to switch between possible screens
		menuOption = interface.displayInitialScreen();

		switch (menuOption)
		{
		case 1:
			interface.displayGenerator();
			switch (interface.typeOption) {

				//fire types are assigned to value 1 of typeOption
			case 1:
				type = generator.genType(1);

				break;

				//water types are assigned to value 2
			case 2:
				type = generator.genType(2);

				break;

				//wood type are assigned to value 3
			case 3:
				type = generator.genType(3);

				break;

			default:
				break;

			}
			// setting variables of chosen type to generate largemon.
			largemon.setName(type);
			largemon.setType(pTypes[interface.typeOption]);
			largemon.setWeakness(generator.genWeakness(interface.typeOption));
			largemon.setSize(generator.gen_random_size());
			largemon.setHP(generator.gen_baseHP());
			largemon.setAttack(generator.gen_BaseAttack());
			largemon.setSpecAttack(generator.gen_SpecAttack());
			largemon.setMissChance(generator.assign_MissChance());
			largemon.printLargeMonStats();
			cout << "Your LargeMon has been created \n";
			cout << "Would you like to save your new friend or abandon it? Yes/No?" << endl;
			cout << "Please Enter y to save or n to abandon" << endl;

			//user input checks to see if largeMon needs to be saved to the vector.
			char saveOrNot;
			cin >> saveOrNot;
			switch (saveOrNot) {
			case 'y':
				// save generated largeMon to a vector
				cout << "Your LargeMon has been successfully saved." << endl;

				break;
			case 'n':
				// delete largeMon
				cout << "Your LargeMon has been removed from the game." << endl;
				break;
			}

			cout << "Returning you to the main menu \n\n\n\n";

			break;

		case 2:
			//this starts by allowing the user to select a largeMon from these created by them
			selectedLargeMon = interface.displayChooseLargeMon();
			if (interface.LargeMonOption == 0) {
				interface.displayInitialScreen();
			}
			cout << "Your LargeMon as been selected, now time to battle\n\n";

			//Auto generates opponent largemon
			if (interface.LargeMonOption != 0) {

				//call the AI method from within battle.cpp
				 generateAIlargemon(randomTypeNumber);
			}
			//this then displays the battle options
			interface.displayBattle();

			break;

		case 3:
			// displays the information and Help Screen
			int returnOption = interface.displayInfo();
			while (returnOption != 1 || cin.fail()) //error check for incorrect keyboard input
			{
				cout << "Input 1 to return to main \n";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> returnOption;
			}
			break;

			//TO DO
			//case 4:
			// exit game;	
		}
	} while (menuOption != 5);
}

