#include <iostream>
using namespace std;

int size;

struct List
{
    int number;
    List* next;
};


void print_lst(List* inf)
{
    auto temp = inf;

    cout << "[";

    while (temp)
    {
        cout << temp->number;
        if (temp->next)
        {
            cout << ", ";
        }
        temp = temp->next;
    }
    cout << "]\n";
}


List* add_to_lst(List* inf, int num)
{
    auto temp = inf;
    List* v = new List;

    v->number = num;
    v->next = nullptr;

    if (temp)
    {
        auto it = temp;
        while (it->next)
        {
            it = it->next;
        }
        it->next = v;
    }
    else
    {
        temp = v;
    }
    return temp;
}


int getSum(List* inf)
{
    auto temp = inf;
    int res = 0;
    while (temp)
    {
        res += temp->number;
        temp = temp->next;
    }
    return res;
}


int z_1(List* inf, int n)
{
    auto temp = inf;
    int res = 1;

    for (int i = 0; i < n; i++)
    {
        res *= getSum(temp);
        temp = temp->next;
    }
    return res;
}


List* z_2(List* inf, int n)
{
    if (inf == nullptr) {
    return nullptr;
    }
    if (inf->number == 0) {
        List* temp = inf->next;
        delete inf;
        size--;
        return temp;
    }
    for (int i = 0; i < n; i++)
    {
        inf->next = z_2(inf->next, n);
    }
    return inf;
}


List* erase(List* inf) {
    auto temp = inf;
    List* v = nullptr;
    while (temp)
    {
        v = temp;
        v->next = nullptr;
        temp = temp->next;
        delete v;
    }
    return temp;
}


int main()
{
    setlocale(LC_ALL, "ru");

    int n, c;
    List* list = nullptr;

    cout << "Введите количество чисел: ";
    cin >> n;
    size = n;
    
    for (int i = 0; i < size; i++)
        {
            int new_num;
            cout << "Введите " << i + 1 << "-е число: ";
            cin >> new_num;
            list = add_to_lst(list, new_num);
        }
        print_lst(list);


    while (1)
    {
        cout << "Выберите задание:\n"
        << "0 - Выход из программы\n"
        << "1 - Вычислить значение выражения типа Xn(Xn+Xn-1)...(Xn+...+X1)\n"
        << "2 - Удалить из списка нули\n";
        cin >> c;

        if (c == 0)
        {
            break;
        }
        else if (c == 1)
        {
            cout << z_1(list, size) << endl;
        }
        else if (c == 2)
        {
            list = z_2(list, size);
            print_lst(list);
        }
    }

    // удаление списка из памяти
    list = erase(list);
}