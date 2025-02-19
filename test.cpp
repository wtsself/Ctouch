#include<iostream>
#include<string>
#include"MyArray.hpp"
using namespace std;
/*
��ģ�壺
1����ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���

2����ģ�����������������
һ�������ִ��뷽ʽ
ָ����������͡���ֱ����ʽ�������������
void PrintPerson1(Person<string,int>&p)
����ģ�廯�����������еĲ�����Ϊģ��������д���
template<class T1,class T2>
void PrintPerson2(Person<T1, T2>&p)
������ģ�廯����������������ͣ�ģ�廯���д���
template<class T>
void PrintPerson3(T &p)
���ö��ǣ�Person<string, int>p1("����",11);

3����ģ����̳�
����ģ�������̳�ʱ����Ҫע��һ�¼��㣺
������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T����������
�������ָ�����������޷�����������ڴ�
��������ָ����������T�����ͣ�����Ҳ��Ҫ��Ϊ��ģ��

4����ģ���г�Ա��������ʵ��ʱ����Ҫ����ģ������б�
template<class T1,class T2>
void Person<T1,T2>::showPerson()

5����ģ����ļ���д
���⣺
��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���
�����ʽ:������.h��ʵ��.cpp�ڵ�ͬһ���ļ��У������ĺ�׺��Ϊ.hpp,hpp��Լ���׳ɵ����ƣ�������ǿ��
.hpp�ļ�

6��
��ģ������Ԫ
ȫ�ֺ�������ʵ�֣�ֱ��������������Ԫ����
friend void PrintPerosn(Person<T1,T2>p)
ȫ�ֺ�������ʵ�֣���Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
friend void PrintPerosn2<>(Person<T1, T2>p);


*/

void PrintArray(MyArray<int>&arr) {
	for (int i = 0; i<arr.getSize();i++) {
		cout<<arr[i]<<endl;
	}
}
//����ͨ����������int
void test01() {
	MyArray <int> arr1(5);
	for (int i = 100; i < 105; i++) {
		arr1.PushBack(i);
	}
	cout << "arr1�Ĵ�ӡ���" << endl;
	PrintArray(arr1);
	cout << "arr1������Ϊ" << arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�СΪ" << arr1.getSize() << endl;
	cout << "arr2�Ĵ�ӡ���" << endl;
	MyArray <int> arr2(arr1);//����
	//arr2 = arr1;����ͷ�ļ���=���������
	PrintArray(arr2);
	arr2.PopBack();
	arr2.PopBack();
	cout << "arr2βɾ��" << endl;
	cout << "arr2������Ϊ" << arr2.getCapacity() << endl;
	cout << "arr2�Ĵ�СΪ" << arr2.getSize() << endl;
}
//����ͨ����������
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
		cout << "������" << arr[i].name << "���䣺" << arr[i].age << endl;
	}
}

void test02() {
	MyArray <Person>arr(10);
	Person p1("ɡ��1", 21);
	Person p2("ɡ��2", 22);
	Person p3("ɡ��3", 23);
	Person p4("ɡ��4", 24);
	Person p5("ɡ��5", 25);
	//�����ݲ��뵽������
	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	arr.PushBack(p5);
	PrintPersonArray(arr);
	//�������
	cout << "arr����Ϊ" << arr.getCapacity() << endl;
	//�����С
	cout << "arr��СΪ" << arr.getSize() << endl;


}





int main(void)
{
	test01();
	test02();
	system("pause");
	return 0;
}

