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
	cout << "��������Ĺ���Ա����(�������ֱ���˳�)��";
	cin >> y;
	control student;
	student.check(y);
	cout << "\t\t\t\t��������������" << endl;
	cout << "\t\t\t\t��ӭ����ѧ���ɼ�����ϵͳ��" << endl;
	cout << "\t\t\t\t��������������" << endl;
	cout << "\n���������ʼ����";
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
			cout << setiosflags(ios::left) << setw(15) << "����" << setiosflags(ios::left) << setw(15) << "ѧ��" << setiosflags(ios::left) << setw(15) << "���ĳɼ�" << setiosflags(ios::left) << setw(15) << "��ѧ�ɼ�" << setiosflags(ios::left) << setw(15) << "Ӣ��ɼ�" << setiosflags(ios::left) << setw(15) << "�ܷ�" << endl;
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
