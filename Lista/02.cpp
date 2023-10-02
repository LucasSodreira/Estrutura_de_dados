#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> Lista_Encadeada;
    list<int> Lista_Encadeada2;

    for (int i = 0; i < 6; i++)
    {
        Lista_Encadeada.push_back(i);   
    }
    
    Lista_Encadeada.reverse();

    int tam = Lista_Encadeada.size();

    for (int i = 0; i < tam; i++)
    {
        cout << Lista_Encadeada.front() << endl;
        Lista_Encadeada.pop_front();
    }

    return 0;
}