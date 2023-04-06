#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int rows = 90, cols = 100; // Глобальные переменные (размер массива m*n)

// ввод массива
template <typename F>
void fill_array(F arr, int n, int m, int mode)
{
    if (mode == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    else if (mode == 2)
    {
        srand(time(nullptr));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = rand() % 500;
            }
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


// первое задание
template <typename P>
void z_1(P& arr, int m, int n)
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
    }
}


struct Point
{
    double x, y;
};


struct Circle
{
    Point center;
    double rad;
};


struct  Points
{
    Point p1, p2;
};


template <typename F>
void fill_points(F& points, int points_num)
{
    for (int i = 0; i < points_num; i++)
    {
        Point p{};
        cout << "Введите координаты x и y через пробел, у точки: " << i + 1
            << endl;
        cin >> p.x >> p.y;
        points.push_back(p);
    }
}


template <typename F>
void fill_circles(F& circles, int circls_num)
{
    for (int i = 0; i < circls_num; i++)
    {
        Point p{};
        Circle c{};
        cout << "Введите координаты центра x и y через пробел, у окружности: " << i + 1 << endl;
        cin >> p.x >> p.y;
        c.center = p;
        cout << "Введите радиус окружности: " << i + 1 << endl;
        cin >> c.rad;
        circles.push_back(c);
    }
}


int intersections(const Points& pnt, const Circle& crcle)
{
    int intersections = 0;
    double d_x = pnt.p2.x - pnt.p1.x;
    double d_y = pnt.p2.y - pnt.p1.y;
    double a = d_x * d_x + d_y * d_y;
    double b = 2 * (d_x * (pnt.p1.x - crcle.center.x) + d_y * (pnt.p1.y - crcle.center.y));
    double c = crcle.center.x * crcle.center.x + crcle.center.y * crcle.center.y + 
        pnt.p1.x * pnt.p1.x + pnt.p1.y * pnt.p1.y - 2 *
        (crcle.center.x * pnt.p1.x + crcle.center.y * pnt.p1.y) - crcle.rad * crcle.rad;
    double discr = b * b - 4 * a * c;
    if (discr < 0)
    {
        return 0;
    }
    double x1 = (-b + sqrt(discr)) / (2 * a);
    double x2 = (-b - sqrt(discr)) / (2 * a);
    if (x1 >= 0 && x1 <= 1)
    {
        intersections++;
    }
    if (x2 >= 0 && x2 <= 1)
    {
        intersections++;
    }
    return intersections;
}

template <typename F, typename T>
void z_2(F pnts, T crcls)
{
    int max = -1;
    int max_i = 0, max_j = 0;
    for (int i = 0; i < pnts.size(); i++)
    {
        for (int j = i + 1; j < pnts.size(); j++)
        {
            if ((pnts[i].x != pnts[j].x) && (pnts[i].y != pnts[j].y))
            {
                int sum = 0;
                Points pt = { {pnts[i].x, pnts[i].y}, {pnts[j].x, pnts[j].y} };
                for (int k = 0; k < crcls.size(); k++)
                {
                    sum += intersections(pt, crcls[k]);
                }
                if (sum > max)
                {
                    max = sum;
                    max_i = i;
                    max_j = j;
                }
            }
        }
    }
    if (max == 0)
    {
        cout << "Пересечения не найдены";
        return;
    }
    cout << "Максимальное количество пересечений: " << max << "Между точками: (x: "
        << pnts[max_i].x << ", y: " << pnts[max_i].y << "), (x: " << pnts[max_j].x << ", y: "
        << pnts[max_j].y << ")";
}


int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Лабораторная работа №2 \"Двумерный массив\". Кузюхин Артемий \n";

    int v1, v2, v3, m, n;

   
    // инициализация массивов
    int array[rows][cols];
    int** array1 = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        array1[i] = new int[cols];
    }

    while (1)
    {
        cout << "Введите номер задания:\n0 - выход\n1 - переместить мин. элемент матрицы в ее левый верхний угол, путем перестановки\n"
            << "2 - найти две точки, прямая через которые пересекается с макс. кол-вом окружностей\n";
        cin >> v3;
        if (v3 == 0)
        {
            break;
        }
        if (v3 == 1)
        {
            // Способ ввода массива
            cout << "Выберите способ ввода массива:\n1 - вручную\n2 - генератор случайных чисел\n";
            while (1)
            {
                cin >> v1;

                // Проверка 
                if (v1 != 0 && v1 != 1 && v1 != 2) {
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
            switch (v1)
            {
            case 1:
                if (v2 == 1)
                {
                    cout << "Введите " << m * n << " целых чисел\n";
                    fill_array(array, m, n, v1);
                    cout << "Массив:\n";
                    output_array(array, m, n);

                    z_1(array, m, n);
                    output_array(array, m, n);
                }
                else
                {
                    cout << "Введите " << m * n << " целых чисел\n";
                    fill_array(array1, m, n, v1);
                    cout << "Массив:\n";
                    output_array(array1, m, n);
                    z_1(array1, m, n);
                    output_array(array1, m, n);
                }
                break;
            case 2:
                if (v2 == 1)
                {
                    cout << "Массив из " << m * n << " целых чисел:\n";
                    fill_array(array, m, n, v1);
                    cout << "Массив:\n";
                    output_array(array, m, n);
                    z_1(array, m, n);
                    output_array(array, m, n);
                }
                else
                {
                    cout << "Введите " << m * n << " целых чисел\n";
                    fill_array(array1, m, n, v1);
                    cout << "Массив:\n";
                    output_array(array1, m, n);
                    z_1(array1, m, n);
                    output_array(array1, m, n);
                }
                break;
            }
        }
        else if (v3 == 2)
        {
            vector<Point> points;
            vector<Circle> circles;
            int points_num, circles_num;

            cout << "Введите количество точек и количество окружностей, через пробел соответственно:\n";
            cin >> points_num >> circles_num;

            fill_points(points, points_num);
            fill_circles(circles, circles_num);
            z_2(points, circles);
        }
        else
        {
            cout << "Неверное значение, повторите ввод: ";
        }
    }
}
