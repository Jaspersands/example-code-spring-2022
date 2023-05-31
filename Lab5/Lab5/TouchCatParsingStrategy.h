//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once

#include "../../SharedCode/AbstractParsingStrategy.h"
#include "../../SharedCode/AbstractCommand.h"
#include "../../SharedCode/AbstractFileSystem.h"
#include <string>
#include <vector>

using namespace std;

class TouchCatParsingStrategy : public AbstractParsingStrategy{
public:
	vector<string> parse(string);
};

enum TouchCat {
	successffull = 0, TouchCatFail = 78
};
