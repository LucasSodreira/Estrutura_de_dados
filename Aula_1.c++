#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> aula; // Pode ser Adicionado mais de 1 list no mesmo codigo
    int tam;
    list<int>::iterator it; // Ponteiro para a lista

    tam = 10;
    for (int i = 0; i < tam; i++){
        aula.push_back(i); // Adiciona no inicio da lista
    }

    it = aula.begin(); // Ponteiro para o inicio da lista
    advance(it, 5); // Avança 5 posições
    aula.insert(it, 0); // Adiciona o valor 0 na posição 5
    
    cout << "Tamanho da lista: " << aula.size() << endl; // Tamanho da lista

    // aula.reverse(); // Inverte a lista
    // aula.sort(); // Ordena a lista
    // aula.unique(); // Remove os elementos repetidos

    tam = aula.size(); // Tamanho da lista
    for (int i = 0; i < tam; i++){
        cout << aula.front() << "\n"; // Mostra o primeiro elemento da lista
        aula.pop_front(); // Remove o primeiro elemento da lista
    }
    
    cout << "Tamanho da lista: " << aula.size() << endl; // Tamanho da lista

    return 0;
}