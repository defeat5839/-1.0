#include<iostream>
#include<list>
#include<string>
#include<iomanip>
#include<conio.h>
using namespace std;
class student
{
public:
	student()
	{
		name = " ";
		score = 0;
	};

	bool operator<(const student& other)const
	{
		if (score < other.score)
			return true;
		return false;
	}
	void set_name(string temp_name) { name = temp_name; }
	void set_score(double temp_score) { score = temp_score; }
	string get_name() { return this->name; }
	double get_score() { return this->score; }
private:
	string id;
	double score;
	string name;
};

class control
{
public:
	~control();
	student* get_student()
	{
		return li.back();
	}
	void additem()
	{
		cout << "������ ";
		cin >> name;
		cout << "���㣺 ";
		cin >> score;
		li.push_back(new student);
		input(name,score);
		cout << "�밴�����������_��  ";
	}
	void Sort() 
	{
		li.sort();
		cout <<"����ɹ�������"<<endl <<"�밴�����������_��  ";

	}
	void input(string temp_name,double temp_score)
	{
		li.back()->set_name(temp_name);
		li.back()->set_score(temp_score);
	}
	void output() 
	{
		list<student*>::iterator it;
		for ( it = li.begin(); it != li.end(); it++)
		{
			cout << setiosflags(ios::left) << setw(10) << (*it)->get_name() << setiosflags(ios::left) << setw(10) << (*it)->get_score() << endl;
		}
		cout << "�밴�����������_��  ";

	}
	void showmenu() 
	{
		cout << "-------------------------------------------" << endl;
		cout << "          ��ӭ����ѧ���ɼ�����ϵͳ               " << endl;
		cout << "-------------------------------------------" << endl;
		cout << "*             1.����ѧ���ɼ�              *" << endl;
		cout << "*             2.��ʾѧ���ɼ�              *" << endl;
		cout << "*             3.����ͳ�Ƴɼ�              *" << endl;
		cout << "*             4.����ѧ���ɼ�              *" << endl;
		cout << "*             5.ɾ��ѧ���ɼ�              *" << endl;
		cout << "*             6.�޸�ѧ���ɼ�              *" << endl;
		cout << "*             0.��ȫ�˳�ϵͳ              *" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "*        ע������������Ҫ��ȫ�˳�ϵͳ     *" << endl;
		cout << "\n\t��ѡ���ܣ�";
	};
	int deletemessage()//�������ֲ���ѧ��
	{
		cout << "������ѧ���������� ";
		cin >> name;
		list<student*>::iterator it;
		for (it = li.begin(); it != li.end(); it++)
		{
			if (name._Equal((*it)->get_name()))
			{
				li.erase(it);
				cout << "ɾ���ɹ�������"<<endl<< "�밴�����������_��  ";
				return 0;
			}
		}
		cout << "û�����ѧ������Ϣ��_��" << endl << "�밴�����������_��  ";
		return 0;
	}
	int changemessage()
	{
		double temp_score;
		cout << "������ѧ���������� ";
		cin >> name;
		list<student*>::iterator it;
		for (it = li.begin(); it != li.end(); it++)
		{
			if (name._Equal((*it)->get_name()))
			{
				cout << "������Ҫ�޸ĵļ�����ֵ�� ";
				cin >> temp_score;
				(*it)->set_score(temp_score);
				cout << "�޸ĳɹ�������" << endl << "�밴�����������_��  ";
				return 0;
			}
		}
		cout << "û�����ѧ������Ϣ��_��" << endl << "�밴�����������_��  ";
		return 0;
	}
	int findstudent()
	{
		cout << "������ѧ���������� ";
		cin >> name;
		list<student*>::iterator it;
		for (it = li.begin(); it != li.end(); it++)
		{
			if (name._Equal((*it)->get_name()))
			{
				cout << setiosflags(ios::left) << setw(10) << (*it)->get_name() << setiosflags(ios::left) << setw(10) << (*it)->get_score() << endl;
				cout << "�밴�����������_��  ";
				return 0;
			}
		}
		cout << "û�����ѧ������Ϣ��_��" << endl << "�밴�����������_��  ";
		return 0;
	}
private:
	list<student*> li;
	string name;
	double score;
};
control::~control()
{
	li.clear();
}
int main()
{
	int x, i = 0;
	bool isquit = false;
	control student;
	while (!isquit)
	{
		system("cls");
		student.showmenu();
		cin >> x;
		switch (x)
		{
		case 0:isquit = true; break;
		case 1:student.additem();_getch(); break;
		case 2:cout << setiosflags(ios::left) << setw(10) << "����" << setiosflags(ios::left) << setw(10) << "����" << endl;
			   student.output(); _getch();	 break;
		case 3:student.Sort(); _getch(); break;
		case 4:student.findstudent(); _getch(); break;
		case 5:student.deletemessage();_getch(); break;
		case 6:student.changemessage(); _getch(); break;
		}
	}
	return 0;
}
