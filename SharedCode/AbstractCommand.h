//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include <string>

using namespace std;


class AbstractCommand {
public:
	virtual int execute(string) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
};
