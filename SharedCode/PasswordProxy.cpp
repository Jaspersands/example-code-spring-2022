//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "PasswordProxy.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* a, string s) : password(s), file(a) {}

unsigned int PasswordProxy::getSize() {

	return file->getSize();
}

string PasswordProxy::getName() {
	return file->getName();
}

int PasswordProxy::write(vector<char> c) {
	if (checkPassword(passwordPrompt())) {
		return file->write(c);
	}
	return noWrite;
}

int PasswordProxy::append(vector<char> a) {
	if (checkPassword(passwordPrompt())) {
		return file->append(a);
	}
	return badAppend;
}



vector<char> PasswordProxy::read() {
	if (checkPassword(passwordPrompt())) {
		return file->read();
	}
	vector<char> t = {};
	return t;
}

void PasswordProxy::accept(AbstractFileVisitor* ab) {
	if (checkPassword(passwordPrompt())) {
		file->accept(ab);
	}
}

string PasswordProxy::passwordPrompt() {
	cout << "Enter password: " << endl;
	string temp;
	getline(cin, temp);
	return temp;
}

bool PasswordProxy::checkPassword(string userInput) {
	if (password == userInput) {
		return true;
	}
	return false;
}

AbstractFile* PasswordProxy::clone(string s) {
	AbstractFile* newProtected = file->clone(s);
	PasswordProxy* newFile = new PasswordProxy(newProtected, password);
	return newFile;
}

void PasswordProxy::chmodchange(string s) {
	if (s == "+") {
		chmodwrite = true;
	}
	else if (s == "-") {
		chmodwrite = false;
	}
}