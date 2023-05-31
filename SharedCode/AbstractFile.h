//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include <vector>
#include <string>
using namespace std;

class AbstractFileVisitor;

class AbstractFile {
public:
	virtual vector<char> read() = 0;
	virtual int write(vector<char> w) = 0;
	virtual int append(vector<char> a) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual AbstractFile* clone(string) = 0;
	virtual void chmodchange(string) = 0;
};