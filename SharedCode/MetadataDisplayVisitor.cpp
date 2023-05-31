//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "MetadataDisplayVisitor.h"
#include "TextFile.h"
#include "iostream"
#include "ImageFile.h"
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* t) {
	if (t->getName().size() < smallname) {
		cout << t->getName() << "\t\t\t";
	}
	else if (t->getName().size() >= smallname && t->getName().size() < bigname) {
		cout << t->getName() << "\t\t";
	}
	else {
		cout << t->getName() << "\t";
	}
	cout << "text" << "\t";
	cout << t->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* i) {
	if (i->getName().size() < smallname) {
		cout << i->getName() << "\t\t\t";
	}
	else if (i->getName().size() >= smallname && i->getName().size() < bigname) {
		cout << i->getName() << "\t\t";
	}
	else {
		cout << i->getName() << "\t";
	}
	cout << "image" << "\t";
	cout << i->getSize() << endl;
}
