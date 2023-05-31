//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"


AbstractFile* SimpleFileFactory::createFile(string s) {

	string temp;

	int i = (int)s.find_last_of('.') + 1;
	temp = s.substr(i);
	if (temp == "txt") {
		TextFile* t = new TextFile(s);
		return t;
	}
	else if (temp == "img") {
		ImageFile* I = new ImageFile(s);
		return I;
	}
	else {
		return nullptr;
	}
}
