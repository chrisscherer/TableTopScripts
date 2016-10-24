/*
 * Die.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: chris scherer
 */

#include "Die.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//Constructor taking an initial die size, e.g. d6, d8, d12 etc.
Die::Die(int size) {
	DieSize = size;

	//Seed a value based on the current system time so it's never the same twice
	//It's super important you do this once,
	//otherwise you will generate the same value over and over if included in the loop that generates your random value
	srand(time(NULL));
}

//Deconstructor that would be relevant if we were writing a proper program and/or cared about memory management
Die::~Die() {
	// TODO Auto-generated destructor stub
}

///In case someone wants to just roll once or use roll in some other way we have this base overload
vector<int> Die::Roll(){
	return Roll(1);
}

///This overload let's a user or developer easily make multiple rolls with one function call.
vector<int> Die::Roll(int numTimes){
	//Initialize our list of ints
	vector<int> results;

	//For every time we want to roll the die
	for(int i=0;i<numTimes;i++){
		//"Roll", Generate and add our result to the list
		results.push_back(rand() % DieSize + 1);
	}
	//We're done, return the list
	return results;
}

//This function will return a 4d6 with the lowest roll dropped
//in other words, a single stat roll
int Die::RollStat(){
	//Initialize our starting values
	vector<int> results;
	int sum = 0;

	//Roll 4 times and save the results
	results = Roll(4);
	//Drop the lowest value from our results
	results = DropLowest(results);

	//shorthand that loops over every int in our vector 'results'
	for (int n : results)
	    sum += n;

	//return our total value
	return sum;
}

//Function that drops the lowest value off a vector of integers
vector<int> Die::DropLowest(vector<int> vec){
	//Sort from highest to lowest so we can just knock off the last element that will be the lowest vaule
	sort(vec.rbegin(), vec.rend());
	//pop_back removes the element at the end of the vector
	vec.pop_back();
	return vec;
}
