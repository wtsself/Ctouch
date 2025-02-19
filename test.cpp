#include<iostream>
#include<string>
#include"MyArray.hpp"
using namespace std;
/*
类模板：
1：类模板中的成员函数在调用时才创建

2：类模板对象做函数参数：
一共有三种传入方式
指定传入的类型——直接显式对象的数据类型
void PrintPerson1(Person<string,int>&p)
参数模板化——将对象中的参数变为模板参数进行传递
template<class T1,class T2>
void PrintPerson2(Person<T1, T2>&p)
整个类模板化——将这个对象类型，模板化进行传递
template<class T>
void PrintPerson3(T &p)
调用都是：Person<string, int>p1("张三",11);

3：类模板与继承
当类模板碰到继承时，需要注意一下几点：
当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的数据类型
如果不想指定，编译器无法给子类分配内存
如果想灵活指定出父类中T的类型，子类也需要变为类模板

4：类模板中成员函数类外实现时，需要加上模板参数列表
template<class T1,class T2>
void Person<T1,T2>::showPerson()

5：类模板分文件编写
问题：
类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
解决方式:将声明.h和实现.cpp在到同一个文件中，并更改后缀名为.hpp,hpp是约定俗成的名称，并不是强制
.hpp文件

6：
类模板与友元
全局函数类内实现，直接在类内声明友元即可
friend void PrintPerosn(Person<T1,T2>p)
全局函数类外实现，需要提前让编译器知道全局函数的存在
friend void PrintPerosn2<>(Person<T1, T2>p);


*/

void PrintArray(MyArray<int>&arr) {
	for (int i = 0; i<arr.getSize();i++) {
		cout<<arr[i]<<endl;
	}
}
//测试通用数据类型int
void test01() {
	MyArray <int> arr1(5);
	for (int i = 100; i < 105; i++) {
		arr1.PushBack(i);
	}
	cout << "arr1的打印输出" << endl;
	PrintArray(arr1);
	cout << "arr1的容量为" << arr1.getCapacity() << endl;
	cout << "arr1的大小为" << arr1.getSize() << endl;
	cout << "arr2的打印输出" << endl;
	MyArray <int> arr2(arr1);//拷贝
	//arr2 = arr1;调用头文件中=运算符重载
	PrintArray(arr2);
	arr2.PopBack();
	arr2.PopBack();
	cout << "arr2尾删后" << endl;
	cout << "arr2的容量为" << arr2.getCapacity() << endl;
	cout << "arr2的大小为" << arr2.getSize() << endl;
}
//测试通用数据类型
class Person {
public:
	Person() {}
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

void PrintPersonArray(MyArray<Person>&arr) {
	for (int i = 0; i < arr.getSize();i++) {
		cout << "姓名：" << arr[i].name << "年龄：" << arr[i].age << endl;
	}
}

void test02() {
	MyArray <Person>arr(10);
	Person p1("伞兵1", 21);
	Person p2("伞兵2", 22);
	Person p3("伞兵3", 23);
	Person p4("伞兵4", 24);
	Person p5("伞兵5", 25);
	//将数据插入到数组中
	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	arr.PushBack(p5);
	PrintPersonArray(arr);
	//输出容量
	cout << "arr容量为" << arr.getCapacity() << endl;
	//输出大小
	cout << "arr大小为" << arr.getSize() << endl;


}





int main(void)
{
	test01();
	test02();
	system("pause");
	return 0;
}

