//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include <string>
#include <vector>
#include "AbstractFile.h"
using namespace std;


class PasswordProxy : public AbstractFile {
protected:
	string passwordPrompt();
	bool checkPassword(string);
	bool chmodwrite = true;
public:
	PasswordProxy(AbstractFile*, string);
	~PasswordProxy();
	virtual unsigned int getSize();
	virtual string getName();
	virtual int write(vector<char>);
	virtual int append(vector<char>);
	virtual vector<char> read();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(string);
	virtual void chmodchange(string);
private:
	AbstractFile* file;
	string password;

};

enum proxyOutcomes {
	noWrite = 7, badAppend = 8
};