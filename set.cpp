#include<iostream>
#include<algorithm>
#include<set>

int main() {
	//set�Ǽ����������ǹ���ʽ����(ͬmap����)����ǰ�������ʽ������ͬ
	//set��Ԫ����Ψһ��(����ʵ��ȥ���ظ�Ԫ�صĹ���)������һ��˳�����У�����_Ĭ�ϣ�,����ָ������λ�ã�Ҳ�����±��at()����
	//set�ǲ��ú����ʵ�֣�һ����ƽ��Ķ�����
	//multiset��set��ȣ�mutiset���Գ�����ͬ��Ԫ��
	//set��mutiset�в���ֱ���޸�ֵ��Ҫ��Ҳֻ��ɾ��ԭ�ȵ�ֵ������µ�ֵ
#if 0
	std::set<int> a;
	std::multiset<int> b;
	a.insert(1);//��Ϊû��ָ��λ�õĲ��룬����û�е������Ĳ�����²���
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);

	std::set<int>::iterator it;
	for (it = a.begin(); it != a.end(); it++) {
		std:: cout<< *it << std::endl;
	}


	std::set<int>::reverse_iterator rit;
	for (rit = a.rbegin(); rit != a.rend(); rit++) {
		std::cout << *rit << std::endl;
	}

	
	std::set<int> c(a); 
	c = a;
	c.clear();
	c.insert(102);
	c.insert(121323232);
	a.swap(c);//���ݻ���
	a.insert(11);
	a.insert(12);
	for (it = a.begin(); it != a.end(); it++) {
		std::cout << *it << std::endl;
	}
	it = a.begin();
	std::cout << "itָ���Ԫ��ֵΪ��" << *it << std::endl;//��δ���ᱨ��
	a.erase(it);//erase()�Ĳ���ֻ���ǵ�����(ָ��),��ֻ�������������,���Ҵ�ʱû�и��µ�������������ָ����ڴ�ռ䱻�ͷ��ˣ����Ұָ���ˣ��ٷ��ʵ�����ָ���ֵ���쳣
	//std::cout << "itָ���Ԫ��ֵΪ��" << *it << std::endl;��ʱ�޷�����
	
	std::cout << "ɾ��itָ���Ԫ�غ�a��Ԫ���У�" << std::endl;
	for (it = a.begin(); it != a.end(); it++) {
		std::cout << *it << std::endl;
	}

	it = a.begin();
	std::cout << "itָ���Ԫ��ֵΪ��" << *it << std::endl;
	it = a.erase(it);
	std::cout << "����ʹ�õ���������it����ָ���Ԫ��ֵΪ��" << *it << std::endl;
	
	std::cout << "ɾ��itָ���Ԫ�غ�a��Ԫ���У�" << std::endl;
	for (it = a.begin(); it != a.end(); it++) {
		std::cout << *it << std::endl;
	}
	a.insert(99);
	for (it = a.begin(); it != a.end(); it++) {
		std::cout << *it << std::endl;
	}
	a.erase(102);//ɾ��ָ����ֵ�����������򷵻�false
	for (it = a.begin(); it != a.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << "�Ƿ���102��Ϊ�գ����" << a.erase(102)<<a.empty()<<a.size();
	//empty(),clear()��size()����Ҳ����
#endif


	return 0;
}