#include<iostream>
#include<algorithm>
#include<stack>

int main() {
#if 0
	//ջ��û�е����������ܱ�����
	//�Ƚ����
	std::stack<int> stk;//Ĭ�Ϲ��췽��
	//��ջ
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	//��ջ����ɾ����
	stk.pop();//û�з���ֵ
	/*stk.pop();
	stk.pop();
	stk.pop();
	ջԪ��Ϊ��ʱ��top()��������ջ��Ԫ��ʱ���쳣
	*/
	std::cout << "ջ��Ԫ��Ϊ��" << stk.top() << std::endl;
	//���η���ջ������ջ
	while (stk.empty()!=true)
	{
		std::cout << "ջ��Ԫ��Ϊ��" << stk.top() << std::endl;
		stk.pop();
	}

#endif
	std::stack<int> stk;//Ĭ�Ϲ��췽��
	//��ջ
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	std::stack<int> stk1(stk);//�������췽��

	std::stack<int> stk2=stk;//��ʱ��Ȼ���ڵ��ÿ������캯������Ϊ�����ڹ��캯���Ĺ�����
	 
	stk2 = stk;//�ڹ�����Ϻ���ʱ�����õ�=���������
	//empty()��size()����Ҳ����
	std::cout << "����stk�Ĵ�С���Ƿ�Ϊ��" << stk.size() << stk.empty() << std::endl;


















	return 0;
}