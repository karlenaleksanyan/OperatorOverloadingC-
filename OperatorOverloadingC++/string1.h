#pragma once
//31.StringClass - string1.cpp
#include <iostream>
#include <new>
#include <cstring>
#include <cstdlib>
using namespace std;

#include <conio.h>
#include <stdio.h>

class StrType {
	char* p;
	int size;
public:
	StrType(const char* str = "");
	StrType(const StrType& o); // copy constructor
	~StrType();

	int strsize() { return strlen(p); }
	void makestr(char* s) { strcpy_s(s, size, p); }

	friend ostream& operator<<(ostream& stream, StrType& o);
	friend istream& operator>>(istream& stream, StrType& o);

	StrType& operator=(const StrType& o); // assign a StrType object
	StrType& operator=(const char* s);// assign  a quoted string to  object

	StrType operator+(const StrType& o); // concatenate a StrType object
	StrType operator+(const char* s); // concatenate a quoted string


   // relational operations between StrType objects
	bool operator==(StrType& o) { return strcmp(p, o.p) == 0; }
	bool operator!=(StrType& o) { return strcmp(p, o.p) != 0; }
	bool operator<(StrType& o) { return  strcmp(p, o.p) < 0; }
	bool operator>(StrType& o) { return  strcmp(p, o.p) > 0; }
	bool operator<=(StrType& o) { return  strcmp(p, o.p) <= 0; }
	bool operator>=(StrType& o) { return  strcmp(p, o.p) >= 0; }

	//operations between StrType objects and quoted strings
	bool operator==(const char* s) { return strcmp(p, s) == 0; }
	bool operator!=(const char* s) { return strcmp(p, s) != 0; }
	bool operator<(const char* s) { return strcmp(p, s) < 0; }
	bool operator>(const char* s) { return strcmp(p, s) > 0; }
	bool operator<=(const char* s) { return strcmp(p, s) <= 0; }
	bool operator>=(const char* s) { return strcmp(p, s) >= 0; }

	operator const char* ()
	{
		return p;
	}
};