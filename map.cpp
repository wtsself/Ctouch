#include<iostream>
#include<algorithm>
#include<map>
using std::cout;
using std::string;
using std::endl;

class stu {
	//重载左移运算符配合友元可以实现输出自定义数据类型。
	friend std::ostream& operator<<(std::ostream & cout, stu & s);

public:
	stu() {}
	stu(int a, string b) {
		this->id = a;
		this->name = b;
	}
	// 利用成员函数重载左移运算符p.operator<<(cout)简化版本p << cout
		//一般我们不会利用成员函数来重载<<运算符，以为无法实现cout在左边
		/*void operator<<(ostream &cout,Person &p)
		{
			cout << p.m_A << endl;
			cout << p.m_B << endl;
		}*/

public:
	int id;
	string name;
};
std::ostream& operator << (std::ostream & cout, stu & s) {
	cout << s.id << " ";
	cout << s.name << endl;
	return cout;
}

int main() {
	//map是键值对，可分别存放两种数据类型
	//默认构造函数map<T1,T2> map;
	std::map<int, stu> stus;
	std::map<int, string> maps;
	//以下是三种map中插入元素的方式
	//1:利用insert加pair对组来存储对象，注意pair是模板类，所以要声明参数类型
	maps.insert(std::pair<int,string>(120,"wutai"));
	maps.insert(std::pair<int, string>(520, "taisong"));
	std::pair<int, string> asd(250,"wangdefa");
	maps.insert(asd);
	//2:还有一种是利用value_type()来传入数据
	maps.insert(std::map<int,string>::value_type(999,"wangba"));
	//3:最后一种比较容易实现，使用赋值的方式赋值键值对
	maps[444] = "wusong";
	//自定义数据类型
	stu stu1(888,"lbw");
	stu stu2(21313, "wfwf");
	stus.insert(std::pair<int,stu>(stu1.id,stu1));
	stus[stu2.id] =stu2 ;

	//map迭代器的遍历
	for (std::map<int, string>::iterator it = maps.begin(); it != maps.end(); it++) {
		std::pair<int, string> p = *it;//取出迭代器的值并传入pair对组
		cout << p.first << "qian shi xuehao hou shi mingzi" << p.second << endl;
	}
	for (std::map<int, stu>::iterator it = stus.begin(); it != stus.end(); it++) {
		std::pair<int, stu> p = *it;//取出迭代器的值并传入pair对组
		int id = p.first;
		stu st = p.second;
		cout << id << " " << st <<endl;//这里特意用到了<<输出运算符重载
	}
	cout << maps.size() << endl;
	//maps[key]=value的类似于数组的方式插入存在如果容器内有该key则会将该key的value给覆盖，使用insert则不会

	//获取学号为520的同学的名字
	string name = maps[520];//与数组形式的插入导致的覆盖相似的情况，访问map里没有对应key的对象会自动创建一个该key的value为空的对象
	cout << name << endl;

	//使用find()函数来访问,不建议使用string name = maps[520]的形式来访问
	std::map<int, string>::iterator se;
	se = maps.find(5206);//这返回的是对应key的键值对的迭代器,若不存在则返回end()
	if (se == maps.end()) {
		cout << "i can't do it" << endl;
	}
	else{
		cout << "name is:" << (*se).second << endl;
	}

	return 0;
}