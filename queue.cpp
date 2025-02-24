#include<iostream>
#include<algorithm>
#include<queue>

int main() {
	//queue队列，FIFO，先进先出，不可遍历
	//入队(队尾添加元素)
	std::queue<int> a;//默认构造函数
	std::queue<int> b(a);//拷贝构造函数
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	b = a;//前面的还没给b赋值
	//front() back()是查看队首和队尾的元素
	std::cout << "初始队列首部元素是：" << a.front() << std::endl;
	std::cout << "初始队列尾部元素是：" << a.back() << std::endl;

	//出队(队头删除元素)
	a.pop();
	std::cout << "队列首部元素出队后首部元素是：" << a.front() << std::endl;
	//通过一边读取队首一边删除队首来访问队列所有元素
	while (b.empty()!=true)
	{
		std::cout << "队列元素是：" << b.front() << std::endl;
		b.pop();
	}

	//empty()和size()函数也适用



	return 0;
}