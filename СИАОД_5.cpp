#include <iostream>
#include <vector>
using namespace std;


struct List
{
    int data;
    List* pNext;
};


void print(List* l)
{
    auto p = l;
    std::cout << '[';

    while (p)
    {
        std::cout << p->data;
        if (p->pNext)
            std::cout << ", ";
        p = p->pNext;
    }
    std::cout << "]\n";
}


List* z_1(List* l, int key, int choose)
{
    auto temp = l;
    List* v = new List;

    v->data = key;
    v->pNext = nullptr;

    if (choose == 1)
    {
        v->pNext = temp;
        temp = v;
        return temp;

    }
    else
    {
        if (temp)
        {
            auto it = temp;
            while (it->pNext)
            {
                it = it->pNext;
            }
            it->pNext = v;
        }
        else
        {
            temp = v;
        }
        return temp;
    }
}


List* z_2(List* l, int key)
{
    if (l)
    {
        auto temp = l;
        List* tr = nullptr;

        if (temp->data == key)
        {
            tr = temp;
            temp = temp->pNext;
            tr->pNext = nullptr;
        }
        else
        {
            auto it = temp;
            while (1)
            {
                if (it->pNext)
                {
                    if (it->pNext->data == key)
                    {
                        break;
                    }
                    it = it->pNext;
                }
                else
                {
                    break;
                }
            }
            if (it->pNext && it->pNext->data == key)
            {
                tr = it->pNext;
                it->pNext = tr->pNext;
                tr->pNext = nullptr;
            }
        }
        delete tr;
        return temp;
    }
    else
    {
        return nullptr;
    }
}


List* z_3(List* l, int data)
{
    auto el = l;
    while (el)
    {
        if (el->data == data)
        {
            return el;
        }
        el = el->pNext;
    }
    return el;
}


List* erase(List* l) {
    auto tmp = l;
    List* tr = nullptr;
    while (tmp)
    {
        tr = tmp;
        tr->pNext = nullptr;
        tmp = tmp->pNext;
        delete tr;
    }
    return tmp;
}


int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Лабораторная работа №5 \"Однонаправленный список\". Кузюхин Артемий \n";

    size_t numOfLists = 0;

    cout << "Введите количество списков: ";
    cin >> numOfLists;

    vector<List*> vec(numOfLists, nullptr);

    while (1)
    {
        int c;
        cout << "Введите номер задания:\n0 - выход из программы\n1 - вставка\n2 - удаление\n3 - поиск\n";
        cin >> c;

        if (c == 0)
        {
            break;
        }
        else if (c == 1)
        {
            int key, i, ch;
            cout << "Введите значение вставляемого элемента: ";
            cin >> key;
            i = key % numOfLists;
            cout << "Индекс списка, в который произведется вставка: " << i << endl;
            cout << "Куда хотите вставить элемент:\n1 - начало спика\n2 - конец списка\n";
            cin >> ch;
            vec[i] = z_1(vec[i], key, ch);
            cout << "Результат: \n";
            for (const auto list : vec)
            {
                print(list);
            }

        }
        else if (c == 2)
        {
            int num = 1, znach;
            if (vec.size() != 1)
            {
                cout << "Введите номер списка: ";
                cin >> num;
                while (1)
                {
                    if (num > numOfLists)
                    {
                        cout << "Введите номер списка заново: ";
                        cin >> num;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            cout << "Введите значение узла, подлежащего удалению: ";
            cin >> znach;

            vec[num - 1] = z_2(vec[num - 1], znach);
            cout << "Результат: \n";
            for (const auto list : vec)
            {
                print(list);
            }
        }
        else
        {
            int num = 1, key;
            if (vec.size() != 1)
            {
                cout << "Введите номер списка с искомым ключом: ";
                cin >> num;
                while (1)
                {
                    if (num > numOfLists)
                    {
                        cout << "Введите номер списка заново: ";
                        cin >> num;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            cout << "Введите искомое значение ключа: ";
            cin >> key;

            auto res = z_3(vec[num - 1], key);
            if (res)
            {
                for (const auto list : vec)
                {
                    print(list);
                }
                cout << "Адрес узла: " << res << "\nЗначение узла: " << res->data << endl;
            }
            else
            {
                cout << "Узла с таким значением нет в списке\n";
            }
            res = nullptr;
        }
    }


    // удаление списков из памяти
    for (auto& list : vec)
    {
        list = erase(list);
    }
}
