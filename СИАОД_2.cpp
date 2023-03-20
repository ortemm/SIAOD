#include <iostream>
#include <vector>
using namespace std;

const int rows = 90, cols = 100; // Глобальные переменные (размер массива m*n)

// ввод массива
template <typename F>
void fill_hands(F arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
}


template <typename F1>
void fill_random(F1 arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 1200;
        }
    }
}
// ввод массива


// вывод массива
template <typename Out>
void output_array(Out arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}
// вывод массива


// поиск минимального элемента в массиве
template <typename P>
int poisk(P& arr, int m, int n)
{
    int min = arr[0][0];
    int x1, x2;
    bool c = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
                x1 = i;
                x2 = j;
                c = 1;
            }
        }
    }
    cout << "Минимальный элемент: " << min << "\n";

    if (c)
    {
        int** Darr = new int* [m];
        for (int i = 0; i < m; i++)
        {
            Darr[i] = new int[n];
        }
        for (int i = 0; i < n; i++)
        {
            Darr[0][i] = arr[0][i];
            arr[0][i] = arr[x1][i];
            arr[x1][i] = Darr[0][i];
        }
        for (int j = 0; j < m; j++)
        {
            Darr[j][0] = arr[j][0];
            arr[j][0] = arr[j][x2];
            arr[j][x2] = Darr[j][0];
        }
        delete[] Darr;
        return 1;
    }
}


int main()
{
    srand(time(nullptr));
    setlocale(LC_ALL, "rus");
    cout << "Лабораторная работа №2 \"Двумерный массив\". Кузюхин Артемий \n";

    int v1, v2, v3, m, n;

    // Способ ввода массива
    cout << "Выберите способ ввода массива:\n1 - вручную\n2 - генератор случайных чисел\n";
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

    // Какая структура данных
    cout << "Какой массив вы хотите использовать:\n1 - статический\n2 - динамический\n";
    while (1)
    {
        cin >> v2;

        // Проверка 
        if (v2 != 1 && v2 != 2) {
            cout << "Ошибка. Убедитесь в правильности подаваемого значение и повторите ввод\n";
            continue;
        }
        break;
    }

    cout << "Введите друг за другом количество строк и столбцов (не более 90 и 100 соответственно)\n";
    while (1)
    {
        cin >> m;

        // Проверка 
        if (m < 0 && m > 90) {
            cout << "Ошибка. Убедитесь в правильности подаваемого значение и повторите ввод\n";
            continue;
        }

        cin >> n;

        if (n < 0 && n > 90) {
            cout << "Ошибка. Убедитесь в правильности подаваемого значение и повторите ввод\n";
            continue;
        }
        break;
    }


    // инициализация массивов
    int array[rows][cols];
    int** array1 = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        array1[i] = new int[cols];
    }


    switch (v1)
    {
    case 1:
        if (v2 == 1)
        {
            cout << "Введите " << m * n << " целых чисел\n";
            fill_hands(array, m, n);
            cout << "Массив:\n";
            output_array(array, m, n);
            while (1)
            {
                cout << "Введите номер задания\n1 - переместить минимальный элемент в левый верхний угол\n" <<
                    "2 - пока что не понятное\n";
                cin >> v3;
                if (v3 < 1 || v3 > 2)
                {
                    cout << "Ошибка. Введите номер задания заново\n";
                }
                else
                {
                    if (v3 == 1)
                    {
                        poisk(array, m, n);
                        output_array(array, m, n);
                    }
                }
            }
        }
        break;
    case 2:
        cout << "Массив из " << m * n << " целых чисел:\n";
        fill_random(array1, m, n);
        cout << "Массив:\n";
        output_array(array1, m, n);
        while (1)
        {
            cout << "Введите номер задания\n1 - переместить минимальный элемент в левый верхний угол\n" <<
                "2 - пока что не понятное\n";
            cin >> v3;
            if (v3 < 1 || v3 > 2)
            {
                cout << "Ошибка. Введите номер задания заново\n";
            }
            else
            {
                if (v3 == 1)
                {
                    poisk(array1, m, n);
                    output_array(array1, m, n);
                }
            }
        }
        break;
    }
}
