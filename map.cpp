#include<iostream>
#include<algorithm>
#include<map>
using std::cout;
using std::string;
using std::endl;

class stu {
	//������������������Ԫ����ʵ������Զ����������͡�
	friend std::ostream& operator<<(std::ostream & cout, stu & s);

public:
	stu() {}
	stu(int a, string b) {
		this->id = a;
		this->name = b;
	}
	// ���ó�Ա�����������������p.operator<<(cout)�򻯰汾p << cout
		//һ�����ǲ������ó�Ա����������<<���������Ϊ�޷�ʵ��cout�����
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
	//map�Ǽ�ֵ�ԣ��ɷֱ���������������
	//Ĭ�Ϲ��캯��map<T1,T2> map;
	std::map<int, stu> stus;
	std::map<int, string> maps;
	//����������map�в���Ԫ�صķ�ʽ
	//1:����insert��pair�������洢����ע��pair��ģ���࣬����Ҫ������������
	maps.insert(std::pair<int,string>(120,"wutai"));
	maps.insert(std::pair<int, string>(520, "taisong"));
	std::pair<int, string> asd(250,"wangdefa");
	maps.insert(asd);
	//2:����һ��������value_type()����������
	maps.insert(std::map<int,string>::value_type(999,"wangba"));
	//3:���һ�ֱȽ�����ʵ�֣�ʹ�ø�ֵ�ķ�ʽ��ֵ��ֵ��
	maps[444] = "wusong";
	//�Զ�����������
	stu stu1(888,"lbw");
	stu stu2(21313, "wfwf");
	stus.insert(std::pair<int,stu>(stu1.id,stu1));
	stus[stu2.id] =stu2 ;

	//map�������ı���
	for (std::map<int, string>::iterator it = maps.begin(); it != maps.end(); it++) {
		std::pair<int, string> p = *it;//ȡ����������ֵ������pair����
		cout << p.first << "qian shi xuehao hou shi mingzi" << p.second << endl;
	}
	for (std::map<int, stu>::iterator it = stus.begin(); it != stus.end(); it++) {
		std::pair<int, stu> p = *it;//ȡ����������ֵ������pair����
		int id = p.first;
		stu st = p.second;
		cout << id << " " << st <<endl;//���������õ���<<������������
	}
	cout << maps.size() << endl;
	//maps[key]=value������������ķ�ʽ�����������������и�key��Ὣ��key��value�����ǣ�ʹ��insert�򲻻�

	//��ȡѧ��Ϊ520��ͬѧ������
	string name = maps[520];//��������ʽ�Ĳ��뵼�µĸ������Ƶ����������map��û�ж�Ӧkey�Ķ�����Զ�����һ����key��valueΪ�յĶ���
	cout << name << endl;

	//ʹ��find()����������,������ʹ��string name = maps[520]����ʽ������
	std::map<int, string>::iterator se;
	se = maps.find(5206);//�ⷵ�ص��Ƕ�Ӧkey�ļ�ֵ�Եĵ�����,���������򷵻�end()
	if (se == maps.end()) {
		cout << "i can't do it" << endl;
	}
	else{
		cout << "name is:" << (*se).second << endl;
	}

	return 0;
}