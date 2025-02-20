
#include<iostream>
#include<list>
#include<algorithm>



//代码要一边看一边敲，光看不敲等于不学
int main() {
	//list是双向链表，适合于大量的插入删除操作，不能用随机存取操作如[],at()，也不能（+常数），但可以++和--
	std::list<int> v1;
	//头尾的插入和删除
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
	std::cout << "\n" << v1.front() << "首个节点" << std::endl;
	std::cout << v1.back() << "末尾节点" << std::endl;
	v1.front() = 20;
	v1.back() = 90;
	std::cout << v1.front() << "修改首个节点" << std::endl;
	std::cout << v1.back() << "修改末尾节点" << std::endl;
	//stack栈和queue队列是不可遍历的







	std::cout << "\nfuck you !";
	return 0;
}