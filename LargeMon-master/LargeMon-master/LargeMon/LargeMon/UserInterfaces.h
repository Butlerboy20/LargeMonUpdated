#pragma once
#include "stdafx.h"

class UserInterfaces
{
public :
		int displayInitialScreen();
	
	//Generator Screen to be displayed
		int displayGenerator();

		int LargeMonOption;

	//Battle Screen displays
		int displayBattle();
		int battleOption;
	
	// Display Information Screen
		int displayInfo();
		int typeOption;

		//void printLargeMonStats(std::string type);
	
	//

private :
	int menuOption;
	int returnOption;
};