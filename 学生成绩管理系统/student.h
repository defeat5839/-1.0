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
			cout << "������ѧ��������";
			cin >> name;
			cout << "������ѧ��ѧ�ţ�";
			cin >> id;
			cout << "���������ĳɼ���";
			cin >> chinese;
			cout << "��������ѧ�ɼ���";
			cin >> math;
			cout << "������Ӣ��ɼ���";
			cin >> english;
			sum = chinese + math + english;
		}
		void ReadFile(istream& in)//�ļ�д��
		{
			in >> name >> id >> chinese >> math >> english >> sum;
		}
		void show()
		{
			cout << setiosflags(ios::left) << setw(15) << name << setiosflags(ios::left) << setw(15) << id << setiosflags(ios::left) << setw(15) << chinese << setiosflags(ios::left) << setw(15) << math << setiosflags(ios::left) << setw(15) << english << setiosflags(ios::left) << setw(15) << sum << endl;
		}
};