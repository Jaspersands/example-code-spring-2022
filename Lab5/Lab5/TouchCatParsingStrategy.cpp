//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "TouchCatParsingStrategy.h"
#include <iostream>
#include <sstream>

using namespace std;

vector<string> TouchCatParsingStrategy::parse(string s) {
	string temp;
	string p;
	string touch;
	string cat;
	vector<string> inputs;
	istringstream iss(s);
	iss >> temp;

	touch = temp;
	cat = temp;

	if (iss >> p && p == "-p") { //don't need to check for cat option because it is empty
		touch += " -p";
	}
	inputs.push_back(touch);
	inputs.push_back(cat);
	return inputs;
}