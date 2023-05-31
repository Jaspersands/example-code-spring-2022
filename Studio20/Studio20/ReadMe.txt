Studio 20 ReadMe.txt
Question 1: Ethan and Jasper
Question 2: It's necessary to delete the pointer to the actual file because it would be a memory leak if not. When the proxy is deleted,
the actual file is still there so it must be cleaned up.
Question 3: No question provided. 
Question 4: 

Test code: 
	AbstractFileFactory* fac = new SimpleFileFactory();
	AbstractFile* t = fac->createFile("text.txt");
	PasswordProxy* p = new PasswordProxy(t, "swag");
	AbstractFileVisitor* a = new BasicDisplayVisitor;
	cout << p->getName() << endl;
	cout << p->getSize() << endl;
	vector<char> v = { 'V', 'E', 'R', 'S', 'A', 'C', 'E', '2'};
	vector<char> b = { 'B', 'E', 'R', 'S', 'A', 'C', 'E'};
	p->write(v);
	cout << p->getSize() << endl;
	p->append(b);
	p->accept(a);
	cout << p->getSize() << endl;
	return 0;

Output: 
	text.txt
	0
	Enter password:
	swag
	8
	Enter password:
	swag
	Enter password:
	swag
	VERSACE2BERSACE
	15

The testing all made sense. I just used a text file and used the proxy to write to it, append it, and print it out using a basic
display visitor. It asks for the password everytime, which makes sense given the code.

Finally got all the unit tests first try :)