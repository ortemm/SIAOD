#include <iostream>
#include <vector>
#include <string>
using namespace std;


int razmer; // Глобальная переменная (размер массива)


// Ввод массивов 
void fill_hands(int* array1, int n) {
    for (int i = 0; i < n; i++) {
        cin >> array1[i];
    }
}


void fill_hands(vector <int>& vec, int n) {
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
}


void fill_random(int* array1, int n) {
    for (int i = 0; i < n; i++) {
        array1[i] = rand() % 1200;
    }
}


void fill_random(vector <int>& vec, int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 1200;
    }
}
// Ввод массивов

// 

// Вывод массивов
void output_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << "\n";
}


void output_array(vector <int>& vec) {
    for (int v : vec) {
        cout << v << ' ';
    }
    cout << "\n";
}
// Вывод массивов


// Поиск максимального значения в массиве (Задание 1)
int z_1(int* array1, int n) {
    int max = array1[0];
    for (int i = 1; i < n; i++) {
        if (array1[i] > max)
            max = array1[i];
    }
    return max;
}

int z_1(vector <int>& vec, int n) {
    int max = vec[0];
    for (int i = 1; i < n; i++) {
        if (vec[i] > max)
            max = vec[i];
    }
    return max;
}


// Поиск элементов, у которых первая и последняя цифра равны (для 2 задания)

int poisk(int* array, int n) {
    for (int i = 0; i < n; i++) {
        string str = to_string(array[i]);
        if (str[0] == str[size(str) - 1]) {
            return i;
        }
    }
    return -1;
}

int poisk(vector <int>& vec, int n) {
    for (int i = 0; i < n; i++) {
        string str = to_string(vec[i]);
        if (str[0] == str[size(str) - 1]) {
            return i;
        }
    }
    return -1;
}

// Вставка (Задание 2)
void z_2(int* array, int n) {
    int mAx = z_1(array, n);
    int x = poisk(array, n);
    if (x >= 0) {
        razmer++;
        for (int i = n; i > x; i--) {
            array[i] = array[i - 1];
        }
    }
    else {
        cout << "Такого значения в массиве нет\n";
        return;
    }
    // вставленный элемент
    array[x + 1] = mAx;
}

void z_2(vector <int>& vec, int n) {
    int mAx = z_1(vec, n);
    const int x = poisk(vec, n);
    if (x >= 0) {
        razmer++;
        for (int i = n - 1; i > x; i--) {
            vec[i + 1] = vec[i];
        }
    }
    else {
        cout << "Такого значения в массиве нет\n";
        return;
    }
    // вставленный элемент
    vec[x + 1] = mAx;
}
// Вставка (Задание 2)


// Удаление (задание 3)
void z_3(int* arr, int n) {
    long long fib[4] = { 112, 1123, 11235, 112358 };
    int mem;
    int countere;
    for (int i = 0; i < n; i++) {
        mem = arr[i];
        countere = 1;
        while (mem > 99) {
            mem /= 10;
            countere += 1;
        }
        if (arr[i] == fib[countere - 2])
        {
            i--;
            razmer--;
            for (int j = i + 1; j < n - 1; j++) {
                arr[j] = arr[j + 1];
                arr[j + 1] = 0;
            }
        }
    }
}

void z_3(vector<int>& vec, int n) {
    long long fib[4] = { 112, 1123, 11235, 112358 };
    int mem;
    int countere;
    for (int i = 0; i < n; i++) {
        mem = vec[i];
        countere = 1;
        while (mem > 99) {
            mem /= 10;
            countere += 1;
        }
        if (vec[i] == fib[countere - 2])
        {
            razmer--;
            i--;
            for (int j = i + 1; j < n - 1; j++) {
                vec[j] = vec[j + 1];
                vec[j + 1] = 0;
            }
        }
    }
}
// Удаление (Задание 3)


