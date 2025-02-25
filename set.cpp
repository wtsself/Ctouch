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


//伪函数(一个类或结构体，重载了operator()函数,常用于自定义的比较，排序和映射)
class stu_fun {
public://类的默认访问权限是 private，而 结构体（struct）的默认访问权限是 public
	bool operator()(const stu &s1,const stu &s2) const{
		return s1.m_id < s2.m_id;//升序排序
	}
};



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

	
	
	//DC::ass as;
	//cout<< as.fun(2, 3, fun1);这段代码fun1识别不到，命名空间内存在访问函数指针问题

	



	std::set<int,std::less<int>> s1;//升序排列，less<int>是模版类，默认为升序排列
	std::set<int, std::greater<int>> s2;//降序排列
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
	//讲一下函数指针
	/*
int x;      // x是一个int型的变量
int *x;     // x是一个指向int型变量的指针
int *x();   // x是一个返回int型指针的函数
int (*x)(); // x是一个函数指针，输入参数为空，返回类型为int型指针
例如:	
int array[5];      // array是一个指向int的指针常量
int *p = array;    // p是一个指向int的指针变量，p = array合法
p[3];              // 等价于array[3]
 
void test(int a){ cout << "a=" << a << endl;}  // test是一个函数指针常量，输入参数int，返回类型void
void (*pf)(int);   // 声明函数指针pf： pf是一个输入参数int，返回void的函数的指针
pf = test;         // 将test函数地址赋值给pf（二者输入参数列表、返回类型必须一致）
pf(123);           // 等价于test(123)
	
	*/
	//函数指针指向的是函数名，也就是函数地址，此时指针就相当于函数名，调用指针就是调用函数
	cout << "9 and 9 + equl :" << fun(9, 9, fun1) << endl;
	cout << "9 and 9 * equl :" << fun(9, 9, fun2) << endl;
	
	//搞不懂，代码出现问题了
	//注意一个致命的细节：
	//在C++中，函数不能嵌套定义。也就是说，你不能在一个函数内部定义另一个函数。在你的代码中，abc()函数被定义在main()函数内部，这是不合法的，因此编译器会报错。

	//定义一个容器实现村出纳学生的信息，并按照仿函数中自定义的的排序规则排序
	std::set<stu, stu_fun> a1;
	a1.insert(stu(16,"太松"));
	a1.insert(stu(23, "太松"));
	a1.insert(stu(11, "太松"));
	std::set<stu, stu_fun>::iterator it;
	for (it = a1.begin(); it != a1.end(); it++) {
		cout << "id :" << it->m_id << " " << "name:" << it->m_name << endl;
	}
#endif
	//查找
	std::set<int> a;
	a.insert(1);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	std::set<int>::iterator it;
	it = a.find(3);
	cout << "find 3 yes or no:" << *it << endl;
	//找不到指定元素时，返回end（）
	it = a.find(2);
	if (it == a.end()) {
		cout << " i can't find it" << endl;
	}
	else {
		cout << *it << endl;
	}
	//a.count(elem)返回容器州中elem值的个数，又因为在set中元素唯一，所以可以判断是否存在该元素，在mutiset中则可以知道个数

	//lower_bound(elem)查找第一个大于等于elem的元素
	it = a.lower_bound(3);
	cout << "should be 3:" << *it << endl;
	//upper_bound(elem)查找第一个大于elem的元素
	it = a.upper_bound(4);
	cout << "should be 5:" << *it << endl;
	return 0;
}