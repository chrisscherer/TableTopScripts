/*
 * Die.h
 *
 *  Created on: Oct 24, 2016
 *      Author: christopherscherer
 */

#ifndef DIE_H_
#define DIE_H_
#include <vector>
using namespace std;

class Die {
public:
	int DieSize;
	//Constructor that takes the die size e.g. d4, d6, d8 etc.
	Die(int size);
	virtual ~Die();

	vector<int> Roll();
	vector<int> Roll(int numTimes);

	int RollStat();

	vector<int> DropLowest(vector<int> vec);
};

#endif /* DIE_H_ */
