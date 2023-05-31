//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "RenameParsingStrategy.h"
#include <iostream>
#include <sstream>

using namespace std;

vector<string> RenameParsingStrategy::parse(string s) {
	string temp;
	vector<string> inputs;
	inputs.push_back(s);
	istringstream iss(s);       
	iss >> temp;
	inputs.push_back(temp);
	return inputs;
}

