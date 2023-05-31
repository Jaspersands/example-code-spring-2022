//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "TextFile.h"
#include "AbstractFileVisitor.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

TextFile::TextFile(string s) : name(s) {}

unsigned int TextFile::getSize() {
	unsigned int content = (unsigned int)contents.size();
	return content;
}

string TextFile::getName() {
	return name;
}

int TextFile::write(vector<char> w) {
	if (chmodwrite == true) {
		contents = w;

		if (contents == w) {

			return suuccess;
		}
		else {
			return writtenFail;
		}
	}
	return chmodUntrue;
}

int TextFile::append(vector<char> a) {
	if (chmodwrite == true) {
		for (int i = 0; i < a.size(); ++i) {
			contents.push_back(a[i]);
		}

		return suuccess;
	}
	return chmodUntrue;
}

vector<char> TextFile::read() {
	return contents;
}

void TextFile::accept(AbstractFileVisitor* ab) {
	ab->visit_TextFile(this);
}

AbstractFile* TextFile::clone(string s) {
	TextFile* newFile = new TextFile(s + ".txt");
	newFile->contents = this->contents;
	return newFile;
}

void TextFile::chmodchange(string s) {
	if (s == "+") {
		chmodwrite = true;
	}
	else if (s == "-") {
		chmodwrite = false;
	}
}