// 手写string.cpp 

#include <iostream>
#include "MyString.h"
void test01() {
	MyString s1("I am Meng!");
	cout << s1 << endl;
	MyString s2 = s1;
	s1[0] = 'm';
	cout << s1 << endl;
	cout << s2 << endl;
	cin >> s2;
	cout << s2;
}
int main()
{
    test01();
	return 0;
}
