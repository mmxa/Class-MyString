#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyString.h"
MyString::MyString() {
	this->mlen = 0;
	this->mstr = NULL;
}
MyString::MyString(const char* str) {
	if (str == NULL) {
		this->mlen = 0;
		this->mstr = new char[0 + 1];
		strcpy(this->mstr,"");
	}
	else {
		int len = strlen(str);
		this->mlen = len;
		this->mstr = new char[len + 1];
		strcpy(this->mstr, str);
	}
}
MyString::~MyString() {
	if (this->mstr != NULL) {
		delete[] this->mstr;
		this->mstr = NULL;
		this->mlen = 0;
	}
}
MyString::MyString(const MyString& another) {
	if (this->mstr != NULL) {
		delete[] this->mstr;
		this->mstr = NULL;
	}
	this->mlen = another.mlen;
	this->mstr = new char[this->mlen + 1];
	strcpy(this->mstr, another.mstr);
	cout << "should be s2 constructor";
}
char& MyString::operator[](int index) 
{
	if (index < 0 || index >= this->mlen) 
	{
		throw("index should between length");
	}
	else 
	{
		return this->mstr[index];
	}
}
ostream& operator<<(ostream& os,MyString& s) {
	os << s.mstr << endl;
	return os;
}
istream& operator>>(istream& is, MyString& s) {
	if (s.mstr != NULL){
		delete[] s.mstr;
		s.mstr = NULL;
		s.mlen = 0;
	}
	char temp[4096] = { 0 };
	cin.getline(temp,4096);
	int len = strlen(temp);
	s.mstr = new char[len + 1];
	strcpy(s.mstr, temp);
	s.mlen = len;
	return is;
}