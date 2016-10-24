//============================================================================
// Name        : DieRoller.cpp
// Author      : Chris Scherer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "Die.h"
using namespace std;

int main() {
	//Create a new die object
	Die* d6 = new Die(6);
	//Roll our stats
	cout << "Str: " << d6->RollStat() << endl;
	cout << "Dex: " << d6->RollStat() << endl;
	cout << "Con: " << d6->RollStat() << endl;
	cout << "Int: " << d6->RollStat() << endl;
	cout << "Wis: " << d6->RollStat() << endl;
	cout << "Cha: " << d6->RollStat() << endl;

	return 0;
}
