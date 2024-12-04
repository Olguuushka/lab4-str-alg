#include<iostream>
#include<string>
#include"Ticket.h"
#include<fstream>
#include<Windows.h>
#include"List.h"

//���������� �������� ����
Date ending(const Date& date)
{
	Date end;
	if (date.get_day() > 28)
	{
		end.set_day(date.get_day() + 2 - 30);
		if (date.get_month() == 12)
		{
			end.set_month(1);
			end.set_year(date.get_year() + 1);
		}
		else
		{
			end.set_month(date.get_month() + 1);
			end.set_year(date.get_year());
		}
	}
	else
	{
		end.set_day(date.get_day() + 2);
		end.set_month(date.get_month());
		end.set_year(date.get_year());
	}
	return end;
}

//����� ����������, ���������� � �������� ����� ����������� � ��������� 3 ��� ������������ �������� ����
List task(const List& list,std::string dest,const Date&date)
{
	List new_list;
	ptrNODE ptr = list.get_head();
	Date end = ending(date);
	bool flag = true;
	while  (ptr&&flag)
	{
		if (ptr->info.get_dest() == dest)
		{
			if (ptr->info.get_date() >= date && ptr->info.get_date() <= end)
			{
				new_list.add_to_tail(ptr->info);
			}
		}
		else
		{
			if (ptr->info.get_dest() > dest)
				flag = false;
		}
			
		ptr = ptr->next;
	}
	return new_list;
}

int main()
{
	SetConsoleOutputCP(1251);
	////////////////////////////////////////////////////////////////////////

	std::ifstream file("data1.txt");//���������������� �����������
	List list(file);
	list.print();
	std::cout << "------------------------------------------------\n";

	////////////////////////////////////////////////////////////////////////

	List list2 = list;//����������� �����������
	list2.print();
	std::cout << "-------------------------------------------------\n";

	////////////////////////////////////////////////////////////////////////

	List list3(file);
	list3 = list;//�������� �����������
	list3.print();
	std::cout << "-------------------------------------------------\n";

	////////////////////////////////////////////////////////////////////////

	Date date(13, 8, 2026);
	std::string dest = "�����";
	std::cout << "�������� �����: " << dest<<'\n';
	std::cout << "�������� ����:\n" << date << '\n';
	List list4 = std::move(task(list, dest, date));//����������� �����������
	if (list4.get_head() == nullptr)
		std::cout << "��� ����������, ���������� � �������� ����� � ��������� ��� ���\n";
	else
		list4.print();
	std::cout << "-------------------------------------------------\n";

	////////////////////////////////////////////////////////////////////////

	std::cout << "�������� �����: " << dest << '\n';
	std::cout << "�������� ����:\n" << date << '\n';
	list3 =task(list, dest, date);// �������� ����������� 
	if (list3.get_head() == nullptr)
		std::cout << "��� ����������, ���������� � �������� ����� � ��������� ��� ���\n";
	else
		list3.print();

	////////////////////////////////////////////////////////////////////////

	std::cin.ignore();
	return 0;
}