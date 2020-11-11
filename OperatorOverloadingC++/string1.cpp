//31.StringClass - string1.cpp
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

#include "string1.h"

// Initialize using a quoted string.
StrType::StrType(const char* str)
{
	size = strlen(str) + 1;
	p = new char[size];
	strcpy_s(p, size, str);
}


StrType::StrType(const StrType& o)
{
	size = o.size;
	p = new char[size];
	strcpy_s(p, size, o.p);
}

StrType::~StrType()
{
	delete[]  p;
}


// Output a string.
std::ostream& operator<<(std::ostream& stream, StrType& o)
{
	stream << o.p;
	return stream;
}

std::istream& operator>>(std::istream& istream, StrType& o)
{
	istream >> o.p;
	return istream;
}

StrType& StrType::operator=(const StrType& o)
{
	if (&o == this) return *this;
	delete[] p;
	size = o.size;
	p = new char[size];
	strcpy_s(p, size, o.p);
	return *this;
}

StrType& StrType::operator=(const char* s)
{
	delete[] p;
	this->size = strlen(s) + 1;
	this->p = new char[size];
	strcpy_s(p, size, s);
	return *this;
}

StrType StrType::operator+(const StrType& o)
{
	StrType result;
	result.size = o.size + size;
	result.p = new char[result.size];
	strcpy_s(result.p, size, p);
	strcat_s(result.p, result.size, o.p);
	return result;
}

StrType StrType::operator+(const char* s)
{
	return StrType(s) + *this;
}