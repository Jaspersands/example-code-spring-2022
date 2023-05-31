//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include <string>
#include <vector>
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;

//class ImageFile;
//class TextFile;

class AbstractFileVisitor {
public:
	virtual void visit_ImageFile(ImageFile*) = 0;
	virtual void visit_TextFile(TextFile*) = 0;
};