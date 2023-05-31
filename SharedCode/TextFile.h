//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractFile.h"
#include <vector>
#include <string>
using namespace std;

class TextFile : public AbstractFile {

private:
	vector<char> contents;
	string name;
	bool chmodwrite = true;
public: 
	TextFile(string);
	virtual unsigned int getSize();
	virtual string getName();
	virtual vector<char> read();
	virtual int write(vector<char>);
	virtual int append(vector<char>);
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(string);
	virtual void chmodchange(string);
};

enum {
	suuccess = 0, writtenFail = 1, chmodUntrue = 104
};