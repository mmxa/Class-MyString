
#include "LinkList.h"

typedef struct PERSON {
	char name[64];
	int age;
	int score;
}Person;
void myprint(void* data) {
	Person* p = (Person*)data;
	printf("name: %s, age: %d, score: %d\n", p->name, p->age, p->score);
}

void test() {
	Person p1 = { "aaa",1,10 };
	Person p2 = { "aaa",2,20 };
	Person p3 = { "aaa",3,30 };
	Person p4 = { "aaa",4,40 };
	LinkList* list = Init_LinkList();
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Print_LinkList(list,myprint);
	printf("--------------------\n");
	RemoveByPos_LinkList(list, 2);
	Print_LinkList(list, myprint);
}
int main()
{
	test();
	return 0;
}	
