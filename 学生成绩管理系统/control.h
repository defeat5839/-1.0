#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
class control
{
public:control();
	   ~control();
	   void showmenu();//չʾĿ¼
	   void save();//��������
	   void find();//������Ϣ
	   void remove1();//ɾ��ѧ����Ϣ
	   void change();//�޸���Ϣ
	   void Swap(student*, student*);//ѧ����Ϣ��������������
	   void sortlist(); //��������
	   void listcount();//ͳ�Ƽ�������
	   void check(char m[10]);//����¼����
	   void deletemima();//ɾ����¼����
	   void display();//չʾѧ����Ϣ
	   void Additem(); //��ӳ�Ա
	   ifstream in;
	   ofstream out;
private:student* Finditem(string name)//�������ֲ���ѧ��
{

	for (student* p = head; p->next != end; p = p->next)
		if (name._Equal(p->next->name))
			return p;
	return NULL;
}
		student* FindID(string id)//����ѧ�Ų���ѧ��
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
	cout << "���������ַ�������~~~";
	_getch();
}
void control::Additem()
{
	end->input();
	end->next = new student;
	end = end->next;
	cout << "�����ɣ�" << endl;
	cout << "���������ַ�������~~~" << endl;
	_getch();
}
control::control()
{
	head = new student;
	head->next = new student;
	end = head->next;
	in.open("sort.txt");
	if (!in)
		cout << "����һ����ϵͳ��" << endl;
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
		cout << "��ȡѧ����Ϣ�ɹ���" << endl;
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
	cout << "          ��ӭ����ѧ���ɼ�����ϵͳ               " << endl;
	cout << "-------------------------------------------" << endl;
	cout << "*             1.����ѧ���ɼ�              *" << endl;
	cout << "*             2.��ʾѧ���ɼ�              *" << endl;
	cout << "*             3.����ͳ�Ƴɼ�              *" << endl;
	cout << "*             4.����ѧ���ɼ�              *" << endl;
	cout << "*             5.ɾ��ѧ���ɼ�              *" << endl;
	cout << "*             6.�޸�ѧ���ɼ�              *" << endl;
	cout << "*             7.�г���������              *" << endl;
	cout << "*             8.����ϵͳ����              *" << endl;
	cout << "*             0.��ȫ�˳�ϵͳ              *" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "*        ע������������Ҫ��ȫ�˳�ϵͳ     *" << endl;

	cout << "\n\t��ѡ���ܣ�";
}

void control::find()
{
	char name[20];
	string id;
	int x;
	student* p = NULL;
	cout << "--------------------------" << endl;
	cout << "   1.��ѧ������������     " << endl;
	cout << "   2.��ѧ����ѧ�Ų���     " << endl;
	cout << "--------------------------" << endl;
	cout << "\n\t��ѡ��";
	cin >> x;
	switch (x)
	{
	case 1: {
		cout << "\t������Ҫ���ҵ�ѧ����������";
		cin >> name;
		if (p = Finditem(name))
		{
			p->next->show();
			cout << "���������ַ�����������";
			_getch();
		}
		else
		{
			cout << "û���ҵ���������ѧ����" << endl;
			cout << "���������ַ�����������";
			_getch();
		}
	}break;
	case 2:
	{
		cout << "\t������Ҫ���ҵ�ѧ����ѧ�ţ�";
		cin >> id;
		if (p = FindID(id))
		{
			p->next->show();
			cout << "���������ַ�����������";
			_getch();
		}
		else
		{
			cout << "û���ҵ���ѧ�ŵ�ѧ����" << endl;
			cout << "���������ַ�����������";
			_getch();
		}
	}
	}
}
void control::change()
{
	char name[20];
	student* p = NULL;
	cout << "������Ҫ�޸ĵ�ѧ����������";
	cin >> name;
	if (p = Finditem(name))
	{
		cout << "���ҵ���ѧ����Ϣ���������µ���Ϣ" << endl;
		p->next->input();
		cout << "�޸ĳɹ���" << endl;
		cout << "���������ַ�����������";
		_getch();
	}
	else
	{
		cout << "û���ҵ���������ѧ����" << endl;
		cout << "���������ַ�����������";
		_getch();
	}
}

void control::remove1()
{
	char name[20];
	student* p = NULL, * temp = NULL;
	cout << "������Ҫɾ����ѧ����������";
	cin >> name;
	if (p = Finditem(name))
	{
		temp = p->next;
		p->next = p->next->next;
		delete temp;
		cout << "ɾ���ɹ���" << endl;
		cout << "���������ַ�����������";
		_getch();
	}
	else
	{
		cout << "û���ҵ���ѧ����" << endl;
		cout << "���������ַ�����������";
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
void control::listcount()//ͳ�ƹ��ж��ٸ�ѧ��
{

	int n = 0;
	for (student* p = head->next; p != end; p = p->next)
	{
		if (p->sum >= 180)
		{
			n++;
		}
	}
	cout << "���������� " << n << endl;
	cout << "���������ַ�����������";
	_getch();
}

//void control::sortlist()//���򷽷�һ
//{
//	cout << "�����С���" << endl;
//	student *p = NULL, *k = NULL;
//	for (p = head->next; p != end; p = p->next)
//		for (k = p->next; k != end; k = k->next)
//	{
//		if (p->sum > k->sum)//���ܷ����� ��С����
//		{
//			Swap(p, k);
//		}
//	}
//	cout << "������ɣ�" << endl;
//	cout << "���������ַ�����������";
//	_getch();
//	return;
//}
void control::sortlist() //��������
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
	cout << "������ɣ�" << endl;
	cout << "���������ַ�����������";
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
		cout << "����һ����ϵͳ���������ù���Ա���룡" << endl;
		cout << "�����ù���Ա���룺";
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
			cout << "��֤�ɹ���" << endl;
		}
		else
		{
			cout << "������󣬼����˳�ϵͳ��" << endl;
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
	cout << "ɾ���ɹ���" << endl;
	_getch();
}
#pragma once
