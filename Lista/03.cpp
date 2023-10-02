// Implemente uma função que divida uma lista encadeada em duas listas igualmente balanceadas, mesmo que a lista original tenha um número ímpar de elementos. Por exemplo, se a lista for 1 -> 2 -> 3 -> 4 -> 5, a função deve dividir em duas listas 1 -> 2 -> 3 e 4 -> 5.

#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> Lista_Encadeada;
    list <int> Lista_Encadeada2;

    for (int i = 0; i < 5; i++)
    {
        Lista_Encadeada.push_back(i);   
    }

    int tam = Lista_Encadeada.size();
    cout << tam << endl;

    while (tam > tam/2)
    {
        Lista_Encadeada2.push_front(Lista_Encadeada.back());
        Lista_Encadeada.pop_back();

        if (Lista_Encadeada2.size() == Lista_Encadeada.size() || Lista_Encadeada2.size() == Lista_Encadeada.size() + 1){
            break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "Lista 1: " << Lista_Encadeada.front() << endl;
        Lista_Encadeada.pop_front();

        cout << "Lista 2: " << Lista_Encadeada2.front() << endl;
        Lista_Encadeada2.pop_front();
    }
    return 0;
}