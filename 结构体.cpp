#include<iostream>
#include<string>
#include<ctime>
using namespace std;


struct stu
{
	string name;
	int age;
	int money;
	int inventory;
	string interest;
};
struct teac
{
	string name;
	struct stu a[2];
};

void pop(struct teac *m) {
	m->name = "stw";
	m->a[0].age = 100;
	m->a[1].age = 200;
}

int main(void)
{
	struct stu bb[2] = { { "1",1,1,1,"1" } ,{"2",2,2,2,"2"}};
	struct teac aa = { "wts",{bb[0],bb[1]}};

	pop(&aa);

	cout << aa.name << endl << aa.a[0].age<<endl<<aa.a[1].age<<endl;

	system("pause");
	return 0;
}
