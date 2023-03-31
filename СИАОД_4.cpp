#include <iostream>
#include <windows.h>
#include <vector>
#include <iomanip>
#include "student_info.h"
using namespace std;


ostream& operator<<(std::ostream& output, const Plan& plan)
{
	output << "| " << std::setfill(' ') << std::setw(16) << plan.d_code << " | ";
	output << std::setfill(' ') << std::setw(20) << plan.d_name << " | ";
	output << std::setfill(' ') << std::setw(12) << plan.p_code << " | ";
	output << std::setfill(' ') << std::setw(20) << plan.profile << " | ";
	output << std::setfill(' ') << std::setw(22) << plan.syllabus << " |";
	return output;
}

void read_info(Plan& plan)
{
	cout << "Введите шифр направления студента\n";
	cin >> plan.d_code;
	cout << "Введите название направления студента\n";
	getchar();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(plan.d_name, 50);
	cout << "Введите шифр профиля студента\n";
	// getchar();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(plan.p_code, 30);
	cout << "Введите название профиля студента\n";
	// getchar();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(plan.profile, 50);
	cout << "Введите год начала действия УП\n";
	cin >> plan.syllabus;
}

void show_table(University& uni)
{
	cout << "| Шифр направления | "
		<< setfill(' ') << setw(17) << "Название направления"
		<< " | " << setfill(' ') << setw(11) << "Шифр профиля" << " | " << setfill(' ') << setw(20) << "Название профиля"
		<< setfill(' ') << setw(14) << " | Год начала действия УП |\n";

	for (int i = 0; i < uni.size; ++i)
	{
		cout << uni.data_array[i] << '\n';
	}
}

int poisk(University& uni, Plan& new_p)
{
	for (int i = 0; i < uni.size; i++)
	{
		if (uni.data_array[i].d_code == new_p.d_code)
		{
			return i;
		}
	}
	return uni.size;
}

void z_1(University& uni, Plan plan)
{
	uni.size += 1;
	uni.data_array = (Plan*)realloc(uni.data_array, uni.size * sizeof(Plan));
	if (!(uni.size - 1))
	{
		uni.data_array[0] = plan;
	}
	else
	{
		int ind = poisk(uni, plan);
		if (ind != uni.size)
		{
			for (size_t i = uni.size - 1; i > ind; --i)
			{
				uni.data_array[i] = uni.data_array[i - 1];
			}
			uni.data_array[ind] = plan;
		}
		else
		{
			uni.data_array[uni.size - 1] = plan;
		}
	}
}

void z_2(University& uni, char(&d_name)[50])
{

	cout << "| " << setfill(' ') << setw(24) << "Название профиля"
		<< " | Год начала действия УП |\n";
	for (int i = 0; i < uni.size; i++)
	{
		if (!(strcmp(uni.data_array[i].d_name, d_name)))
		{
			cout << "| " << std::setfill(' ') << std::setw(24) << uni.data_array[i].profile << " | " << std::setfill(' ') << std::setw(22) << uni.data_array[i].syllabus << " |\n";
		}
	}
}

int findInd(const University& uni, const int& now)
{
	for (int i = 0; i < uni.size; i++)
	{
		if (now - uni.data_array[i].syllabus > 4)
		{
			return i;
		}
	}
	return -1;
}

void z_3(University& uni, const int& now)
{
	auto ind = findInd(uni, now);
	while (ind != -1)
	{
		for (int i = ind; i < uni.size; i++)
		{
			uni.data_array[i] = uni.data_array[i + 1];
		}
		uni.size--;
		uni.data_array = (Plan*)realloc(uni.data_array, uni.size * sizeof(Plan));
		ind = findInd(uni, now);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Лабораторная работа №4 \"Структуризация многоэлементных структур средствами struct\". Кузюхин Артемий \n";

	University uni;
	uni.size = 0;
	uni.data_array = new Plan[uni.size];

	while (1)
	{
		// Выбор задания
		int c;
		cout << "Выберите задание:\n1 - Вставить запись в таблицу планов в начало подсписка, с одним и тем же шифром направления\n"
			<< "2 - Вывести названия профилей и год начала действия учебного плана заданного направления\n"
			<< "3 - Удалить планы срок действия которых истек при прошествии 4-х лет\n";
		cin >> c;

		if (c == 0)
		{
			break;
		}
		else if (c == 1)
		{

			Plan plan;
			cin.ignore(cin.rdbuf()->in_avail());
			read_info(plan);
			z_1(uni, plan);
			show_table(uni);
		}
		else if (c == 2)
		{
			char _d_name[50];
			cout << "Введите направление\n";
			getchar();
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(_d_name, 50);
			z_2(uni, _d_name);
		}
		else if (c == 3)
		{
			int year;
			cout << "Введите пользовательский год на настоящий момент\n";
			cin >> year;
			z_3(uni, year);
			show_table(uni);
		}
		else
		{
			cout << "Ошибка. Убедитесь в правильности подаваемого значение и повторите ввод\n";
		}
	}
}