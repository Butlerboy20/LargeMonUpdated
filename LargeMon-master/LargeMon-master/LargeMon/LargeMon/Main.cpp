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
	LargeMon generatedLargeMon, AIgeneratedLargeMon;
	UserInterfaces interface;
	Battle battle;
	
	string type;

	vector <string> pTypes;
	pTypes.push_back("");
	pTypes.push_back("Fire");
	pTypes.push_back("Water");
	pTypes.push_back("Wood");

	//vector to store generated largeMon original idea to store all in a list and choose
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
	

	//random number to generate random type for AI largeMon
	srand(time(NULL));
	int randomTypeNumber = (rand() % 3) + 1; 

	int battleCount = 1;

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
			generatedLargeMon.setName(type);
			generatedLargeMon.setType(pTypes[interface.typeOption]);
			generatedLargeMon.setWeakness(generator.genWeakness(interface.typeOption));
			generatedLargeMon.setSize(generator.gen_random_size());
			generatedLargeMon.setMaxHP(generator.gen_baseHP());
			generatedLargeMon.setHP(generatedLargeMon.getMaxHP());
			generatedLargeMon.setAttack(generator.gen_BaseAttack());
			generatedLargeMon.setSpecAttack(generator.gen_SpecAttack());
			generatedLargeMon.setMissChance(generator.assign_MissChance());
			generatedLargeMon.printLargeMonStats();
	
			cout << "Your LargeMon has been created \n";
			cout << "Would you like to battle with your new friend or abandon it? Yes/No?" << endl;
			cout << "Please Enter y to battle or n to abandon" << endl;

			//user input checks to see if largeMon needs to be saved to the vector.
			char saveOrNot;
			cin >> saveOrNot;
			switch (saveOrNot) {
			case 'y':
				// pushes generated largemon to battle screen and loads.
				cout << "\n\n";
				cout << "Its Now Time to battle!!!\n\n\n" << endl;
				
				//generate AI automatically
				battle.generateAIlargemon(randomTypeNumber);
				
				//print User LargeMon Stats
				generatedLargeMon.printLargeMonStats();
				cout << "\n\n\n";

				// Display Battle Screen
				
				interface.displayBattle();

				//Call battle to initiate both objects
				battle.performBattle(&generatedLargeMon, &AIgeneratedLargeMon);
			
				//While Loop for Battle Functionality
				while (AIgeneratedLargeMon.getHP() && generatedLargeMon.getHP() > 0)
				{
						//Switch Case of User Attacks.
						switch (interface.battleOption)	
						{
						case 1:
							//Users Normal Attack
							cout << "Player chooses to use a normal attack\n\n";
							battle.LargeMonAttack();
							battle.returnAI().printAILargeMonStats();
							cout << "Its Your Opponents Turn to Attack \n\n" << endl;

							//Then AI Attacks choosing a random move
							battle.AIChosenMove(0);
							battle.returnPlayer().printLargeMonStats();
							//print out updated stats.
							interface.displayBattle();
							cout << "\n";
							break;

						case 2:
							//Users Special Attack
							cout << "Player chooses to use it special attack\n\n";
							//add a do while loop with special attack limiter if i get time.
							battle.specAttack();
							
							//print out updated ai stats.
							battle.returnAI().printAILargeMonStats();
							cout << "Its Your Opponents Turn to Attack \n\n" << endl;
							
							//Then AI Attacks choosing a random move
							battle.AIChosenMove(0);
							cout << "\n";
							//print out updated player stats.
							battle.returnPlayer().printLargeMonStats();
							cout << "\n";
							interface.displayBattle();

						case 3:
							//Users Heal move.
							cout << "Player chooses to use its healing ability\n\n";
							battle.heal();
							
							//print out updated AI stats.
							battle.returnAI().printAILargeMonStats();
							cout << "Its Your Opponents Turn to Attack \n\n" << endl;

							//Then AI Attacks choosing a random move
							battle.AIChosenMove(0);
							cout << "\n";
							//print out updated player stats.
							battle.returnPlayer().printLargeMonStats();
							
							cout << "\n";
							interface.displayBattle();
							break;
						
						case 4:
							//return to main menu.
							break;

						}

						if (battle.returnAI().getHP() <= 0) {

							cout << "You Win. Well done trainer. Continue your Journey forward \n\n";
							break;
							interface.displayInitialScreen();
						}

						else if (battle.returnPlayer().getHP() <= 0) {

							cout << "You lose. Hope you enjoyed, please try again.\n\n" << endl;
							break;
							interface.displayInitialScreen();

						}
				}
				break;

			case 'n':
				// does not store largeMon
				cout << "Your LargeMon has been removed from the game." << endl;
				break;
			}

			cout << "Returning you to the main menu \n\n\n\n";

			break;

		case 2:

			//This case would deal with battle screen however battle is now access after generation.
			cout << "You have not yet Generated your own LargeMon" << endl;
			cout << "Returning you to main menu" << endl;
			cout << "Please go to Generation Screen and Access Battle via there\n\n" << endl;

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

