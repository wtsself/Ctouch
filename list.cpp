
#include<iostream>
#include<list>
#include<algorithm>



//����Ҫһ�߿�һ���ã��⿴���õ��ڲ�ѧ
int main() {
#if 0
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
	std::cout << " \n";
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

	//list�����ĵ�������˫���������list˫��������iterator���������������reverse_iterator�Ƿ��������
	//rebegin(),rend()�Ƿ���ĵ�һ�������һ����һ��Ԫ��
	std::list<int> v1;
	v1.push_back(10);
	v1.push_front(20);
	v1.push_front(30);//30,20,10

	//�����ȡ
	for (std::list<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++) {
		std::cout << *it << " ";
	}

	//���췽��
	std::list<int> v1(3,5);//(n,m)����n��m��list����
	for (std::list<int>::iterator it = v1.begin(); it != v1.end(); it++){
		std::cout << *it << " ";
	}
	std::list<int> v2;
	v2.push_back(10);
	v2.push_front(20);
	v2.push_front(30);
	v2.push_front(40);//40,30,20,10
	//list�����乹��������ҿ�[n,m+1)
	//��֧��std::list<int> v3(v2.begin()+1,v2.begin()+2);�Ĺ��죬����+n
	//�Ƚ��鷳
	std::list<int>::iterator beg = v2.begin();
	std::list<int>::iterator end = v2.begin();
	beg++;
	end++;
	end++;
	end++;
	
	std::list<int> v3(beg,end);
	for (std::list<int>::iterator it = v3.begin(); it != v3.end(); it++) {
		std::cout << *it << " ";
	}
	//���ÿ�������
	std::list<int> v4(v2);
	for (std::list<int>::iterator it = v4.begin(); it != v4.end(); it++) {
		std::cout << *it << " ";
	}

	//��ֵ��assign()������ֵ���Ǹ��Ǹ�ֵ
	//ͬvectorһ���ĸ�ֵ����,v1.assign(n,m);��n��m-1���������ݸ�ֵ
	//v1.assign(n,m)��������Ϊ����ʱ��n��m��ֵ��list
	//=�����������
	//swap()������������
	std::list<int> v2;
	v2.push_back(10);
	v2.push_front(20);
	v2.push_front(30);
	v2.push_front(40);
	std::list<int> v90,v80;
	v90.assign(v2.begin(), v2.end());
	for (std::list<int>::iterator it = v90.begin(); it != v90.end(); it++) {
		std::cout << *it << " ";
	}
	v80 = v90;
	for (std::list<int>::iterator it = v80.begin(); it != v80.end(); it++) {
		std::cout << *it << " ";
	}
	v80.assign(10, 90);
	v90.swap(v80);
	for (std::list<int>::iterator it = v90.begin(); it != v90.end(); it++) {
		std::cout << *it << " ";
	}


	//list�����Ĵ�СҲ�Ǹ�vectorһ����,ʹ�������ĸ�����
	//size(),empty(),resize(num),resize(num,elem)

	//ͬ�ϣ�list�����Ĳ���Ҳһ��
	std::list<int> a = { 1,2,3 }, b = { 32,44,90,30 };
	std::list<int>::iterator it = a.begin();
	std::list<int>::iterator it2 = b.begin();
	it++;
	it2++;

	////������δ����
	//a.insert(it, 25);
	//it++;
	//a.insert(it, 3, 35);//���Ϊ1 25 2 35 35 35 3
	//
	// 
	//����������
	it=a.insert(it, 25);
	it++;
	a.insert(it, 3, 35);//���Ϊ1 25 35 35 35 2 3
	b.insert(it2, it, a.end());//���Ϊ32 2 3 44 90 30��ÿ��˼������b{}��2��λ��44������û���µ�����it����ʱitָ��2����ע���ǲ���44λ�õ�ǰ�棡

	for (std::list<int>::iterator it = a.begin(); it !=a.end(); it++) {
		std::cout << *it << " ";
	}
	for (std::list<int>::iterator it = b.begin(); it != b.end(); it++) {
		std::cout << *it << " ";
	}

	//listɾ��+��������
	std::list<int> a = { 1,2,3,4,5,6 };
	std::list<int>::iterator it = a.begin();
	it=a.erase(it);
	std::cout << *it << std::endl;
	for (std::list<int>::iterator it0 = a.begin(); it0 != a.end(); it0++) {
		std::cout << *it0 << " ";
	}
	
	//std::list<int>::reverse_iterator its = a.rbegin();
	//its++; 
	//std::cout <<std::endl;
	//std::cout << *its ;

	//a.erase(its,a.rbegin());�������δ��룬erase���ܽ��ܷ��������

	std::list<int>::iterator ita = it;
	it++; ita++; ita++; ita++;
	std::cout << "\n" << *it << std::endl << *ita;
	a.erase(it, ita);//ɾ��Ҳ������ҿ�
	std::cout << std::endl;

	for (std::list<int>::iterator it0 = a.begin(); it0 != a.end(); it0++) {
		std::cout << *it0 << " ";
	}
	a.remove(6);
	std::cout << "\nremoveɾ��ָ��Ԫ��6��Ϊ��\n";
	for (std::list<int>::iterator it0 = a.begin(); it0 != a.end(); it0++) {
		std::cout << *it0 << " ";
	}
	a.push_back(90);
	a.push_back(21);
	a.reverse();
	std::cout << "\nĩβ����90,21��ת���к�\n";
	for (std::list<int>::iterator it0 = a.begin(); it0 != a.end(); it0++) {
		std::cout << *it0 << " ";
	}

	a.clear();
	std::cout << "\nlist����a�Ƿ�Ϊ��=" << a.empty() << std::endl;
#endif
	//������ʧЧ(������ɾ���Ͳ���)
	//��������ԭ����ţ���ͨ��ָ����ָ���Ӧ���ڴ�ռ�Ĳ���
	//Ұָ����ָ�������������Լ���Χ���ڴ�ռ䣬��ָ��Ŀռ䱻�ͷźͷ����ˣ����������Լ�
	std::list<int> a = { 2,3,4,3,3,7 };
	for (std::list<int>::iterator it0 = a.begin(); it0 != a.end(); it0++) {
		std::cout << *it0 << " ";
	}
	std::cout << std::endl;


	//��ʽ�����������ɾ��ʧЧ����
	for (std::list<int>::iterator is = a. begin(); is != a.end();) {
		if (*is == 3) {
			is = a.erase(is);
		}
		else
		{
			is++;
		}
	}

	for (std::list<int>::iterator it0 = a.begin(); it0 != a.end(); it0++) {
		std::cout << *it0 << " ";
	}
	
	//��֮�����ڵ�����it����ɾ�������У���ɾ���󲻸���ʱ��ָ��λ��ɾ����һԪ�أ����º�ָ��ɾ��Ԫ��ǰһλ��
	//�ڲ�������У�������ʱit��Ȼָ��ԭ��ָ����Ǹ�Ԫ�أ����º�Ϊָ������Ԫ���е�һ��Ԫ��λ��
	std::cout << "\nfuck you !";
	return 0;
}