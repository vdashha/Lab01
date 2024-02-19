 #include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct List {

    char n;
    List* next;

};

void addEnd(List** first, char n);
void Print(List* first);


int main(int argc, const char* argv[]) {
    setlocale(LC_ALL, "");
    List* first = NULL; //указатель на первый элемент первого списка
    List* second = NULL; //указатель на первый элемент второго списка

    bool flag = true;
    string n;
    int count = 0;

    while (flag) {

        cout << "Введите букву: ";
        getline(cin, n);

        if (n[0] == char(32)) //считает кол-во слов
            count++;

        if (n[0] != char(48)) {
            addEnd(&first, n[0]);
        } 
        else {

            flag = false;
            Print(first);

            //заполнение нового списка
            while (first->next)
            {
                if (first->n == char(32))
                    count--;
                if (count == 0)
                    break;

                addEnd(&second, first->n);
                first = first->next;

            }
            
            Print(second);
        }
    }

    return 0;
}

//вывод списка
void Print(List* first)
{
    cout << "\nВывод списка\n";
    if (first == NULL)
        cout << "\nСписок пуст.\n\n";
    else
    {
        cout << "\nСписок:\n";
        while (first != NULL)
        {
            cout << "Буква " << first->n << "      Адрес: " << first->next << endl;
            first = first->next;
        }
    }

}

//заполнение списка
void addEnd(List** first, char n) 
{
    if (*first == NULL)//проверка на первый элемент
    {
        List* tmp = new List;
        tmp->n = n;
        tmp->next = *first;
        *first = tmp;

    }
    else //следующие элементы 
    {
        List* p, *tmp;
        tmp = new List;
        p = *first;
        while (p->next)
        {
            p = p->next;
        }
        p->next = tmp;
        tmp->n = n;
        tmp->next = NULL;
    }
}
