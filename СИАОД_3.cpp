#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void fill_string(char*& str1)
{
    cout << "Введите слова через запятую или пробел: \n";
    int i = 0;
    char x;
    while ((x = getchar()) != '\n')
    {
        i++;
        str1 = (char*)realloc(str1, (i + 1) * sizeof(char));
        str1[i - 1] = x;
    }
    str1[i] = '\0';
}


void fill_string(string& str)
{
    cout << "Введите слова через запятую или пробел: \n";
    getline(cin, str);
}


void print_string(char*& str1)
{
    cout << str1 << "\n\n";
}


void print_string(string& str)
{
    cout << str << "\n\n";
}


void erase(char*& str1, int pos, int amount) {
    int l = strlen(str1);
    for (int i = pos; i < l; i++) {
        str1[i] = str1[i + amount];
    }
    str1[l - amount] = '\0';
    str1 = (char*)realloc(str1, (l - amount + 1) * sizeof(char));
}


void insert(char*& str1, int pos, char c) {
    int l = strlen(str1);
    str1 = (char*)realloc(str1, (l + 2) * sizeof(char));
    for (int i = l; i >= pos; i--)
    {
        str1[i + 1] = str1[i];
        break;
    }
    str1[pos] = c;
    str1[l + 1] = '\0';
}


void z(char*& str1, int nach, int cnt, int num)
{
    erase(str1, nach, cnt);
    int a = num;
    char num_now = a + '0';
    str1[nach] = num_now;
    insert(str1, nach, num_now);
    erase(str1, strlen(str1) - 1, 1);
    cout << "Результат: ";
    cout << str1 << endl;
}

void z(string& str, int nach, int cnt, int num)
{
    str = str.erase(nach, cnt);
    int a = num;
    char num_now = a + '0';
    str[nach] = num_now;
    str = str.erase(size(str) - 1);
    cout << "Результат: ";
    cout << str << endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Лабораторная работа №3 \"Структура данных - строка\". Кузюхин Артемий \n";

    char* str1 = (char*)malloc(1 * sizeof(char));
    string str;

    int cnt = 0; // количество букв в слове
    int max = 0; // временная переменная для поиска максимума
    int num_max = 0; // номер самого длинного палиндрома среди палиндромов
    int g_num = 0; // запоминает номер
    int g_cnt = 0; // запоминает количество букв в слове
    int g_jh = 0; // запоминает первую позицию в строке самого длинного палиндрома

    // Какая структура данных
    int v1;
    cout << "Что вы хотите использовать? :\n1 - класс string\n2 - нуль терминальная строка\n";
    while (1)
    {
        cin >> v1;

        // Проверка 
        if (v1 != 1 && v1 != 2) {
            cout << "Ошибка. Убедитесь в правильности подаваемого значение и повторите ввод\n";
            continue;
        }
        break;
    }

    if (v1 == 1)
    {
        getchar();
        fill_string(str);
        cout << "Ваше предложение: \n";
        print_string(str);
        str.push_back(',');
        for (int i = 0; i < size(str); i++)
        {
            cnt++;

            if (str[i] == ',' || str[i] == ' ')
            {
                cnt = 0;
            }

            if (str[i + 1] == ' ' || str[i + 1] == ',')
            {
                int jh = i - cnt + 1;
                for (int j = jh; j < jh + cnt / 2; j++)
                {
                    if (str[j] == str[(jh + cnt) - 1])
                    {
                        num_max += 1;
                        if (cnt > max)
                        {
                            max = cnt;
                            g_jh = jh + 1;
                            g_cnt = cnt;
                            g_num = num_max;
                        }
                    }
                }
            }
        }
        cout << "Порядковый номер среди палиндромов самого длинного палиндрома в строке: " << g_num << endl
            << "Номер первой буквы искомого слова: " << g_jh << endl
            << "Количество букв в слове: " << g_cnt << endl << endl;
        z(str, g_jh - 1, g_cnt - 1, g_num);
    }
    else
    {
        getchar();
        fill_string(str1);
        cout << "Ваше предложение: \n";
        print_string(str1);
        insert(str1, strlen(str1), ',');
        for (int i = 0; i < strlen(str1); i++)
        {
            cnt++;

            if (str1[i] == ',' || str1[i] == ' ')
            {
                cnt = 0;
            }

            if (str1[i + 1] == ' ' || str1[i + 1] == ',')
            {
                int jh = i - cnt + 1;
                for (int j = jh; j < jh + cnt / 2; j++)
                {
                    if (str1[j] == str1[(jh + cnt) - 1])
                    {
                        num_max += 1;
                        if (cnt > max)
                        {
                            max = cnt;
                            g_jh = jh + 1;
                            g_cnt = cnt;
                            g_num = num_max;
                        }
                    }
                }
            }
        }
        cout << "Порядковый номер среди палиндромов самого длинного палиндрома в строке: " << g_num << endl
            << "Номер первой буквы искомого слова: " << g_jh << endl
            << "Количество букв в слове: " << g_cnt << endl << endl;
        z(str1, g_jh - 1, g_cnt - 1, g_num);
    }
}
