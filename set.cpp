#include<iostream>
#include<algorithm>
#include<set>
using std::cout;
using std::endl;
typedef int (*x)(int, int);


int fun1(int a,int b) {
	return a + b;
}

int fun2(int a, int b) {
	return a * b;
}
int fun(int a, int b,x fun) {
	return fun(a, b);
}
//namespace DC {
//	class ass {
//	private:
//	public:
//	};
//}

class stu {
public:
	stu(int id ,std::string name) {
		m_id = id;
		m_name = name;
	}
	int m_id;
	std::string m_name;
};


//α����(һ�����ṹ�壬������operator()����,�������Զ���ıȽϣ������ӳ��)
class stu_fun {
public://���Ĭ�Ϸ���Ȩ���� private���� �ṹ�壨struct����Ĭ�Ϸ���Ȩ���� public
	bool operator()(const stu &s1,const stu &s2) const{
		return s1.m_id < s2.m_id;//��������
	}
};



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

	
	
	//DC::ass as;
	//cout<< as.fun(2, 3, fun1);��δ���fun1ʶ�𲻵��������ռ��ڴ��ڷ��ʺ���ָ������

	



	std::set<int,std::less<int>> s1;//�������У�less<int>��ģ���࣬Ĭ��Ϊ��������
	std::set<int, std::greater<int>> s2;//��������
	s1.insert(5);
	s1.insert(2);
	s1.insert(3);
	s2.insert(5);
	s2.insert(2);
	s2.insert(3);
	std::set<int>::iterator it;
	for (it = s1.begin(); it != s1.end(); it++) {
		std::cout << *it << std::endl;
	}
	for (it = s2.begin(); it != s2.end(); it++) {
		std::cout << *it << std::endl;
	}
	//��һ�º���ָ��
	/*
int x;      // x��һ��int�͵ı���
int *x;     // x��һ��ָ��int�ͱ�����ָ��
int *x();   // x��һ������int��ָ��ĺ���
int (*x)(); // x��һ������ָ�룬�������Ϊ�գ���������Ϊint��ָ��
����:	
int array[5];      // array��һ��ָ��int��ָ�볣��
int *p = array;    // p��һ��ָ��int��ָ�������p = array�Ϸ�
p[3];              // �ȼ���array[3]
 
void test(int a){ cout << "a=" << a << endl;}  // test��һ������ָ�볣�����������int����������void
void (*pf)(int);   // ��������ָ��pf�� pf��һ���������int������void�ĺ�����ָ��
pf = test;         // ��test������ַ��ֵ��pf��������������б��������ͱ���һ�£�
pf(123);           // �ȼ���test(123)
	
	*/
	//����ָ��ָ����Ǻ�������Ҳ���Ǻ�����ַ����ʱָ����൱�ں�����������ָ����ǵ��ú���
	cout << "9 and 9 + equl :" << fun(9, 9, fun1) << endl;
	cout << "9 and 9 * equl :" << fun(9, 9, fun2) << endl;
	
	//�㲻�����������������
	//ע��һ��������ϸ�ڣ�
	//��C++�У���������Ƕ�׶��塣Ҳ����˵���㲻����һ�������ڲ�������һ������������Ĵ����У�abc()������������main()�����ڲ������ǲ��Ϸ��ģ���˱������ᱨ��

	//����һ������ʵ�ִ����ѧ������Ϣ�������շº������Զ���ĵ������������
	std::set<stu, stu_fun> a1;
	a1.insert(stu(16,"̫��"));
	a1.insert(stu(23, "̫��"));
	a1.insert(stu(11, "̫��"));
	std::set<stu, stu_fun>::iterator it;
	for (it = a1.begin(); it != a1.end(); it++) {
		cout << "id :" << it->m_id << " " << "name:" << it->m_name << endl;
	}
#endif
	//����
	std::set<int> a;
	a.insert(1);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	std::set<int>::iterator it;
	it = a.find(3);
	cout << "find 3 yes or no:" << *it << endl;
	//�Ҳ���ָ��Ԫ��ʱ������end����
	it = a.find(2);
	if (it == a.end()) {
		cout << " i can't find it" << endl;
	}
	else {
		cout << *it << endl;
	}
	//a.count(elem)������������elemֵ�ĸ���������Ϊ��set��Ԫ��Ψһ�����Կ����ж��Ƿ���ڸ�Ԫ�أ���mutiset�������֪������

	//lower_bound(elem)���ҵ�һ�����ڵ���elem��Ԫ��
	it = a.lower_bound(3);
	cout << "should be 3:" << *it << endl;
	//upper_bound(elem)���ҵ�һ������elem��Ԫ��
	it = a.upper_bound(4);
	cout << "should be 5:" << *it << endl;
	return 0;
}