#include <iostream>
#include<string>
using namespace std;
	class parent {
	public:
		virtual string name () = 0;
		//virtual ~parent() = 0;
		string pa_name() {

			return "��Զ��";
		}
		virtual ~parent() = 0;
	};
	
	parent::~parent() {
		cout << "���Ǹ���Ĵ�����������������Ҫ����ʵ��" << endl;
	}

	class son : public parent {
	public:
		virtual string name() {
			return *m_name;
		}
		son(string name) {

			this->m_name = new string(name);
		}
		~son() {
			if (m_name != NULL) {
				cout << "�������������������˵������ָ���ͷŵ���������������������������ͷ��������ͷŸ���" << endl;
				delete m_name;
				m_name = NULL;

			}
		}
		string* m_name;
	};

class dauter :public parent {
public:
	virtual string name() {
		return "���÷�";
	}
};

void main() {
	parent* par = new son("250");
	cout<< par->name() << endl;
	parent* par1 = new dauter;
	cout << par1->name() << endl;
	delete par, par1;
	 
	//����
	son s1("520");
	parent & a = s1;
	cout << a.pa_name()<< endl;
	cout << a.name() << endl;
	dauter s2;
	parent& b = s2;
	cout << s2.name() << endl;


	system("pause");

}



	



