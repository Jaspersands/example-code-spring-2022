//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractParsingStrategy.h"


class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	vector<string> parse(string);
};
