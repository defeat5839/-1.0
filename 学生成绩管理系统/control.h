#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
class control
{
public:control();
	   ~control();
	   void showmenu();//展示目录
	   void save();//保存数据
	   void find();//查找信息
	   void remove1();//删除学生信息
	   void change();//修改信息
	   void Swap(student*, student*);//学生信息交换，便于排序
	   void sortlist(); //链表排序
	   void listcount();//统计几个人数
	   void check(char m[10]);//检查登录密码
	   void deletemima();//删除登录密码
	   void display();//展示学生信息
	   void Additem(); //添加成员
	   ifstream in;
	   ofstream out;
private:student* Finditem(string name)//按照名字查找学生
{

	for (student* p = head; p->next != end; p = p->next)
		if (name._Equal(p->next->name))
			return p;
	return NULL;
}
		student* FindID(string id)//按照学号查找学生
		{

			for (student* p = head; p->next != end; p = p->next)
				if (id._Equal(p->next->id))
					return p;
			return NULL;
		}
		student* head, * end;

};
void control::display()
{
	student* p;
	for (p = head->next; p != end; p = p->next)
		p->show();
	cout << "输入任意字符！继续~~~";
	_getch();
}
void control::Additem()
{
	end->input();
	end->next = new student;
	end = end->next;
	cout << "添加完成！" << endl;
	cout << "输入任意字符！继续~~~" << endl;
	_getch();
}
control::control()
{
	head = new student;
	head->next = new student;
	end = head->next;
	in.open("sort.txt");
	if (!in)
		cout << "这是一个新系统，" << endl;
	else
	{
		while (!in.eof())
		{
			end->ReadFile(in);
			if (end->name[0] == '\0')
				break;
			end->next = new student;
			end = end->next;
		}
		in.close();
		cout << "读取学生信息成功！" << endl;
	}
}

control::~control()
{
	save();
	for (student* temp; head->next != end; )
	{
		temp = head->next;
		head->next = head->next->next;
		delete temp;
	}
	delete head, end;
}

void control::showmenu()
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
	cout << "*             7.列出及格人数              *" << endl;
	cout << "*             8.管理系统密码              *" << endl;
	cout << "*             0.安全退出系统              *" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "*        注：保存数据需要安全退出系统     *" << endl;

	cout << "\n\t请选择功能：";
}

void control::find()
{
	char name[20];
	string id;
	int x;
	student* p = NULL;
	cout << "--------------------------" << endl;
	cout << "   1.按学生的姓名查找     " << endl;
	cout << "   2.按学生的学号查找     " << endl;
	cout << "--------------------------" << endl;
	cout << "\n\t请选择：";
	cin >> x;
	switch (x)
	{
	case 1: {
		cout << "\t请输入要查找的学生的姓名：";
		cin >> name;
		if (p = Finditem(name))
		{
			p->next->show();
			cout << "输入任意字符，继续……";
			_getch();
		}
		else
		{
			cout << "没有找到该姓名的学生！" << endl;
			cout << "输入任意字符，继续……";
			_getch();
		}
	}break;
	case 2:
	{
		cout << "\t请输入要查找的学生的学号：";
		cin >> id;
		if (p = FindID(id))
		{
			p->next->show();
			cout << "输入任意字符，继续……";
			_getch();
		}
		else
		{
			cout << "没有找到该学号的学生！" << endl;
			cout << "输入任意字符，继续……";
			_getch();
		}
	}
	}
}
void control::change()
{
	char name[20];
	student* p = NULL;
	cout << "请输入要修改的学生的姓名：";
	cin >> name;
	if (p = Finditem(name))
	{
		cout << "已找到该学生信息，请输入新的信息" << endl;
		p->next->input();
		cout << "修改成功！" << endl;
		cout << "输入任意字符，继续……";
		_getch();
	}
	else
	{
		cout << "没有找到该姓名的学生！" << endl;
		cout << "输入任意字符，继续……";
		_getch();
	}
}

void control::remove1()
{
	char name[20];
	student* p = NULL, * temp = NULL;
	cout << "请输入要删除的学生的姓名：";
	cin >> name;
	if (p = Finditem(name))
	{
		temp = p->next;
		p->next = p->next->next;
		delete temp;
		cout << "删除成功！" << endl;
		cout << "输入任意字符，继续……";
		_getch();
	}
	else
	{
		cout << "没有找到该学生！" << endl;
		cout << "输入任意字符，继续……";
		_getch();
	}
}


void control::Swap(student* p1, student* p2)
{

	swap(p1->name, p2->name);
	swap(p1->id, p2->id);
	swap(p1->chinese, p2->chinese);
	swap(p1->english, p2->english);
	swap(p1->math, p2->math);
	swap(p1->sum, p2->sum);
}
void control::listcount()//统计共有多少个学生
{

	int n = 0;
	for (student* p = head->next; p != end; p = p->next)
	{
		if (p->sum >= 180)
		{
			n++;
		}
	}
	cout << "及格人数： " << n << endl;
	cout << "输入任意字符，继续……";
	_getch();
}

//void control::sortlist()//排序方法一
//{
//	cout << "排序中……" << endl;
//	student *p = NULL, *k = NULL;
//	for (p = head->next; p != end; p = p->next)
//		for (k = p->next; k != end; k = k->next)
//	{
//		if (p->sum > k->sum)//按总分排序 从小到大
//		{
//			Swap(p, k);
//		}
//	}
//	cout << "排序完成！" << endl;
//	cout << "输入任意字符，继续……";
//	_getch();
//	return;
//}
void control::sortlist() //链表排序
{
	student* q = head->next;
	student* p = head;
	while (p->next != end)
	{
		q = p->next;
		while (q != end)
		{
			if (p->sum > q->sum)
			{
				Swap(p, q);

			}
			q = q->next;
		}
		p = p->next;
	}
	cout << "排序完成！" << endl;
	cout << "输入任意字符，继续……";
	_getch();
	return;
}
void control::save()
{
	out.open("sort.txt");
	for (student* p = head->next; p != end; p = p->next)
		out << p->name << "\t" << p->id << "\t" << p->chinese << "\t" << p->english << "\t" << p->math << "\t" << p->sum << "\n";
	out.close();
}

void control::check(char m[10])
{
	char buffer[10];
	in.open("mima.txt");
	if (!in)
	{
		cout << "这是一个新系统，请先设置管理员密码！" << endl;
		cout << "请设置管理员密码：";
		cin >> buffer;
		out.open("mima.txt");
		out << buffer << "\n";
		out.close();
	}
	else
	{
		in.getline(buffer, '\n');
		if (!strcmp(buffer, m))
		{
			cout << "验证成功！" << endl;
		}
		else
		{
			cout << "密码错误，即将退出系统！" << endl;
			exit(-1);
		}
		in.close();
	}
}

void control::deletemima()
{
	//char*  c1;
	//c1 = "mima.txt";
	remove("mima.txt");
	//DeleteFile(c1.c_str());
	cout << "删除成功！" << endl;
	_getch();
}
#pragma once
