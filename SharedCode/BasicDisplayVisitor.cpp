//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "BasicDisplayVisitor.h"
#include <vector>
#include <string>
#include <iostream>
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile* im) {
	for (int i = im->size -1; i >= 0; --i) {
		for (int j = 0; j < im->size; ++j) {
			auto k = i * im->size + j;
			cout << im->read()[k];
		}
		cout << endl;
	}
	cout << endl;
}

void BasicDisplayVisitor::visit_TextFile(TextFile* tx) {
	int size = tx->getSize();
	for (int i = 0; i < size; ++i) {
		cout << tx->read()[i];
	}
	cout << endl;
}


