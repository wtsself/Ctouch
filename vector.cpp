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
//#include<iostream>
//#include<vector>
//#include<algorithm>
//	template<class T>//for_each������ͨ�õ����������
//	void cout1(T a) {
//		std::cout << a << " ";
//	}
//	float main() {
//		int a = 0;
//		float array[] = { 1.21,2.21,3.21,4.32 };
//		std::vector<float> v1(array, array + 4);
//		std::for_each(v1.begin(), v1.end(), cout1<float>);
//		std::cout << std::endl;
//		std::vector<float> v2(v1);
//		std::vector<float> v3(3, 21);
//		std::for_each(v2.begin(), v2.end(), cout1<float>);
//		std::cout << std::endl;
//		std::for_each(v3.begin(), v3.end(), cout1<float>);
//
//		std::cout << std::endl;
//		std::string array_str[] = { "my" ,"name","is","wutaisong" };
//		std::vector<std::string> v4(array_str, array_str + 4);
//		std::for_each(v4.begin(), v4.end(), cout1<std::string>);
//		std::cout << std::endl;
//		std::vector<std::string> v21;
//		v21.push_back("i");
//		v21.push_back("love");
//		v21.push_back("you");
//		for (std::vector<std::string>::iterator ite = v21.begin(); ite != v21.end(); ite++) {
//			std::cout << *ite << " ";//���������Կ���һ��ָ��
//		}
//		std::cout << std::endl;
//		a = 2;
//
//		return 0;
//	}
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

	//����
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
	//������ͳһ�˶����������ķ��ʷ�ʽ��������������ָ�루���Ͻ�����Ҳ�������࣬vector<int>::iterator ite,iteΪ������������ָ��
	//������ʧЧ����--vs������쳣��ֹ
	//������µ�����ʧЧ
	std::vector<int> v1(5, 2);
	//std::cout << v1[15] << std::endl;
	//v1[15] = 100;//����Խ����ܻ��޸��ڴ�ֵ
	//std::cout << v1[15] << std::endl;
	std::vector<int>::iterator ite;
	ite = v1.begin() + 4;
	//v1.insert(v1.begin() + 4, 8);//�������ʹԭ������Ŀռ䱻�ͷŵ��ˣ�������ڴ������ռ䣬����iteָ������Ұָ�룬���������iteָ���ֵӦ��Ϊ8
	//std::cout <<*ite;
	ite = v1.insert(v1.begin() + 4, 8);//�ڲ�����ʹ�õ�������Ҫ�����ò���ķ���ֵ���¸�ֵ--�ò������µ�����
	std::cout << *ite;

	//ɾ��Ԫ�غ��µ�����ʧЧ
	std::vector<int> v1 = { 1,2,3,3,3,3,3,4,5 };
	for (std::vector<int>::iterator ite = v1.begin(); ite != v1.end(); ) {
		if (*ite == 3) {
			ite=v1.erase(ite);//���µ�����
		}
		else {
			ite++;//�����for�е�++�Ƶ�������Ϊ���ܹ���ɾ��һ��Ԫ�غ󣬸�Ԫ�غ��Ԫ��λ��ǰ�ƣ�vector��̬���ԣ���ite�ܹ������ڸ�λ�����ж�
		}
	}
	for (std::vector<int>::iterator ite = v1.begin(); ite != v1.end(); ite++) {
		std::cout << *ite << std::endl;
	}
#endif
	//deque��˫�����飬��vector�����кܶ�����֮�������Ƕ�̬���飩
	//deque��������ʱ�����ݲ�����ȫ�����ģ�ͨ��[]����������ҵ����ݣ���vector�����������ݴ洢�ռ䣬������vector��Ч�ʸ���
	//deque���е�ͷ���ͷɾ��push_front(),pop_front()
	//��ҪƵ��ʹ��ͷ��ʱ����deque������vector





	std::cout << "\nfuck you !";
	return 0;
}