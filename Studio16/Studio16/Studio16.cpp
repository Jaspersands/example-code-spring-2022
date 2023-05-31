// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>
#include <vector>
#include <string>


using namespace std;

int& foo(int* p){
	int &i = *p;
	i = 5;
	return i;
}
 
void bar(int& i) {
	int j = 10;
	i = j;
	j = 0;
}

int& bar(int* p) {
	//int m = 5;
	//p = m;
	int& i = *p;
	i = 5;
	return i;
}

void swag(int i, int& j, int* k) {
	++i;
	k = &j;
	*k = 10;
	k = &i;
	*k = 5;
}

int main()
{
	
	
	int a = 10;
	int b = 20;
	int c = 30;
	int& z = a;
	int* y = &b;
	cout << z << y << endl;
	z = b;
	cout << b << a << z << endl;
	y = &c;
	swag(a, b, &c);
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;
	int l = 5;
	bar(l);
	//cout << l << endl;
	int k = 10;
	cout << k << endl;
	int& j = foo(&k);
	cout << k << " " << j << endl;
	vector<char> temp = {'p', 'o', 'o', 'p'};
	//TextFile test("swag");
	//AbstractFile& newTest = test;
	AbstractFile *newTest = new TextFile("swag");
	(*newTest).write(temp);
	//cout << (*newTest).getName() << endl;
	(*newTest).append(temp);
	//(*newTest).read();
	/*test.write(temp);
	cout << test.getName() << endl;
	test.append(temp);
	test.read();*/
	int maths = 99;
	int* pmaths = &maths;
	cout << pmaths << endl;
	cout << &pmaths << endl;
	cout << &maths << endl;
	cout << *pmaths << endl;
	cout << maths << endl;
	return 0;
}


