studio 18 answers here
Question 1: Jasper and Ethan
Question 2: Making a new file system implementation that creates different files than the SimplefileSystem would be pretty easy. However,
if we were to create a new concrete file type that is used by many different file system implementations, that would require
a lot more work because we would have to modify all the file system implementations. Without file factory, we have to modify the 
file systems as opposed to just having to modify the factory. 
Question 3: You would want to create a new concrete file factory class whenever distinct types of files must be created. If a new file 
type should be created by existing factories, only the factories need to be modified, not the systems. Given two file system
implementations that manage the same types of files, the same factory can be used for both. Given two file system implementations 
that manage different types of files, the same concrete factory implementation probably would not be used to create both. Perhaps 
the same abstract factory, but not concrete (though we believe with modifications it would be possible, though it would kind of defeat
the purpose of the abstract factory pattern).
Question 4: 

TEST CODE:
	AbstractFileSystem* test = new SimpleFileSystem();
	AbstractFileFactory* fac = new SimpleFileFactory();
	AbstractFile* a = fac->createFile("filename");
	AbstractFile* t = fac->createFile("text.txt");
	AbstractFile* i = fac->createFile("image.img");
	cout << t->getSize() << endl;
	cout << t->getName() << endl;
	
	test->addFile("text", t);
	test->addFile("image", t);
	cout << test->addFile("ThisShouldn'tWork", a) << endl;
	cout << test->openFile("ThisShouldn'tWork") << endl;
	cout << test->openFile("text.txt") << endl;
	cout << test->openFile("text") << endl;
	cout << test->deleteFile("text") << endl;
	cout << test->closeFile(t) << endl;
	cout << test->deleteFile("text") << endl;

	vector<char> v = { 'X', 'X', ' ', ' ', '2'}; //this kinda doesn't work fam
	i->write(v);
	i->read();
	cout << i->getName() << endl;
	cout << i->getSize() << endl;

OUTPUT:
	0
	text.txt
	4
	00000000
	00000000
	011D7218
	2
	0
	0

	XX

	image.img
	4

We made a new simple file system and factory and then created an image and a text file. We then did various functions to ensure that 
they worked properly (i.e. getSize, adding them, opening them, trying to delete them while open and while closed, and for the image
file, we wrote a char vector to it and then read that)

Question 5: At this point, SimpleFileSystem only depends on the AbstractFile interface only.