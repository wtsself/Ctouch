#include<iostream>
#include<algorithm>
#include<set>

int main() {
	//set是集合容器，是关联式容器(同map容器)，与前面的序列式容器不同
	//set中元素是唯一的(可以实现去除重复元素的功能)，按照一定顺序排列（升序_默认）,不能指定插入位置，也不能下标和at()访问
	//set是采用红黑树实现，一种自平衡的二叉树
	//multiset与set相比，mutiset可以出现相同的元素
	//set和mutiset中不可直接修改值，要改也只能删除原先的值再添加新的值
#if 0
	std::set<int> a;
	std::multiset<int> b;
	a.insert(1);//因为没有指定位置的插入，所以没有迭代器的插入更新操作
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
	a.swap(c);//内容互换
	a.insert(11);
	a.insert(12);
	for (it = a.begin(); it != a.end(); it++) {
		std::cout << *it << std::endl;
	}
	it = a.begin();
	std::cout << "it指向的元素值为：" << *it << std::endl;//这段代码会报错
	a.erase(it);//erase()的参数只能是迭代器(指针),且只能是正向迭代器,并且此时没有更新迭代器，迭代器指向的内存空间被释放了，变成野指针了，再访问迭代器指向的值会异常
	//std::cout << "it指向的元素值为：" << *it << std::endl;此时无法访问
	
	std::cout << "删除it指向的元素后a的元素有：" << std::endl;
	for (it = a.begin(); it != a.end(); it++) {
		std::cout << *it << std::endl;
	}

	it = a.begin();
	std::cout << "it指向的元素值为：" << *it << std::endl;
	it = a.erase(it);
	std::cout << "继续使用迭代器返回it后，其指向的元素值为：" << *it << std::endl;
	
	std::cout << "删除it指向的元素后a的元素有：" << std::endl;
	for (it = a.begin(); it != a.end(); it++) {
		std::cout << *it << std::endl;
	}
	a.insert(99);
	for (it = a.begin(); it != a.end(); it++) {
		std::cout << *it << std::endl;
	}
	a.erase(102);//删除指定的值，若不存在则返回false
	for (it = a.begin(); it != a.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << "是否还有102：为空？多大？" << a.erase(102)<<a.empty()<<a.size();
	//empty(),clear()和size()函数也适用
#endif


	return 0;
}