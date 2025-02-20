#include<iostream>
#include<vector>
#include<algorithm>

template<class T>
void myprint(T n) {
	std::cout << n << " ";
}

//代码要一边看一边敲，光看不敲等于不学
int main() {
#if 0
//#include<iostream>
//#include<vector>
//#include<algorithm>
//	template<class T>//for_each函数的通用迭代输出函数
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
//			std::cout << *ite << " ";//迭代器可以看成一种指针
//		}
//		std::cout << std::endl;
//		a = 2;
//
//		return 0;
//	}
	//构造
	int arry[] = { 1,2,3,4,5 };
	std::vector<int> v1(arry, arry + 5);
	std::vector<int> v2(3, 9);
	std::vector<int> v3(v1);
	for (std::vector<int>::iterator ite = v1.begin(); ite != v1.end(); ite++) {
		std::cout << *ite << std::endl;
	}
	std::for_each(v3.begin(), v3.end(), myprint<int>);
	std::cout << "\n";

	//赋值
	int arry[] = { 1,2,3,4,5 };
	std::vector<int> s1, s2, s3;
	s1.assign(arry, arry + 5);
	s2.assign(s1.begin(), s1.end());
	for (int i = 0; i < s2.size(); i++) {
		std::cout << s2[i] << " ";
	}
	s3.assign(5, 10);
	s3.swap(s2);
	std::cout << "上面的互换后（swap）" << std::endl;
	for (int i = 0; i < s2.size(); i++) {
		std::cout << s2[i] << " ";
	}
	s2 = s3;//=运算符重载


	//大小
	std::vector<int> f1;
	std::cout << f1.size() << std::endl;
	if (f1.empty()) {
		std::cout << "f1容器是空的";
	}
	f1.assign(5, 1);
	f1.resize(10);//指定容器大小后在变长会把默认值放在空位置处，变短则删除后面的值，resize（n,m），第二个参数为指定的默认值
	std::for_each(f1.begin(), f1.end(), myprint<int>);

	//访问
	std::vector<std::string> s2(5, "wutaisong");
	for (int i = 0; i < s2.size(); i++) {
		std::cout << s2[i] << " ";//s2[10],下标访问越界可能会导致程序异常终止
	}
	s2.at(10);//使用at（）函数越界时抛出异常

	//插入
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
	//指定位置插入数据
	s2.insert(s2.begin() + 4, 999);//第一个参数为指针，不为下标
	std::for_each(s2.begin(), s2.end(), myprint<int>);
	std::cout << "\n";
	//指定位置插入多个数据
	s2.insert(s2.begin() + 4, 3, 90);
	std::for_each(s2.begin(), s2.end(), myprint<int>);
	std::cout << "\n";
	//指定位置插入指定区间的数据
	int a[] = { 1,2,3,4,5,6,6,7 };
	s2.insert(s2.begin() + 2, a + 1, a + 8);
	std::for_each(s2.begin(), s2.end(), myprint<int>);
	std::cout << "\n";

	int v[5] = { 10,20,30,40,50 };
	std::vector<int> r1(v + 2, v + 5);//30，40，50
	s2.insert(s2.begin() + 1, r1.begin() + 1, r1.end());//40.50插进s2第一个元素后的位置，begin()函数是首地址，不是首个元素，因此s2.begin() + 1不是从第二元素位置插进去
	std::for_each(s2.begin(), s2.end(), myprint<int>);
	std::cout << "\n"<<s2.size();
	//迭代器统一了对所有容器的访问方式，迭代器本质是指针（不严谨），也是类中类，vector<int>::iterator ite,ite为变量名，对象，指针
	//迭代器失效处理--vs会程序异常终止
	//插入后导致迭代器失效
	std::vector<int> v1(5, 2);
	//std::cout << v1[15] << std::endl;
	//v1[15] = 100;//访问越界可能会修改内存值
	//std::cout << v1[15] << std::endl;
	std::vector<int>::iterator ite;
	ite = v1.begin() + 4;
	//v1.insert(v1.begin() + 4, 8);//这里插入使原来数组的空间被释放掉了，深拷贝到内存其它空间，导致ite指针变成了野指针，正常情况下ite指向的值应该为8
	//std::cout <<*ite;
	ite = v1.insert(v1.begin() + 4, 8);//在插入中使用迭代器，要重新用插入的返回值重新赋值--该操作更新迭代器
	std::cout << *ite;

	//删除元素后导致迭代器失效
	std::vector<int> v1 = { 1,2,3,3,3,3,3,4,5 };
	for (std::vector<int>::iterator ite = v1.begin(); ite != v1.end(); ) {
		if (*ite == 3) {
			ite=v1.erase(ite);//更新迭代器
		}
		else {
			ite++;//这里吧for中的++移到这里是为了能够在删除一个元素后，该元素后的元素位置前移（vector动态特性），ite能够继续在该位置上判断
		}
	}
	for (std::vector<int>::iterator ite = v1.begin(); ite != v1.end(); ite++) {
		std::cout << *ite << std::endl;
	}
#endif
	//deque（双向数组，跟vector容器有很多相似之处，都是动态数组）
	//deque的在扩容时的数据不是完全连续的，通过[]运算符重载找到数据，而vector是连续的数据存储空间，理论上vector的效率更高
	//deque特有的头插和头删，push_front(),pop_front()
	//需要频繁使用头插时才用deque，不用vector





	std::cout << "\nfuck you !";
	return 0;
}