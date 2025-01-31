#include <iostream>
#include<string>
using namespace std;
	class parent {
	public:
		virtual string name () = 0;
		//virtual ~parent() = 0;
		string pa_name() {

			return "吴远波";
		}
		virtual ~parent() = 0;
	};
	
	parent::~parent() {
		cout << "这是父类的纯虚析构函数，不需要子类实现" << endl;
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
				cout << "这是子类的析构函数，说明父类指针释放调用了子类的析构函数，并且先释放子类再释放父类" << endl;
				delete m_name;
				m_name = NULL;

			}
		}
		string* m_name;
	};

class dauter :public parent {
public:
	virtual string name() {
		return "吴婷菲";
	}
};

void main() {
	parent* par = new son("250");
	cout<< par->name() << endl;
	parent* par1 = new dauter;
	cout << par1->name() << endl;
	delete par, par1;
	 
	//引用
	son s1("520");
	parent & a = s1;
	cout << a.pa_name()<< endl;
	cout << a.name() << endl;
	dauter s2;
	parent& b = s2;
	cout << s2.name() << endl;


	system("pause");

}



	