int main()
{
    srand(time(nullptr));
    setlocale(LC_ALL, "rus");
    cout << "Лабораторная работа №1 \"Простые алгоритмы сортировки массивов\". Кузюхин Артемий \n";

    int v1, v2, v3, n; // v1 - способ ввода, v2 - какой массив, v3 - какое задание

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

    // Какой массив
    cout << "Какой массив вы хотите использовать:\n1 - статический\n2 - динамический\n3 - vector\n";

    while (1)
    {
        cin >> v2;

        // Проверка 
        if (v2 != 1 && v2 != 2 && v2 != 3) {
            cout << "Ошибка. Убедитесь в правильности подаваемого значение и повторите ввод\n";
            continue;
        }
        break;
    }

    // Размер массива
    cout << "Сколько элементов должен содержать массив? (не более 100)\n";
    while (1)
    {
        cin >> n;

        // Проверка 
        if (v2 != 1 && v2 != 2 && v2 != 3) {
            cout << "Ошибка. Убедитесь в правильности подаваемого значение и повторите ввод\n";
            continue;
        }
        razmer = n;
        break;
    }

    // Инициализация массивов
    int array[100];
    int* array1 = (int*)malloc(n * sizeof(int));
    vector <int> vec(n);

    if (v1 == 1) {
        if (v2 == 1)
        {
            cout << "Введите " << razmer << " целых чисел\n";
            fill_hands(array, razmer);
            cout << "Массив:\n";
            output_array(array, razmer);
            bool zz2 = 1, zz3 = 1;
            while (1) {
                cout << "Введите номер задания:\n1 - Найти максимальный элемент\n"
                    << "2 - Вставить максимальный элемент после \"зеркального\" элемента\n"
                    << "3 - Удалить элементы, числа которых образуют ряд Фибоначчи(1-я и 2-я цифра единицы)\n";
                cin >> v3;
                if (v3 < 1 || v3 > 3)
                {
                    cout << "Ошибка. Введите номер задания заново\n";
                }
                else
                {
                    if (v3 == 1)
                    {
                        cout << "Результат: " << z_1(array, razmer) << "\n";
                    }
                    else if (v3 == 2)
                    {

                        z_2(array, razmer);
                        output_array(array, razmer);
                        zz2 = 0;
                    }
                    else
                    {

                        z_3(array, razmer);
                        cout << "Результат: \n";
                        output_array(array, razmer);
                        zz3 = 0;
                    }
                }
            }
        }
        else if (v2 == 2)
        {
            cout << "Введите " << razmer << " целых чисел\n";
            fill_hands(array1, razmer);
            cout << "Массив:\n";
            output_array(array1, razmer);
            bool zz2 = 1, zz3 = 1;
            while (1) {
                cout << "Введите номер задания:\n1 - Найти максимальный элемент\n"
                    << "2 - Вставить максимальный элемент после \"зеркального\" элемента\n"
                    << "3 - Удалить элементы, числа которых образуют ряд Фибоначчи(1-я и 2-я цифра единицы)\n";
                cin >> v3;
                if (v3 < 1 || v3 > 3)
                {
                    cout << "Ошибка. Введите номер задания заново\n";
                }
                else
                {
                    if (v3 == 1)
                    {
                        cout << "Результат: " << z_1(array1, razmer) << "\n";
                    }

                    else if (v3 == 2)
                    {

                        array1 = (int*)realloc(array1, (razmer + 1) * sizeof(int));
                        z_2(array1, razmer);
                        output_array(array1, razmer);
                        zz2 = 0;
                    }
                    else
                    {
                        z_3(array1, razmer);
                        array1 = (int*)realloc(array1, razmer * sizeof(int));
                        cout << "Результат: \n";
                        output_array(array1, razmer);
                        zz3 = 0;
                    }
                }
            }
        }
        else
        {
            cout << "Введите " << razmer << " целых чисел\n";
            fill_hands(vec, razmer);
            cout << "Массив:\n";
            output_array(vec);
            bool zz2 = 1, zz3 = 1;
            while (1) {
                cout << "Введите номер задания:\n1 - Найти максимальный элемент\n"
                    << "2 - Вставить максимальный элемент после \"зеркального\" элемента\n"
                    << "3 - Удалить элементы, числа которых образуют ряд Фибоначчи(1-я и 2-я цифра единицы)\n";
                cin >> v3;
                if (v3 < 1 || v3 > 3)
                {
                    cout << "Ошибка. Введите номер задания заново\n";
                }
                else
                {
                    if (v3 == 1)
                    {
                        cout << "Результат: " << z_1(vec, razmer) << "\n";
                    }

                    else if (v3 == 2)
                    {
                        vec.resize(razmer + 1);
                        z_2(vec, razmer);
                        output_array(vec);
                        zz2 = 0;
                    }

                    else
                    {
                        z_3(vec, razmer);
                        vec.resize(razmer);
                        cout << "Результат: \n";
                        output_array(vec);
                        zz3 = 0;
                    }
                }
            }
        }
    }
    else {
        if (v2 == 1)
        {
            cout << "Введите " << razmer << " целых чисел\n";
            fill_random(array, razmer);
            cout << "Массив:\n";
            output_array(array, razmer);
            bool zz2 = 1, zz3 = 1;
            while (1)
            {
                cout << "Введите номер задания:\n1 - Найти максимальный элемент\n"
                    << "2 - Вставить максимальный элемент после \"зеркального\" элемента\n"
                    << "3 - Удалить элементы, числа которых образуют ряд Фибоначчи(1-я и 2-я цифра единицы)\n";
                cin >> v3;
                if (v3 < 1 || v3 > 3)
                {
                    cout << "Ошибка. Введите номер задания заново\n";
                }
                else
                {
                    if (v3 == 1)
                    {
                        cout << "Результат:\n";
                        z_1(array, razmer);
                    }
                    else if (v3 == 2)
                    {
                        z_2(array, razmer);
                        output_array(array, razmer);
                    }
                    else
                    {
                        z_3(array, razmer);
                        cout << "Результат: \n";
                        output_array(array, razmer);
                        zz3 = 0;
                    }
                }
            }
        }

        else if (v2 == 2)
        {
            cout << "Введите " << razmer << " целых чисел\n";
            fill_random(array1, razmer);
            cout << "Массив:\n";
            output_array(array1, razmer);
            bool zz2 = 1, zz3 = 1;
            while (1)
            {
                cout << "Введите номер задания:\n1 - Найти максимальный элемент\n"
                    << "2 - Вставить максимальный элемент после \"зеркального\" элемента\n"
                    << "3 - Удалить элементы, числа которых образуют ряд Фибоначчи(1-я и 2-я цифра единицы)\n";
                cin >> v3;
                if (v3 < 1 || v3 > 3)
                {
                    cout << "Ошибка. Введите номер задания заново\n";
                }
                else
                {
                    if (v3 == 1)
                    {
                        cout << "Результат:\n" << z_1(array1, razmer) << "\n";
                    }
                    else if (v3 == 2)
                    {
                        array1 = (int*)realloc(array1, (razmer + 1) * sizeof(int));
                        z_2(array1, razmer);
                        output_array(array1, razmer);
                    }
                    else
                    {
                        z_3(array1, razmer);
                        array1 = (int*)realloc(array1, razmer * sizeof(int));
                        cout << "Результат: \n";
                        output_array(array1, razmer);
                        zz3 = 0;
                    }
                }
            }
        }

        else
        {
            cout << "Введите " << razmer << " целых чисел\n";
            fill_random(vec, razmer);
            cout << "Массив:\n";
            output_array(vec);
            bool zz2 = 1, zz3 = 1;
            while (1)
            {
                cout << "Введите номер задания:\n1 - Найти максимальный элемент\n"
                    << "2 - Вставить максимальный элемент после \"зеркального\" элемента\n"
                    << "3 - Удалить элементы, числа которых образуют ряд Фибоначчи(1-я и 2-я цифра единицы)\n";
                cin >> v3;
                if (v3 < 1 || v3 > 3)
                {
                    cout << "Ошибка. Введите номер задания заново\n";
                }
                else
                {
                    if (v3 == 1)
                    {
                        cout << "Результат:\n" << z_1(vec, razmer) << "\n";
                    }
                    else if (v3 == 2)
                    {
                        vec.resize(razmer + 1);
                        z_2(vec, razmer);
                        output_array(vec);
                    }
                    else
                    {
                        z_3(vec, razmer);
                        vec.resize(razmer);
                        cout << "Результат: \n";
                        output_array(vec);
                        zz3 = 0;
                    }
                }
            }
        }
    }
}