#include<iostream>
#include<vector>
#include<algorithm>

template<class T>
void myprint(T n) {
	std::cout << n << " ";
}

//����Ҫһ�߿�һ���ã��⿴���õ��ڲ�ѧ
int main() {
#if 0
	//����
	int arry[] = { 1,2,3,4,5 };
	std::vector<int> v1(arry, arry + 5);
	std::vector<int> v2(3, 9);
	std::vector<int> v3(v1);
	for (std::vector<int>::iterator ite = v1.begin(); ite != v1.end(); ite++) {
		std::cout << *ite << std::endl;
	}
	std::for_each(v3.begin(), v3.end(), myprint<int>);
	std::cout << "\n";

	//��ֵ
	int arry[] = { 1,2,3,4,5 };
	std::vector<int> s1, s2, s3;
	s1.assign(arry, arry + 5);
	s2.assign(s1.begin(), s1.end());
	for (int i = 0; i < s2.size(); i++) {
		std::cout << s2[i] << " ";
	}
	s3.assign(5, 10);
	s3.swap(s2);
	std::cout << "����Ļ�����swap��" << std::endl;
	for (int i = 0; i < s2.size(); i++) {
		std::cout << s2[i] << " ";
	}
	s2 = s3;//=���������


	//��С
	std::vector<int> f1;
	std::cout << f1.size() << std::endl;
	if (f1.empty()) {
		std::cout << "f1�����ǿյ�";
	}
	f1.assign(5, 1);
	f1.resize(10);//ָ��������С���ڱ䳤���Ĭ��ֵ���ڿ�λ�ô��������ɾ�������ֵ��resize��n,m�����ڶ�������Ϊָ����Ĭ��ֵ
	std::for_each(f1.begin(), f1.end(), myprint<int>);

	//����
	std::vector<std::string> s2(5, "wutaisong");
	for (int i = 0; i < s2.size(); i++) {
		std::cout << s2[i] << " ";//s2[10],�±����Խ����ܻᵼ�³����쳣��ֹ
	}
	s2.at(10);//ʹ��at��������Խ��ʱ�׳��쳣
#endif
	std::vector<int> s2(10,1); 
	for (int i = 0; i < s2.size(); i++) {
		std::cout << s2[i] << " ";
	}
	std::cout << "\n";
	s2.push_back(12);
	for (int i = 0; i < s2.size(); i++) {
		std::cout << s2[i] << " ";
	}
	std::cout << "\n";
	s2.pop_back();
	for (int i = 0; i < s2.size(); i++) {
		std::cout << s2[i] << " ";
	}
	std::cout << "\n";
	//ָ��λ�ò�������
	s2.insert(s2.begin() + 4, 999);//��һ������Ϊָ�룬��Ϊ�±�
	std::for_each(s2.begin(), s2.end(), myprint<int>);
	std::cout << "\n";
	//ָ��λ�ò���������
	s2.insert(s2.begin() + 4, 3, 90);
	std::for_each(s2.begin(), s2.end(), myprint<int>);
	std::cout << "\n";
	//ָ��λ�ò���ָ�����������
	int a[] = { 1,2,3,4,5,6,6,7 };
	s2.insert(s2.begin() + 2, a + 1, a + 8);
	std::for_each(s2.begin(), s2.end(), myprint<int>);
	std::cout << "\n";

	int v[5] = { 10,20,30,40,50 };
	std::vector<int> r1(v + 2, v + 5);//30��40��50
	s2.insert(s2.begin() + 1, r1.begin() + 1, r1.end());//40.50���s2��һ��Ԫ�غ��λ�ã�begin()�������׵�ַ�������׸�Ԫ�أ����s2.begin() + 1���Ǵӵڶ�Ԫ��λ�ò��ȥ
	std::for_each(s2.begin(), s2.end(), myprint<int>);
	std::cout << "\n"<<s2.size();

	std::cout << "\nfuck you !";
	return 0;
}