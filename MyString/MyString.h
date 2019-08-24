#pragma once
#include <iostream>
using namespace std;
class MyString {
public:
	MyString();
	MyString(const char* str);
	~MyString();
	MyString(const MyString& another);
	char& operator[](int index);
	friend ostream& operator<<(ostream& os, MyString& s);
	friend istream& operator>>(istream& is, MyString& s);
private:
	int mlen;
	char* mstr;
};