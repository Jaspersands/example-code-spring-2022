//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include <string>
#include <vector>
#include "AbstractFile.h"
using namespace std;


enum {
	success = 0, badWrite = 1, noAppend = 2, chmodFalse = 105
};

class ImageFile : public AbstractFile {
public:
	ImageFile(string);
	virtual unsigned int getSize();
	virtual string getName();
	virtual int write(vector<char>);
	virtual int append(vector<char>);
	virtual vector<char> read();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(string);
	virtual void chmodchange(string);
	char size;
private: 
	vector<char> contents;
	string name;
	bool chmodwrite = true;
};

