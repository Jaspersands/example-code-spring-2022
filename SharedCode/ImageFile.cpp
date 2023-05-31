//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "ImageFile.h"
#include "AbstractFileVisitor.h"
#include <iostream>
using namespace std;

ImageFile::ImageFile(string s) : name(s), size(0) {}

unsigned int ImageFile::getSize() {
	unsigned int contento = (unsigned int)contents.size();
	return contento;
}

string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> c) {
	if (chmodwrite == true) {
		size = c.back() - 48;
		int temp = size * size;
		if (temp != c.size() - 1) {
			return badWrite;
		}
		for (int i = 0; i < c.size() - 1; ++i) {
			if (c[i] == 'X' || c[i] == ' ') {

				contents.push_back(c[i]);
			}
			else {
				contents.clear();
				size = 0;
				return badWrite;
			}
		}
		return success;
	}
	return chmodFalse;
}

int ImageFile::append(vector<char> failure) {
	return noAppend;
}

vector<char> ImageFile::read() {
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* ab) {
	ab->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(string s) {
	ImageFile* newFile = new ImageFile(s + ".img");
	newFile->contents = this->contents;
	return newFile;
}
void ImageFile::chmodchange(string s) {
	if (s == "+") {
		chmodwrite = true;
	}
	else if (s == "-") {
		chmodwrite = false;
	}
}