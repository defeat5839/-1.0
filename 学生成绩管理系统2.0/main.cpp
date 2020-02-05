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
		cout << "姓名： ";
		cin >> name;
		cout << "绩点： ";
		cin >> score;
		li.push_back(new student);
		input(name,score);
		cout << "请按任意键继续·_·  ";
	}
	void Sort() 
	{
		li.sort();
		cout <<"排序成功！！！"<<endl <<"请按任意键继续·_·  ";

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
		cout << "请按任意键继续·_·  ";

	}
	void showmenu() 
	{
		cout << "-------------------------------------------" << endl;
		cout << "          欢迎进入学生成绩管理系统               " << endl;
		cout << "-------------------------------------------" << endl;
		cout << "*             1.增加学生成绩              *" << endl;
		cout << "*             2.显示学生成绩              *" << endl;
		cout << "*             3.排序统计成绩              *" << endl;
		cout << "*             4.查找学生成绩              *" << endl;
		cout << "*             5.删除学生成绩              *" << endl;
		cout << "*             6.修改学生成绩              *" << endl;
		cout << "*             0.安全退出系统              *" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "*        注：保存数据需要安全退出系统     *" << endl;
		cout << "\n\t请选择功能：";
	};
	int deletemessage()//按照名字查找学生
	{
		cout << "请输入学生的姓名： ";
		cin >> name;
		list<student*>::iterator it;
		for (it = li.begin(); it != li.end(); it++)
		{
			if (name._Equal((*it)->get_name()))
			{
				li.erase(it);
				cout << "删除成功！！！"<<endl<< "请按任意键继续·_·  ";
				return 0;
			}
		}
		cout << "没有这个学生的信息·_·" << endl << "请按任意键继续·_·  ";
		return 0;
	}
	int changemessage()
	{
		double temp_score;
		cout << "请输入学生的姓名： ";
		cin >> name;
		list<student*>::iterator it;
		for (it = li.begin(); it != li.end(); it++)
		{
			if (name._Equal((*it)->get_name()))
			{
				cout << "请输入要修改的绩点数值： ";
				cin >> temp_score;
				(*it)->set_score(temp_score);
				cout << "修改成功！！！" << endl << "请按任意键继续·_·  ";
				return 0;
			}
		}
		cout << "没有这个学生的信息·_·" << endl << "请按任意键继续·_·  ";
		return 0;
	}
	int findstudent()
	{
		cout << "请输入学生的姓名： ";
		cin >> name;
		list<student*>::iterator it;
		for (it = li.begin(); it != li.end(); it++)
		{
			if (name._Equal((*it)->get_name()))
			{
				cout << setiosflags(ios::left) << setw(10) << (*it)->get_name() << setiosflags(ios::left) << setw(10) << (*it)->get_score() << endl;
				cout << "请按任意键继续·_·  ";
				return 0;
			}
		}
		cout << "没有这个学生的信息·_·" << endl << "请按任意键继续·_·  ";
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
		case 2:cout << setiosflags(ios::left) << setw(10) << "姓名" << setiosflags(ios::left) << setw(10) << "绩点" << endl;
			   student.output(); _getch();	 break;
		case 3:student.Sort(); _getch(); break;
		case 4:student.findstudent(); _getch(); break;
		case 5:student.deletemessage();_getch(); break;
		case 6:student.changemessage(); _getch(); break;
		}
	}
	return 0;
}
