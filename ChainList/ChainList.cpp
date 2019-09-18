//date:2019.9.18
//description: a practice about chainlist in c++ 
#include <iostream>
#include<string>
#include "ChainList.hpp"
class People {
public:
	People() {
		name = "xxx";
		id = 8888888;
	}
	People(string str, int id) :name(str), id(id) {}
	friend ostream& operator<<(ostream& out,  People p);
	ostream& Print(ostream& out) {
		out << "name: " << name << "  id Number: " << id <<"   ";
		return out;
	}
protected:
	string name;
	int id;
};
ostream& operator<<(ostream& out, People p) {
	return p.Print(out);
}
void test01() {
	Chain<int> list1;
	for (int i = 0; i < 20; i++) {
		list1.insert(0, i);
	}
	Chain<int>::iterator temp = list1.begin();
	for (temp; temp != list1.end(); temp++)
		cout << *temp << endl;
	list1.erase(10);
}
void test02() {
	Chain<People> list2;
	for(int i=0;i<20;i++){
		string temp = "MMMMMMMMM" ;
		list2.insert(0, People(temp, i * 10));
	}
	list2.erase(10);
	list2.insert(10, People());
	list2.output(cout);
}
using namespace std;
int main()
{
	//test01();
	test02();
}
