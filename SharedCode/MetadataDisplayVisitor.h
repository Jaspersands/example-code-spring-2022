//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractFileVisitor.h"


class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
};

enum wordsizes {
	smallname = 8, bigname = 16
};