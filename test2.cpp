#include<iostream>
#include<fstream>
using namespace std;
//�ı��ļ�д�ļ�
void test01()
{
	//1.����ͷ�ļ�
	//2.����������
	ofstream ofs;
	//3.ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);//�����ָ���ļ�·����Ĭ�Ϻ�����Ŀ���ļ�·��һ��
	//4.д����
	ofs << "����:����" << endl;
	ofs << "�Ա�:��" << endl;
	ofs << "����:18" << endl;
	//5.�ر��ļ�
	ofs.close();
}
int main(void)
{
	test01();
	system("pause");
	return 0;
}

