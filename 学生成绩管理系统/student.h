#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include<windows.h>
#include<iomanip>
using namespace std;
class student
{
public: char name[20];
		string id;
		int chinese;
		int math;
		int english;
		int sum;
		student* next;
		void input()
		{
			cout << "请输入学生姓名：";
			cin >> name;
			cout << "请输入学生学号：";
			cin >> id;
			cout << "请输入语文成绩：";
			cin >> chinese;
			cout << "请输入数学成绩：";
			cin >> math;
			cout << "请输入英语成绩：";
			cin >> english;
			sum = chinese + math + english;
		}
		void ReadFile(istream& in)//文件写入
		{
			in >> name >> id >> chinese >> math >> english >> sum;
		}
		void show()
		{
			cout << setiosflags(ios::left) << setw(15) << name << setiosflags(ios::left) << setw(15) << id << setiosflags(ios::left) << setw(15) << chinese << setiosflags(ios::left) << setw(15) << math << setiosflags(ios::left) << setw(15) << english << setiosflags(ios::left) << setw(15) << sum << endl;
		}
};