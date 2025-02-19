//�������ִ����ģ�尸��
#pragma once
#include<iostream>
using namespace std;
template<class T>//���������Ϊͨ����������
class MyArray 
{
public:
	//�вι��캯��������Ϊ����
	MyArray(int capacity) {
		this->m_Size = 0;
		this->m_Capacity = capacity;
		this->pAddress = new T[this->m_Capacity];
	}
	 //�������캯��
	MyArray(const MyArray& arr) {
		this->m_Size = arr.m_Size;
		this->m_Capacity = arr.m_Capacity;
		this->pAddress = new T[arr.m_Capacity];//�����pAddress��ŵ��������׵�ַ�����ٶ�����������ʱָ�����СΪ������С
		//arr�����ݿ�������
		for (int i = 0; i < arr.m_Size;i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator��ֹǳ��������,ǰ���ǵ��ÿ������캯����������������õ��ں�=�����������ʵ�ֿ�������
	MyArray& operator=(const MyArray & arr) {
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL) {
			this->m_Size = 0;
			this->m_Capacity =0;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
		this->m_Size = arr.m_Size;
		this->m_Capacity = arr.m_Capacity;
		this->pAddress = new T[arr.m_Capacity];//�����pAddress��ŵ��������׵�ַ�����ٶ�����������ʱָ�����СΪ������С
		//arr�����ݿ�������
		for (int i = 0; i < arr.m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//β�巨
	void PushBack(const T&val) {
		if (this->m_Capacity == this->m_Size) {
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//βɾ��
	void PopBack() {
		//�߼�ɾ�������ʲ�����������һ��Ԫ��
		if (this->m_Size==0) {
			return;
		}
		this->m_Size--;
	}
	//[]���������,�±���������е�Ԫ��,�������Ϊ����󣬱���Ҫ�����
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
		}//ɾ��ɾsize��capacity�����Է�������ʱ�������ú������
	}

private:
	T* pAddress;//ָ��ָ���ڶ������ٵ������ַ
	int m_Size;
	int m_Capacity;
};