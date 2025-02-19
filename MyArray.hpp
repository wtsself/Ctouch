//这是我手搓的类模板案例
#pragma once
#include<iostream>
using namespace std;
template<class T>//数组的数据为通用数据类型
class MyArray 
{
public:
	//有参构造函数，参数为容量
	MyArray(int capacity) {
		this->m_Size = 0;
		this->m_Capacity = capacity;
		this->pAddress = new T[this->m_Capacity];
	}
	 //拷贝构造函数
	MyArray(const MyArray& arr) {
		this->m_Size = arr.m_Size;
		this->m_Capacity = arr.m_Capacity;
		this->pAddress = new T[arr.m_Capacity];//深拷贝，pAddress存放的是数组首地址，开辟堆区数该数组时指定其大小为容量大小
		//arr中数据拷贝过来
		for (int i = 0; i < arr.m_Size;i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator防止浅拷贝问题,前者是调用拷贝构造函数来拷贝，这个是用等于号=运算符重载来实现拷贝操作
	MyArray& operator=(const MyArray & arr) {
		//先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL) {
			this->m_Size = 0;
			this->m_Capacity =0;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
		this->m_Size = arr.m_Size;
		this->m_Capacity = arr.m_Capacity;
		this->pAddress = new T[arr.m_Capacity];//深拷贝，pAddress存放的是数组首地址，开辟堆区数该数组时指定其大小为容量大小
		//arr中数据拷贝过来
		for (int i = 0; i < arr.m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插法
	void PushBack(const T&val) {
		if (this->m_Capacity == this->m_Size) {
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//尾删法
	void PopBack() {
		//逻辑删除，访问不到数组的最后一个元素
		if (this->m_Size==0) {
			return;
		}
		this->m_Size--;
	}
	//[]运算符重载,下标访问数组中的元素,数组对象为类对象，必须要用这个
	T& operator[](int index) {
		return this->pAddress[index];
	}

	int getCapacity() {
		return this->m_Capacity;
	}

	int getSize() {
		return this->m_Size;
	}
	~MyArray(){
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}//删不删size和capacity都可以反正是临时变量调用后就销毁
	}

private:
	T* pAddress;//指针指向在堆区开辟的数组地址
	int m_Size;
	int m_Capacity;
};