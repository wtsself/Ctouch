#include<iostream>
#include<algorithm>
#include<stack>

int main() {
#if 0
	//栈（没有迭代器，不能遍历）
	//先进后出
	std::stack<int> stk;//默认构造方法
	//入栈
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	//出栈（即删除）
	stk.pop();//没有返回值
	/*stk.pop();
	stk.pop();
	stk.pop();
	栈元素为空时，top()函数访问栈顶元素时会异常
	*/
	std::cout << "栈顶元素为：" << stk.top() << std::endl;
	//依次访问栈顶并出栈
	while (stk.empty()!=true)
	{
		std::cout << "栈顶元素为：" << stk.top() << std::endl;
		stk.pop();
	}

#endif
	std::stack<int> stk;//默认构造方法
	//入栈
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	std::stack<int> stk1(stk);//拷贝构造方法

	std::stack<int> stk2=stk;//此时任然是在调用拷贝构造函数，因为这是在构造函数的过程中
	 
	stk2 = stk;//在构造完毕后，这时才是用的=运算符重载
	//empty()和size()函数也适用
	std::cout << "数组stk的大小和是否为空" << stk.size() << stk.empty() << std::endl;


















	return 0;
}