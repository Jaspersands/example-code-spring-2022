//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include <vector>
#include <string>

using namespace std;

class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string) = 0;
};

