#include<iostream>
#include<algorithm>
#include<queue>

int main() {
	//queue���У�FIFO���Ƚ��ȳ������ɱ���
	//���(��β���Ԫ��)
	std::queue<int> a;//Ĭ�Ϲ��캯��
	std::queue<int> b(a);//�������캯��
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	b = a;//ǰ��Ļ�û��b��ֵ
	//front() back()�ǲ鿴���׺Ͷ�β��Ԫ��
	std::cout << "��ʼ�����ײ�Ԫ���ǣ�" << a.front() << std::endl;
	std::cout << "��ʼ����β��Ԫ���ǣ�" << a.back() << std::endl;

	//����(��ͷɾ��Ԫ��)
	a.pop();
	std::cout << "�����ײ�Ԫ�س��Ӻ��ײ�Ԫ���ǣ�" << a.front() << std::endl;
	//ͨ��һ�߶�ȡ����һ��ɾ�����������ʶ�������Ԫ��
	while (b.empty()!=true)
	{
		std::cout << "����Ԫ���ǣ�" << b.front() << std::endl;
		b.pop();
	}

	//empty()��size()����Ҳ����



	return 0;
}