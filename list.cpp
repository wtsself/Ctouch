
#include<iostream>
#include<list>
#include<algorithm>



//����Ҫһ�߿�һ���ã��⿴���õ��ڲ�ѧ
int main() {
	//list��˫�������ʺ��ڴ����Ĳ���ɾ�������������������ȡ������[],at()��Ҳ���ܣ�+��������������++��--
	std::list<int> v1;
	//ͷβ�Ĳ����ɾ��
	v1.push_front(10);
	v1.push_front(100);
	v1.push_back(999);
	v1.push_back(9999);
	for (std::list<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout <<  " \n";
	v1.pop_back();
	v1.pop_front();
	for (std::list<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n" << v1.front() << "�׸��ڵ�" << std::endl;
	std::cout << v1.back() << "ĩβ�ڵ�" << std::endl;
	v1.front() = 20;
	v1.back() = 90;
	std::cout << v1.front() << "�޸��׸��ڵ�" << std::endl;
	std::cout << v1.back() << "�޸�ĩβ�ڵ�" << std::endl;
	//stackջ��queue�����ǲ��ɱ�����







	std::cout << "\nfuck you !";
	return 0;
}