
#include<iostream>
#include<list>
#include<algorithm>



//代码要一边看一边敲，光看不敲等于不学
int main() {
#if 0
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
	std::cout << " \n";
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

	//list容器的迭代器是双向迭代器（list双向链表），iterator是正向迭代器，而reverse_iterator是反向迭代器
	//rebegin(),rend()是反向的第一个和最后一的下一个元素
	std::list<int> v1;
	v1.push_back(10);
	v1.push_front(20);
	v1.push_front(30);//30,20,10

	//反向读取
	for (std::list<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++) {
		std::cout << *it << " ";
	}

	//构造方法
	std::list<int> v1(3,5);//(n,m)构造n个m到list里面
	for (std::list<int>::iterator it = v1.begin(); it != v1.end(); it++){
		std::cout << *it << " ";
	}
	std::list<int> v2;
	v2.push_back(10);
	v2.push_front(20);
	v2.push_front(30);
	v2.push_front(40);//40,30,20,10
	//list的区间构造是左闭右开[n,m+1)
	//不支持std::list<int> v3(v2.begin()+1,v2.begin()+2);的构造，不能+n
	//比较麻烦
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
	//常用拷贝构造
	std::list<int> v4(v2);
	for (std::list<int>::iterator it = v4.begin(); it != v4.end(); it++) {
		std::cout << *it << " ";
	}

	//赋值，assign()函数赋值都是覆盖赋值
	//同vector一样的赋值方法,v1.assign(n,m);将n到m-1的区间内容赋值
	//v1.assign(n,m)，两参数为数字时则将n个m赋值到list
	//=号运算符重载
	//swap()函数互换内容
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


	//list容器的大小也是跟vector一样的,使用以下四个函数
	//size(),empty(),resize(num),resize(num,elem)
#endif
	//同上，list容器的插入也一样
	std::list<int> a = { 1,2,3 }, b = { 32,44,90,30 };
	std::list<int>::iterator it = a.begin();
	std::list<int>::iterator it2 = b.begin();
	it++;
	it2++;

	////迭代器未更新
	//a.insert(it, 25);
	//it++;
	//a.insert(it, 3, 35);//输出为1 25 2 35 35 35 3
	//
	// 
	//迭代器更新
	it=a.insert(it, 25);
	it++;
	a.insert(it, 3, 35);//输出为1 25 35 35 35 2 3
	b.insert(it2, it, a.end());//输出为32 2 3 44 90 30，每日思考，在b{}的2号位置44处插入没更新迭代器it（此时it指向2），注意是插向44位置的前面！

	for (std::list<int>::iterator it = a.begin(); it !=a.end(); it++) {
		std::cout << *it << " ";
	}
	for (std::list<int>::iterator it = b.begin(); it != b.end(); it++) {
		std::cout << *it << " ";
	}






	std::cout << "\nfuck you !";
	return 0;
}