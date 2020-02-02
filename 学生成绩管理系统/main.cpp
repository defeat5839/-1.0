#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include "student.h"
#include "control.h"
using namespace std;
int main()
{
	int x, i = 0;
	char y[10];
	bool isquit = false;
	cout << "请输入你的管理员密码(密码错误将直接退出)：";
	cin >> y;
	control student;
	student.check(y);
	cout << "\t\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆" << endl;
	cout << "\t\t\t\t欢迎进入学生成绩管理系统！" << endl;
	cout << "\t\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆" << endl;
	cout << "\n按任意键开始……";
	_getch();
	while (!isquit)
	{
		system("cls");
		student.showmenu();
		cin >> x;
		switch (x)
		{
		case 0:isquit = true; break;
		case 1:student.Additem(); break;
		case 2:
			cout << setiosflags(ios::left) << setw(15) << "姓名" << setiosflags(ios::left) << setw(15) << "学号" << setiosflags(ios::left) << setw(15) << "语文成绩" << setiosflags(ios::left) << setw(15) << "数学成绩" << setiosflags(ios::left) << setw(15) << "英语成绩" << setiosflags(ios::left) << setw(15) << "总分" << endl;
			student.display(); break;
		case 3:student.sortlist(); break;
		case 4:student.find(); break;
		case 5:student.remove1(); break;
		case 6:student.change(); break;
		case 7:student.listcount(); break;
		case 8:student.deletemima(); break;
		}
	}
	return 0;
}
