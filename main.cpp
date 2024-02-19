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
    List* first = NULL; //pointer to the first element of the first list
    List* second = NULL; //pointer to the first element of the second list

    bool flag = true;
    string n;
    int count = 0;

    while (flag) {

        cout << "Enter a letter: ";
        getline(cin, n);

        if (n[0] == char(32)) //counts the number of words
            count++;

        if (n[0] != char(48)) {
            addEnd(&first, n[0]);
        } 
        else {

            flag = false;
            Print(first);

            //populating a new list
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

//list output
void Print(List* first)
{
    cout << "\nList output\n";
    if (first == NULL)
        cout << "\nThe list is empty.\n\n";
    else
    {
        cout << "\nList:\n";
        while (first != NULL)
        {
            cout << "Letter " << first->n << "      Address:" << first->next << endl;
            first = first->next;
        }
    }

}

//filling the list
void addEnd(List** first, char n) 
{
    if (*first == NULL)
    {
        List* tmp = new List;
        tmp->n = n;
        tmp->next = *first;
        *first = tmp;

    }
    else 
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
